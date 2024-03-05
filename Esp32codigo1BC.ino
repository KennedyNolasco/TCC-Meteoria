#include "DHT.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

DHT dht(32,DHT11);
Adafruit_BMP280 bmp;

// Pinos dos Sensores

int lumiPin = 34;
int rainPin = 35;
int tempPin = 32;
int grndPin = 14;

// Set dos Sensores 

int ldrMax = 4000;
int thresholdValue = 50;

void setup() {
    Serial.begin(9600);
    while ( !Serial ) delay(100);   // wait for native usb
    Serial.println(F("BMP280 test"));
    unsigned status;
    //status = bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID);
    status = bmp.begin(0x76);
    if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
                 }

    /* Default settings from datasheet. */
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                    Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                    Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
               

  
    dht.begin();
    pinMode(grndPin, INPUT);
    pinMode(lumiPin, INPUT);
    pinMode(rainPin, INPUT);
    //Serial.printf("weatherstation Initialized.\n");
}

 

void loop() {
    
    String serialCommand;
    while (Serial.available() > 0) {
        char serialChar = Serial.read();
        serialCommand += serialChar; 

        if (serialChar == '\n') {
            processCommand(serialCommand);
            serialCommand = "";
        }
    }
    
    delay(1500); // modificado para teste
}


void processCommand(String command) {
    command.trim();
    command.toUpperCase();
   
    if (command == "GET_DATA")
      Serial.printf("RES GET_DATA %d %d %d %d %d %d\n", humiGetValue(), rainGetValue(), pressureGetValue(), tempeGetValue(), lumiGetValue(), groundGetValue());
    else
      Serial.println("ERR Unknown command.\n");
      
}

//Funções de leitura e retorno

int lumiGetValue() {
    int lumiAnalog = analogRead(lumiPin);
    int lumiValue = 100*lumiAnalog/ldrMax;
    return lumiValue > 100 ? 100 : lumiValue;
}

int rainGetValue(){
    int rainAnalog = analogRead(rainPin);
    int rainValue = 100*rainAnalog/ldrMax;
    return rainValue > 100 ? 100 : rainValue;
}

int groundGetValue(){
    int groundAnalog = analogRead(grndPin);
    int groundValue = 100*groundAnalog/ldrMax;
    return groundValue > 100 ? 100 : groundValue;
}


//retornar valores int

int humiGetValue() {
    int humiAnalog = dht.readHumidity()*100;
    int humiValue = humiAnalog;
    return humiValue;
}

int tempeGetValue() {
    int tempeAnalog = dht.readTemperature()*100;
    int tempeValue = tempeAnalog;
    return tempeValue;
}

int pressureGetValue() {
    int tempeValue = bmp.readPressure();
    return tempeValue;
}

        
