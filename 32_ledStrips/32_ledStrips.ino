#include <Adafruit_NeoPixel.h>

#define PIN     13
#define NUMPIXELS 32
#define RGB 65535

Adafruit_NeoPixel pixels(NUMPIXELS,PIN, NEO_GRB + NEO_KHZ800);

int pot1 = A5;
int pot2 = A3;
int pot3 = A0;
int interval = 50;


void setup(){
    pixels.begin();
    pixels.show();
}



void rainbow(){
    int x = 0;
    while (x<RGB){
        pixels.rainbow(x,1,255,255,true);
        pixels.show();
        delay(interval);
        x+=1000;
        interval = analogRead(pot1)/8;
    }
}

/*void three_potentiometers(){
    int pot1Val = analogRead(pot1) / 4; //Deler på 4 for å gå fra analogread sin 0-1023 til rgb sin 0-255.
    int pot2Val = analogRead(pot2) / 4;
    int pot3Val = analogRead(pot3) / 4;
     for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pot1Val, pot2Val, pot3Val);
  }
  pixels.show();
  delay(100);
}*/

void loop(){
    rainbow();
    //three_potentiometers();
    
}

