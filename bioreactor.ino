/*
FONCTIONNEL
Picobrewery Project 
Code by Dearcham 07/01/2013
 Other code with lib
http://arduino-info.wikispaces.com/Brick-Temperature-DS18B20

SSr http://www.homeroasters.org/php/forum/viewthread.php?thread_id=2268&rowstart=0

Simple code to test temperature probe, interpret it with the apporpriate librairies (see under) and send the value to Serial  

Circuit :
SensorShield on Arduino 2560 bought on Yourduino
T°probe DS18b20 bought on Yourduino (Wiring : 1Vcc 5V 1Grnd 1Signal on digital 2) 
A pull up resistor 4,7Komh between signal  (yellow) and Vcc(+) (red)
Can be juiced up by arduino  with sensor shield

------->PLUG ON A DIGITAL ENTRY<-------

DEPENDANCES
:Library “DallasTemperatureControl” (change the lib directory for this name) AND
 Library “OneWire”
http://download.milesburton.com/Arduino/MaximTemperature/DallasTemperature_372Beta.zip
http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip


 */
/* YourDuino Electronic Brick Test
Temperature Sensor DS18B20
- Connect cable to Arduino Digital I/O Pin 2
terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <OneWire.h>
#include <DallasTemperature.h>

/*-----( Declare Constants )-----*/
#define ONE_WIRE_BUS 6 /*-(Connect to Pin 2 )-*/

/*-----( Declare objects )-----*/
/* Set up a oneWire instance to communicate with any OneWire device*/
OneWire ourWire(ONE_WIRE_BUS);

/* Tell Dallas Temperature Library to use oneWire Library */
DallasTemperature sensors(&ourWire);

/*-----( Declare Variables )-----*/
String ph_sensor_string = ""; 
String oh_sensor_string = "";
String t_sensor_string = "";
boolean ph_sensor_string_complete = false; 
boolean oh_sensor_string_complete = false;

void setup(void) /*----( SETUP: RUNS ONCE )----*/
{
  /*-(start serial port to see results )-*/
  delay(1000);
  Serial.begin(38400);
  Serial2.begin(38400); // OH Sensor
  Serial3.begin(38400); // PH Sensor
  delay(1000);

  /*-( Start up the DallasTemperature library )-*/
  sensors.begin();
}/*--(end setup )---*/


void loop() /*----( LOOP: RUNS CONSTANTLY )----*/
{
  sensors.requestTemperatures(); // Send the command to get temperatures
  t_sensor_string = "T  : " + (String)sensors.getTempCByIndex(0);
  Serial.println(t_sensor_string);
  if (ph_sensor_string_complete &&  oh_sensor_string_complete ) { 
    Serial.println(ph_sensor_string);
    Serial.println(oh_sensor_string);
    ph_sensor_string = ""; 
    oh_sensor_string = "";
    ph_sensor_string_complete = false;
    oh_sensor_string_complete = false; 
  }
  Serial.println();
}/* --(end main loop )-- */

/* ( THE END ) */

