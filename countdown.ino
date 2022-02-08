// demo program 

#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;

void setup() {
  Serial.begin(115200);
  Serial.println("Circuit Playground - Countdown test!");

  CircuitPlayground.begin();
}

void loop() {

  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  
  if (leftButtonPressed) {
    CircuitPlayground.clearPixels();
    Serial.println("Left button pressed...");
    
    // Animation "3"
    CircuitPlayground.setPixelColor(0, 0xFF0000);
    CircuitPlayground.setPixelColor(1, 0xFF0000);
    CircuitPlayground.setPixelColor(2, 0xFF0000);
    Serial.print("3... ");
    CircuitPlayground.playTone(440, 100, false);
    delay(1000);

    // Animation "2"
    CircuitPlayground.setPixelColor(2, 0x000000);
    Serial.print("2... ");
    CircuitPlayground.playTone(440, 100, false);
    delay(1000);

    // Animation "1"
    CircuitPlayground.setPixelColor(1, 0x000000);
    Serial.print("1... ");
    CircuitPlayground.playTone(440, 100, false);
    delay(1000);

    // Animation "GO"
    for(uint8_t i; i<10; i++){
      CircuitPlayground.setPixelColor(i, 0x00FF00);
    }
    Serial.println(" Time up! ");
    CircuitPlayground.playTone(880, 100, false);
  }
}