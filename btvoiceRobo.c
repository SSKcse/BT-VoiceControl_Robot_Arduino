#include <SoftwareSerial.h>

/*
===========================================
=      Bluetooth Voice Control Robot      =
=                                         =
=      by Shuvo Karmaker, Roboticist,     =
=      SSK Innovation Lab - SSKIL         =
=                                         =
=      Contact: sskshuvo.cse@gmail.com    =
===========================================

*/

SoftwareSerial BT(0, 1); // TX, RX respetively
String readvoice;

void setup()
{
    BT.begin(9600);
    Serial.begin(9600);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
}
//-----------------------------------------------------------------------//
void loop()
{
    while (BT.available())
    {                       // Check if there is an available byte to read
        delay(10);          // Delay added to make thing stable
        char c = BT.read(); // Conduct a serial read
        readvoice += c;     // build the string- "forward", "reverse", "left" and "right"
    }
    if (readvoice.length() > 0)
    {
        Serial.println(readvoice);

        if (readvoice == "*ffffffffff#")
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(100);
        }

        else if (readvoice == "*bbbbbbbbbbbb#")
        {
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            delay(100);
        }

        else if (readvoice == "*go#")
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(1000);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(100);
        }

        else if (readvoice == "*back#")
        {
            digitalWrite(3, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(800);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(100);
        }

        else if (readvoice == "*stop#")
        {
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(100);
        }
        else if (readvoice == "*keep watch in all direction#")
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            delay(100);
        }

        readvoice = "";
    }
} // Reset the variable
