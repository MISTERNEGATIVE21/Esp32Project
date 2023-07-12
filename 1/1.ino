#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"
#define dataPin D7 // Defines pin number to which the sensor is connected
DHT dht(D7, DHT22);
WiFiClient client;
HTTPClient http;

//const char* ssid = "HP 0263";
//const char* password = "a502<M22";
const char* ssid = "Motorola Edge 30";
const char* password = "hitksuman";
//const char* serverURL = "http://192.168.137.95:8000/esp32_data_view/";
const char* serverURL = "http://192.168.173.65:8000/esp32_data_view/";

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  dht.begin();
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Simulate sensor readings
  delay(1000);
  float random1 = dht.readTemperature(); // Gets the values of the temperature
  float random2 = dht.readHumidity();
  Serial.print("Temperature = ");
  Serial.print(random1);
  Serial.println(" °C ");
  Serial.print("Humidity = ");
  Serial.print(random2);
  Serial.print(" % ");
  
  String data1 = String(random1);
  String data2 = String(random2);
  // Create a JSON payload with the sensor data
//  String payload = "Random 1 =" + String(random1) + "& Random 2 =" + String(random2);
//
//  // Make a POST request to the Django server
//  //  HttpClient http;
//  http.begin(client, serverURL);
//  http.addHeader("Content-Type", "application/json");
//  int httpResponseCode = http.POST(payload);
//
//  // Check the response from the server
//  if (httpResponseCode == HTTP_CODE_OK) {
//    //String response = http.getString();
//    Serial.print("HTTP Response code: ");
//    Serial.println(httpResponseCode);
//  } else {
//    Serial.println("Error sending request. Error code: ");
//    Serial.println(httpResponseCode);
//  }
//  http.end();
//
//  delay(5000);  // Wait for 5 seconds before sending the next request
//}
  sendDataToServer(data1, data2);

  delay(5000); // Delay between each data transmission
}

void sendDataToServer(const String& data1, const String& data2) {
  HTTPClient http;

  // Specify the server and resource path
  String url = serverURL;

  // Create the POST request payload
  String payload = "data1=" + data1 + "&data2=" + data2;

  // Make POST request
  http.begin(client, serverURL);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(payload);

  // Check the HTTP response code
  if (httpCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println("Received response: " + response);
    // Handle the response as needed
  } else {
    Serial.println("Error: HTTP request failed with code " + String(httpCode));
  }

  http.end();
}
