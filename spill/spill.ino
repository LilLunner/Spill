#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 32

int speedRead = A0;
int red = A1;
int green = A2;
int blue = A3;
int button1 = 5;
int button2 = 6;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
    pinMode(speedRead, INPUT);
    pinMode(red, INPUT);
    pinMode(green, INPUT);
    pinMode(blue, INPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    Serial.begin(9600);
    pixels.clear();
    pixels.show();
}

void reaction() {
    int dly=random(10,5000);
    delay(dly);
    for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(255,255,255));
    }
    int time=millis();
    pixels.show();
    int i=0;
    while (i==0) {
        if (digitalRead(button1)==HIGH) {
            pixels.clear();
            pixels.show();
            int reaction=millis()-time;
            Serial.print("Player 1 won with a reaction time of "); 
            Serial.print(reaction);
            Serial.println(" milliseconds!");
            i++;
            delay(5000);
            }
        if (digitalRead(button2)==HIGH) {
            pixels.clear();
            pixels.show();
            int reaction=millis()-time;
            Serial.print("Player 2 won with a reaction time of "); 
            Serial.print(reaction);
            Serial.println(" milliseconds!");
            i++;
            delay(5000);
            }
        }
        
    }
        

void loop() {
   reaction(); 
}
