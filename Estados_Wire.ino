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

#include <Wire.h>    
 
#define disk1 0x50    //Address of 24LC256 eeprom chip

int estado=0;
char incomingByte;
char dato[2]={0,0};
int cont=0;

uint8_t XORChecksum8(const byte *dato , int largo){
     uint8_t valor=0;

     for(int i=0; i< largo ; i++){
        valor^=(uint8_t)(*dato);
        dato++;
      }
      return ~valor;
}

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Wire.begin();  
 
  unsigned int address = 0;
 
  writeEEPROM(disk1, address, 123);
  Serial.print(readEEPROM(disk1, address), DEC);
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
              byte readEEPROM(int deviceaddress, unsigned int eeaddress ) 
              {
               byte rdata = 0xFF;
 
               Wire.beginTransmission(deviceaddress);
               Wire.send((int)(eeaddress >> 8));   // MSB
               Wire.send((int)(eeaddress & 0xFF)); // LSB
               Wire.endTransmission();
 
               Wire.requestFrom(deviceaddress,1);
 
               if (Wire.available()) rdata = Wire.receive();
 
               return rdata;
              }
            estado= ESTADO4;
          break;
        }
        else{
          estado= ESTADO1;
          break;
          } 
    

    case ESTADO2: 
        dato[cont]=incomingByte;
          void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data ) 
            {
            Wire.beginTransmission(deviceaddress);
            Wire.send((int)(eeaddress >> 8));   // MSB
            Wire.send((int)(eeaddress & 0xFF)); // LSB
            Wire.send(data);
            Wire.endTransmission();
 
            delay(5);
            }

        cont++;
        if(cont==2){
          estado= ESTADO5;
        }
    
      break;
    case ESTADO5: 

      Serial.println(dato[0]);
      Serial.println(dato[1]);

      if(incomingByte==XORChecksum8(&dato[0],2)){
        cont=0;
        Serial.println("CRC bien");
        }
      else{
        Serial.println("CRC mal");
                }



    break;
  }


       
     

  }
}
