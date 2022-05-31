#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const int buttonAPin = A0;
static const int buttonBPin = A1;

void setup()
{
    Serial.begin(9600);

    pinMode(buttonAPin, INPUT);
    pinMode(buttonBPin, INPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ; // Don't proceed, loop forever
    }
}

bool buttonA = false;
bool buttonB = false;
int buttonState = 0;

void loop()
{
    buttonState = digitalRead(buttonAPin);
    buttonA = buttonState == HIGH;
    buttonState = digitalRead(buttonBPin);
    buttonB = buttonState == HIGH;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    if (buttonA)
    {
        display.println("Button A");
    }
    if (buttonB)
    {
        display.println("Button B");
    }
    if (!buttonA && !buttonB)
    {
        display.println("No button");
    }
    display.display();
}
