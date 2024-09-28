#define BLYNK_TEMPLATE_ID "TMPL34cjFTKdL"  // Replace with your actual Template ID
#define BLYNK_TEMPLATE_NAME "EcoFrost fridge"  // Replace with your actual Device Name
#define BLYNK_AUTH_TOKEN "3f3Vz81lKXxBPKxwAWHJ1_rb2TIZ2E9O"          // Replace with your Auth Token

// Libraries required
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// DHT11 sensor configuration
#define DHTPIN 4         // Pin where the DHT11 data pin is connected
#define DHTTYPE DHT11    // DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

// Relay pin configuration
#define RELAY_PIN 5  // GPIO pin connected to relay control

// WiFi credentials
char ssid[] = "Eco";      // Replace with your WiFi SSID
char pass[] = "riidabinqsj5vpr";  // Replace with your W iFi Password

BlynkTimer timer;

void setup(){
  Serial.begin(115200);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Initially, turn off the relay
  
  timer.setInterval(2000L, sendSensorData); // Set a timer to run every 2 seconds
}

void sendSensorData()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send temperature and humidity data to Blynk
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

  // Control relay based on temperature
  if (temperature > 5.0)
  {
    digitalWrite(RELAY_PIN, LOW);  // Turn ON relay to activate Peltier module
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);  // Turn OFF relay to deactivate Peltier module
  }

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

void loop()
{
  Blynk.run();
  timer.run();
}

