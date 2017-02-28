# Secondary-Flight-Computer-Recovery
All files pertaining to the Arduino and components which make up our secondary flight computer and recovery.

## Install Libraries

To compile the program, you must have the required libraries installed:
* [Adafruit Unified Sensor Driver](https://github.com/adafruit/Adafruit_Sensor)
* [Adafruit LSM303DLHC Driver (Accelerometer + Magnetometer)](https://github.com/adafruit/Adafruit_LSM303DLHC)
* [Adafruit Unified L3GD20 Driver](https://github.com/adafruit/Adafruit_L3GD20_U)
* [Adafruit Unified BMP085/BMP180 Driver (Barometric Pressure Sensor)](https://github.com/adafruit/Adafruit_BMP085_Unified)
* [Adafruit 10DOF Library](https://github.com/adafruit/Adafruit_10DOF)
* [SD Library for Arduino](https://github.com/arduino-libraries/SD)

To install these libraries, download each library as a ZIP and move the root folder of the ZIP into the `libraries` directory located in the default sketchbook directory. If the `libraroes` directory does not exist, create it. The location varies depending on the OS:

Linux: `~/Arduino/libraries`

Mac OS: `~/Documents/Arduino/libraries`

Windows: `%USERPROFILE%\Documents\Arduino\libraries`
