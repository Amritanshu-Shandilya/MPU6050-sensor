#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

  delay(100);
}

void datapacket() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print("@"); //New Data pack identifier
  Serial.print(g.gyro.x); Serial.print("x"); //gyro X
  Serial.print(g.gyro.y); Serial.print("y"); //gyro Y
  Serial.print(g.gyro.z); Serial.print("z"); //gyro Z
  Serial.print(a.acceleration.x); Serial.print("X"); //acclerometer X
  Serial.print(a.acceleration.y); Serial.print("Y"); //acclerometer Y
  Serial.print(a.acceleration.z); Serial.print("Z"); //acclerometer Z
  Serial.print(temp.temperature); Serial.print("t"); //Temperature
  Serial.print("\n"); //New line

}

void loop() {
  datapacket();
  delay(500); // 2 times per second
}