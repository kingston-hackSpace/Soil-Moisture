/*
Monitor Soil Moisture 

HARDWARE:
Arduino UNO
Sparkfun Soil Moisture Sensor

NOTE
Rather than powering the sensor through the 3.3V or 5V pins, 
we'll use a digital pin to power the sensor. This will 
prevent corrosion of the sensor as it sits in the soil. 

*/

int moisture_sensor = A0;
int soilPower = 7; //Variable for Soil moisture Power
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
}

void loop() {
  Serial.print("Soil Moisture = ");    // print in serial monitor
  Serial.println(readSoil()); // call function below
  delay(1000);
}

int readSoil(){
    digitalWrite(soilPower, HIGH); //turn D7 "On"
    delay(10);//wait 10 milliseconds 
    sensorValue = analogRead(moisture_sensor);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return sensorValue;//send current moisture value
}
