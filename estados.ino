#define F_CPU 16000000ul //Definicion de reloj ATMEGA328P externo que está en Arduino UNO
#include <avr/io.h> // Libreria estándar avr
#include <util/delay.h> //Librería para tiempo
#include "i2c.h"      //inclusion libreria memoria
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

int readata=0; //Variable para leer datos de memoria
int address[2]={0,1};
long int value=3;
                     

void escribir(uint16_t address, unsigned char dato); //para escribir o enviar datos a la memoria EEPROM 24LC256
unsigned char leer(uint16_t address);    //recibir datos de la memoria EEPROM 24LC256

uint8_t XORChecksum8(const byte *dato , int largo){
     uint8_t valor=0;

     while(dato<largo){
        valor^=(uint8_t)(*dato);
        dato++;
      }
      return ~valor;
}

void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
int n=0;
void loop() {
   i2c_iniciar();      //empezar la comunicación
  
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

      readata=leer(address[0]);  
      Serial.println(readata);

      estado=ESTADO1;
       break;

    case ESTADO4:
        
      readata=leer(address[2]);  
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
           escribir(address[cont],atoi(&dato[cont]));
           _delay_ms(20);            //pausa de 20ms para darle tiempo a la eeprom
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
