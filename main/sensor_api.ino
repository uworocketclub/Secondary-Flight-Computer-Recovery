#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_10DOF.h>

/* Assign a unique ID to the sensors */
Adafruit_10DOF                dof   = Adafruit_10DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);

/* Update this with the correct SLP for accurate altitude measurements */
//float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
float seaLevelPressure = 999.25;

void initSensors()
{
  if(!accel.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no Acc LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no Mag LSM303 detected ... Check your wiring!");
    while(1);
  }
  if(!bmp.begin())
  {
    /* There was a problem detecting the BMP180 ... check your connections */
    Serial.println("Ooops, no BMP180 detected ... Check your wiring!");
    while(1);
  }
}

boolean accelerometer_sensor(float &pitch, float &roll, float &heading) 
{
  sensors_event_t accel_event;
  sensors_vec_t   orientation;
 
  sensors_event_t mag_event;
  /* Calculate pitch and roll from the raw accelerometer data */
  accel.getEvent(&accel_event);
  boolean accel_success = dof.accelGetOrientation(&accel_event, &orientation);
  
  mag.getEvent(&mag_event);
  boolean mag_success = dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation);
  
  if (accel_success && mag_success)
  {
    /* 'orientation' should have valid .roll and .pitch fields */
    roll = orientation.roll;
    pitch = orientation.pitch;
    heading = orientation.heading;
    return true;
  }

  return false;
}

boolean altitude_temperature_sensor(float &altitude, float &temperature) 
{
  sensors_event_t bmp_event;

  /* Calculate the altitude using the barometric pressure sensor */
  bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
  {
    /* Get ambient temperature in C */
    bmp.getTemperature(&temperature);
    /* Convert atmospheric pressure, SLP and temp to altitude    */
    altitude = bmp.pressureToAltitude(seaLevelPressure,
                                      bmp_event.pressure,
                                      temperature); 
    return true;
  }

  return false;
}


// Function returns float value for altitude based on sea level pressure, temperature and current pressure. 
float get_alt() {
   bmp.getEvent(&bmp_event);
  if (bmp_event.pressure)
  {
    /* Get ambient temperature in C */
    bmp.getTemperature(&temperature);
    /* Convert atmospheric pressure, SLP and temp to altitude    */
    altitude = bmp.pressureToAltitude(seaLevelPressure,
                                      bmp_event.pressure,
                                      temperature); 
    return altitude;
  }
}
