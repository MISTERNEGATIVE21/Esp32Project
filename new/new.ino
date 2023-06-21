#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Normal wifi";
const char* password = "sayak123";
//const char* serverURL = "http://192.168.137.95:8000/esp32_data_view/";
const char* serverURL = "http://192.168.217.70:8000/esp32_data_view/";

void setup() {
  Serial.begin(115200);

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
  // Generate two random values
  int randomValue1 = random(0, 100);
  int randomValue2 = random(0, 100);

  // Convert the random values to strings
  String data1 = String(randomValue1);
  String data2 = String(randomValue2);

  // Send the data to the server
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
  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
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