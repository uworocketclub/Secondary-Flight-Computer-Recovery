/*
   Secondary Flight Computer
   UWO Rocket Club
   Contributors:
   
*/
float currentAGLafter; //current above ground level altitude
float currentAGLbefore = 0; //last altitude reading (above ground level)
float temperature;
float laucnhAlt = 0; //altitude at launch 
boolean isLaunched = false;
int time; //current time since Arduino started
int timeAtLaunch = 0; //time since launch was detected

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }//*/

  // initialise SD card for logging
  initCard();

  launchAlt = getGroundAlt();
}

void loop() {
  writeLog("Altitude: test");

  currentAGLafter = getAGLAlt();
  
    if(currentAGLafter >= 6) { //signifies that the rocket has launched (6 meters)
      isLaunched = true;
      timeAtLaunch = millis();
    }

    if(isLaunched) {
        if(currentAGLafter < currentAGLbefore) { //then we have reached apogee
          
          //TODO: logic incase we go faster than speed of sound
          //print apogee for testing
          //TODO: after testing fire signal to recovery
          
        }

        else {
          currentAGLbefore = currentAGLafter;
        }
    }
    

  
  delay(1000);

}

//takes 100 samples and selects the lowest as ground altitude
float getGroundAlt() {
  float lowestAlt = 30000;
  float sampleAlt = 0;
  for(int i = 0; i < 100; i++) {
    sampleAlt = get_alt();
    if(sampleAlt < lowestAlt) 
      lowestAlt = sampleAlt;
  }
  return lowestAlt;
}

//get the altitude above ground level
float getAGLAlt() {
  return  get_alt() - groundAltitude;
}

