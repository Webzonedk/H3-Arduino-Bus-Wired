//------------------------------------------------------------
// SLAVE COM port 9
//------------------------------------------------------------

// Libraries
#include <Wire.h>

short Leds[] =
    {
        8,
        9,
        10,
        11,
        12,
        13};

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);

  for (int i = 0; i < sizeof(Leds) / sizeof(short); i++)
  {
    pinMode(Leds[i], OUTPUT);
  }
}

void loop()
{
  delay(100);
  // blinkFunction();
}

void receiveEvent(int howMany)
{
  while (0 < Wire.available()) // loop through all
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);      // print the character
  }
  // Serial.println();
  // float x = Wire.read(); // receive byte as an integer
  // Serial.println(x);   // print the integer

  //   while (0 < Wire.available()) // loop through all
  // {
  //   char c = Wire.read(); // receive byte as a character
  //   Serial.print(c);      // print the character
  // }
  // Serial.println();
  // // int x = Wire.read(); // receive byte as an integer
  // // Serial.println(x);   // print the integer

  // while (1 < Wire.available()) // loop through all but the last
  // {
  //   char c = Wire.read(); // receive byte as a character
  //   Serial.print(c);      // print the character
  // }
  // int x = Wire.read(); // receive byte as an integer
  // Serial.println(x);   // print the integer
}

void blinkFunction()
{
  for (int i = 0; i < sizeof(Leds) / sizeof(short); i++)
  {
    digitalWrite(Leds[i], HIGH);
    delay(200);
    digitalWrite(Leds[i], LOW);
  }
  Serial.println("LED looop op");
  for (int i = sizeof(Leds) / sizeof(short) - 2; i >= 1; i--)
  {
    digitalWrite(Leds[i], HIGH);
    delay(200);
    digitalWrite(Leds[i], LOW);
  }
  Serial.println("LED looop ned");
}