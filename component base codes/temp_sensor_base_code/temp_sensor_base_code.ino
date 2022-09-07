
#include "DHT.h"// - DHT Sensor Library

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11// Uncomment whatever type you're using!

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));

  dht.begin();
}

void loop() {


  
  // Wait a few seconds between measurements.
  

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 

  float t = dht.readTemperature();  // Read temperature as Celsius (the default)
  


  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));

 
  if (isnan(t)) {      // Check if any tempreture reads failed and exit early (to try again).
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
    }


  





}
