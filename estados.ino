#define F_CPU 16000000ul //Definicion de reloj ATMEGA328P externo que está en Arduino UNO
#include <avr/io.h> // Libreria estándar avr
#include <util/delay.h> //Librería para tiempo
#include "i2c.h"      //inclusion libreria memoria
#define ESTADO0 0
#define ESTADO1 1
#define ESTADO2 2
#define ESTADO3 3
#define ESTADO4 4

#define PALABRAINICIO '#'
#define OPCION1 '1'
#define OPCION2 '2'
#define OPCION3 '3'


int estado=0;
char incomingByte;
char dato[2]={1,2};
int numero[2]={1,2};
int cont=0;
int num=0;
int j=0;
int i=0;
int y=0;
char nuevo[1]={0};
int cont1=0;
int cont2=0;
int cont3=0;
byte prueba;
int probar=0;
int result=0;
int readata=0; //Variable para leer datos de memoria

                     

void escribir(uint16_t address, unsigned char dato); //para escribir o enviar datos a la memoria EEPROM 24LC256
unsigned char leer(uint16_t address);    //recibir datos de la memoria EEPROM 24LC256

uint8_t XORChecksum8(const byte *dato , int largo){
     uint8_t valor=0;
     for(size_t i=0; i< largo ; i++){
        valor^=(uint8_t)dato[i];
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
            estado= ESTADO1;
            while(y<2000){
              readata=leer(y);
              Serial.println(readata);
              y=y+1;
            }
            y=0;
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
      
        dato[cont3]=incomingByte;
        Serial.println(atoi(&dato[cont3]));

            if(dato[cont3]=='0'){
              numero[cont3]=0;
            }
            if(dato[cont3]=='1'){
              numero[cont3]=1;
            }
            if(dato[cont3]=='2'){
              numero[cont3]=2;
            }
            if(dato[cont3]=='3'){
              numero[cont3]=3;
            }
            if(dato[cont3]=='4'){
              numero[cont3]=4;
            }
            if(dato[cont3]=='5'){
              numero[cont3]=5;
            }
            if(dato[cont3]=='6'){
              numero[cont3]=6;
            }
            if(dato[cont3]=='7'){
              numero[cont3]=7;
            }
            if(dato[cont3]=='8'){
              numero[cont3]=8;
            }
            if(dato[cont3]=='9'){
              numero[cont3]=9;
            }
            
        cont++;
        cont3++;
        
        if(cont%2==0){
            
              num= (numero[cont2]*10)+(numero[cont2+1]);  
              escribir(cont1,num);
              _delay_ms(20); 
              
              readata=leer(cont1);
              Serial.println(readata);
              
              prueba= XORChecksum8(readata,8);
              
              numero[cont2]=0;
              numero[cont2+1]=0;
              dato[cont2]=0;
              dato[cont2+1]=0;
              
              cont1++; // esto es para la direccion
              cont3=0;
              
      }
         
     if(cont1==2000){
        estado=ESTADO1;
        break;
      }
      break;

    case ESTADO3:
    
        readata=leer(y);
        Serial.println(readata);
        y=y+1;

      if(y==2000){
        estado=ESTADO1;  
      }
        
     break;

    case ESTADO4:

        readata=leer(0);
        Serial.println(readata);
       

        estado=ESTADO1;
       break;
  }

  }
}
