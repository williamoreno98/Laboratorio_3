
#include "Wire.h"
#define EEPROM_I2C_ADDRESS 0x50

#define ESTADO0 0
#define ESTADO1 1
#define ESTADO2 2
#define ESTADO3 3
#define ESTADO4 4
#define ESTADO5 5
#define ESTADO6 6
#define ESTADO7 7
#define ESTADO8 8
#define ESTADO9 9
#define ESTADO6 10
#define PALABRAINICIO '#'
#define OPCION1 '1'
#define OPCION2 '2'
#define OPCION3 '3'

int estado=0;
char incomingByte;
char dato[2]={3,5};
char nuevo[2]={3,5};
int cont=0;
int f=0;

int readata=0;
int address[2]={0,1};
long int value=3;

uint8_t XORChecksum8(const byte *dato , int largo){
     uint8_t valor=0;

     while(dato<largo){
        valor^=(uint8_t)(*dato);
        dato++;
      }
      return ~valor;
}

void setup() {
   Wire.begin();
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
int n=0;
void loop() {
  // send data only when you receive data:

  if(Serial.available()>0){
         incomingByte = Serial.read();
         if(n=0){
          estado= ESTADO0;
         }
  
  switch(estado){

    case ESTADO0:

          if(incomingByte== PALABRAINICIO){
              Serial.println("Llego bien");
              estado= ESTADO1;
              n=1;
            }
          else {
              estado= ESTADO0;
            }
       break;
       
    case ESTADO1:

        if(incomingByte== OPCION1 ){
            Serial.println("Elegiste opcion 1 para escribir");
            estado= ESTADO2;
            cont=0;
            break;
          }
        if(incomingByte== OPCION2 ){
            Serial.println("Elegiste opcion 2 para leer todo");    
            estado= ESTADO3;
            break;
        }
        if(incomingByte == OPCION3){
            Serial.println("Elegiste opcion 3 para leer un dato");  
            estado= ESTADO4;
          break;
        }
        else{
          estado= ESTADO1;
          break;
          } 
    

    case ESTADO2: 
        dato[cont]=incomingByte;
        cont++;
        if(cont==2){
          estado= ESTADO5;
          cont=0;
        }
    
      break;

    case ESTADO3:
        
      Wire.beginTransmission(EEPROM_I2C_ADDRESS);  // make control byte to begin the transmission
      Wire.write((int)(address[0] >> 8));  // high address byte
      Wire.write((int)(address[0] & 0xFF)); // low address byte
      Wire.endTransmission();
      Wire.requestFrom(EEPROM_I2C_ADDRESS,1); // pedir a la memoria leer
      readata= Wire.read(); //leer dato y guarda
      Serial.println(readata);

      estado=ESTADO1;
       break;

    case ESTADO4:
        
      Wire.beginTransmission(EEPROM_I2C_ADDRESS);  // make control byte to begin the transmission
      Wire.write((int)(address[0] >> 8));  // high address byte
      Wire.write((int)(address[0] & 0xFF)); // low address byte
      Wire.endTransmission();
      Wire.requestFrom(EEPROM_I2C_ADDRESS,1); // pedir a la memoria leer
      readata= Wire.read(); //leer dato y guarda
      Serial.println(readata);

      estado=ESTADO1;
       break;

    case ESTADO5: 
      nuevo[0]= incomingByte;
      char crc=(char)XORChecksum8(&dato[0],2);
      char crc2=(char)XORChecksum8(&nuevo[0],2);
      if(crc==crc2){
        
        Serial.println("CRC bien"); 

          while(cont<2){
       
            Wire.beginTransmission(EEPROM_I2C_ADDRESS);  // make control byte to begin the transmission
            Wire.write((int)(address[cont] >> 8));  // high address byte
            Wire.write((int)(address[cont] & 0xFF)); // low address byte
            Wire.write(atoi(&dato[0]));
            Wire.endTransmission();
            Serial.println(dato[cont]);
            delay(5);
            cont++;
          }
      }
      else{
        Serial.println("CRC mal");
        estado=ESTADO1;
        }
       if(cont==2){
        estado=ESTADO1;
        }
    break;
  }

  }
}
