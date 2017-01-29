/*
   Secondary Flight Computer
   UWO Rocket Club
   Contributors:
*/


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }//*/

  // initialise SD card for logging
  initCard();

}

void loop() {
  writeLog("Altitude: test");
  delay(1000);

}

