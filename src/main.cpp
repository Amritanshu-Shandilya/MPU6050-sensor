#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "main.h"

Adafruit_MPU6050 mpu;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup_Text(int size, int w, int h){
  display.setTextSize(size);
  display.setTextColor(WHITE);
  display.setCursor(w, h);
}


void set_MPU6050(){
  // Try to initialize!
  display.clearDisplay();
  setup_Text(1,0,10);
  if (!mpu.begin(MPU_ADDRESS)) {
    display.println("Failed to find MPU6050 chip");
    display.display();
    while (1) {
      delay(10);
    }
  }
  display.println("MPU6050 Found!");
  display.display();
  delay(2000);
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  display.clearDisplay();
  display.println("MPU6050 Initialization Done");
  display.display();
}

void set_Screen(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  //Display an icon/image here : logo or something else
  display.clearDisplay();
  setup_Text(1,0,10);
  // Display static text for now
  display.println("Display ON");
  display.display();
  delay(2000);
}

void setup()
{
  Wire.begin();
  Serial.begin(115200);

  // Initialize Screen
  set_Screen();
  // Initialize MPU sensor
  set_MPU6050();  
}

void loop() {

}