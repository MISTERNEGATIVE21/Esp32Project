#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "HP 0263";
const char* password = "a502<M22";
//const char* serverURL = "http://192.168.137.95:8000/esp32_data_view/";
const char* serverURL = "http://127.0.0.1:8000/esp32_data_view/";

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
  // Simulate sensor readings
  int random1 = esp_random();
  int random2 = random(100);
  Serial.println(random1);
  Serial.println(random2);
  // Create a JSON payload with the sensor data
  String payload = "Random 1 =" + String(random1) + "& Random 2 =" + String(random2);

  // Make a POST request to the Django server
  HTTPClient http;
  http.begin(serverURL);
  http.addHeader("Content-Type", "numeric/plain");
  int httpResponseCode = http.POST(payload);

  // Check the response from the server
  if (httpResponseCode == HTTP_CODE_OK) {
    //String response = http.getString();
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error sending request. Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  delay(5000);  // Wait for 5 seconds before sending the next request
}
