//------------------------------------------------------------
// MASTER COM port 8
//------------------------------------------------------------

// Libraries
#include <DHT.h>
#include <Wire.h>

// Constants
#define DHTPIN 4          // what pin we're connected to
#define DHTTYPE DHT22     // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

void setup()
{
  Serial.begin(9600);
  dht.begin();
  Wire.begin(); // join i2c bus (address optional for master)

  // for (int i = 0; i < sizeof(Leds) / sizeof(short); i++)
  // {
  //   pinMode(Leds[i], OUTPUT);
  // }
}

// Variables
int chk;
float hum;  // Stores humidity value
float temp; // Stores temperature value

void loop()
{

  masterSend();
  // tempFunction();
}

// void tempFunction()
// {
//   hum = dht.readHumidity();
//   temp = dht.readTemperature();
//   // Print temp and humidity values to serial monitor
//   Serial.print("Humidity: ");
//   Serial.print(hum);
//   Serial.print(" %, Temp: ");
//   Serial.print(temp);
//   Serial.println(" Celsius");
//   delay(2000); // Delay 2 sec.
// }

void masterSend()
{

  hum = dht.readHumidity();
  temp = dht.readTemperature();
  // Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(500); // Delay 2 sec.


  char humidity[6];
  char temperature[6];
  String test = String(hum, 3);
  String test2 = String(temp, 3);
  test.toCharArray(humidity, test.length());
  test2.toCharArray(temperature, test2.length());
  // test.concat(hum);
  // test2.concat(temp);

  Wire.beginTransmission(4); // transmit to device #4
  // Wire.write("Hu: ");  // sends five bytes
  Wire.write(humidity);      // sends one byte
  Wire.write(";");  // sends one byte
  // Wire.write(" %, Temp: ");  // sends one byte
  Wire.write(temperature);   // sends one byte
  // Wire.write(" Celcius");    // sends one byte
  Wire.write(";");    // sends one byte
  Wire.endTransmission();    // stop transmitting

  delay(500);

}
