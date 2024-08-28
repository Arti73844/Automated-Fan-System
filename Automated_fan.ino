#include <DHT.h> 
 
#define DHTPIN 2 
#define DHTTYPE DHT11 
 
#define FAN_PIN 3 
#define GREEN_LED_PIN 4 
#define BLUE_LED_PIN 5 
 
DHT dht(DHTPIN, DHTTYPE); 
 
void setup() { 
  Serial.begin(9600); 
  pinMode(FAN_PIN, OUTPUT); 
  pinMode(GREEN_LED_PIN, OUTPUT); 
  pinMode(BLUE_LED_PIN, OUTPUT); 
} 
 
void loop() { 
  float humidity = dht.readHumidity(); 
  float temperature = dht.readTemperature(); 
  float temp; 
  if(temperature < 0){ 
    temp = temperature +22.7; 
    Serial.print("%, Temp: "); 
    Serial.print(temp); 
     Serial.print("%, temperature: "); 
    Serial.print(temperature); 
  }else if(temperature > 0 ){ 
    temp = temperature+0; 
    Serial.print("%, Temp: "); 
    Serial.print(temp); 
     Serial.print("%, temperature: "); 
    Serial.print(temperature); 
  } 
 
  Serial.print("Humidity: "); 
  Serial.print(humidity); 
  
  Serial.println("°C"); 
   if (temp > 12.0) { 
    digitalWrite(FAN_PIN, HIGH);      // Turn on the fan 
    digitalWrite(GREEN_LED_PIN, HIGH); // Turn on the green LED 
    digitalWrite(BLUE_LED_PIN, LOW);   // Turn off the blue LED 
    Serial.println("green"); 
  } else if(temp < 10){ 
    digitalWrite(FAN_PIN, LOW );       // Turn off the fan 
    digitalWrite(GREEN_LED_PIN, LOW);  // Turn off the green 
LED 
    digitalWrite(BLUE_LED_PIN, HIGH);  // Turn on the blue LED 
    Serial.println("blue"); 
  } 
 
  delay(1000); // Delay for better readability in Serial 
Monitor 
} 