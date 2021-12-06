#include "SD.h"
#include"SPI.h"
const int CSpin = 10;
String dataString =""; // holds the data to be written to the SD card
float power = 0.00; // value read from your first sensor
float voltage = 0.00; // value read from your second sensor
float resistance = 0;
File sensorData;


void setup()
{

  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  pinMode(CSpin, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  resistance = 12,5;

  if (!SD.begin(CSpin)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop(){

  dataString = String(power) + "," + String(voltage) + "; // convert to CSV
  saveData(); // save to SD card
  delay(60000); // delay before next write to SD Card, adjust as required
}

void saveData(){
  if(SD.exists("data.csv")){ 
  sensorData = SD.open("data.csv", FILE_WRITE);
  if (sensorData){
    sensorData.println(dataString);
    sensorData.close(); 
    }
}
  else{
  Serial.println("Error writing to file !");
  }
}
