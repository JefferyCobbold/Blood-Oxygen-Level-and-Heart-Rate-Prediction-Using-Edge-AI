#include <Wire.h>
#include "MAX30105.h"

MAX30105 particleSensor;

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
  Serial.begin(9600);
  delay(1000);  // Allow time for Serial to initialize

  Wire.begin(SDA_PIN, SCL_PIN);  // Use ESP32 I2C pins

  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 not found. Please check wiring.");
    while (1);
  }

  particleSensor.setup();  // Use default configuration
  Serial.println("MAX30102 initialized.");
}

void loop() {
  long irValue = particleSensor.getIR();
  long redValue = particleSensor.getRed();

  Serial.print(irValue);
  Serial.print(",");
  Serial.println(redValue);

  delay(1000); // Log every 1 second
}
