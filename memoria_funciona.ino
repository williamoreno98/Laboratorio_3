#include "Wire.h"
#define EEPROM_I2C_ADDRESS 0x50

int address= 0;
long int value=0;


void setup() {

  Wire.begin();
  Serial.begin(9600);

  //write process 

  for(int i=0; i<256 ;i++){
  value=i;
  address= address+1;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);  // make control byte to begin the transmission
  Wire.write((int)(address >> 8));  // high address byte
  Wire.write((int)(address & 0xFF)); // low address byte
  Wire.write(value);
  Wire.endTransmission();
  delay(5);
  }
  // read process
  
  long int readata=0;
  Wire.beginTransmission(EEPROM_I2C_ADDRESS);  // make control byte to begin the transmission
  Wire.write((int)(address >> 8));  // high address byte
  Wire.write((int)(address & 0xFF)); // low address byte
  Wire.endTransmission();
  Wire.requestFrom(EEPROM_I2C_ADDRESS,1); // pedir a la memoria leer
  readata= Wire.read(); //leer dato y guardar

  Serial.print(address);
  Serial.print(" : ");
  Serial.print(readata);
}

void loop() {
  // put your main code here, to run repeatedly:

  
}
