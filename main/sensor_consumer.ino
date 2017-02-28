/*
void setup() {
  Serial.begin(115200);

  Serial.println(F("Adafruit 10 DOF Pitch/Roll/Heading Example")); Serial.println("");

  initSensors();
}

void loop() {
  float pitch, roll, heading;
  float altitude, temperature;

  if(accelerometer_sensor(pitch, roll, heading)) {
    Serial.print(F("Roll: "));
    Serial.print(roll);
    Serial.print(F("; "));
    Serial.print(F("Pitch: "));
    Serial.print(pitch);
    Serial.print(F("; "));
    Serial.print(F("Heading: "));
    Serial.print(heading);
    Serial.print(F("; "));
  }

  if(altitude_temperature_sensor(altitude, temperature)) {
    Serial.print(F("Alt: "));
    Serial.print(altitude); 
    Serial.print(F(" m; "));
    // Display the temperature
    Serial.print(F("Temp: "));
    Serial.print(temperature);
    Serial.print(F(" C"));
  }

  Serial.println(F(""));
  delay(1000);
}*/
