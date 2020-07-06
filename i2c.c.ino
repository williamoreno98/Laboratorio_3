#define F_CPU 16000000ul //Definicion de reloj ATMEGA328P externo que está en Arduino UNO
#include <avr/io.h> // Libreria estándar avr
#include <util/delay.h> //Librería para tiempo
#include "DHT.h"
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

DHT dht(4, DHT11);
const int analogPin = A0;
int value;      //variable que almacena la lectura analógica raw
int position1;   //posicion del potenciometro en tanto por ciento
const int EchoPin = 3;
const int TriggerPin = 2;


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
   dht.begin();
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
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

      while(i<100){ 
      //Temperatura
      
      float t = dht.readTemperature();
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println(" *C");
      escribir(i,t);
      i=i+1;

      //Potenciometro

      value = analogRead(analogPin);          // realizar la lectura analógica raw
      position1 = map(value, 0, 1023, 0, 100);  // convertir a porcentaje
      Serial.println(position1);
      escribir(i,t);
      i=i+1;

      //Distancia 

       int cm = ping(TriggerPin, EchoPin);
       if(cm<100){
        Serial.print("Distancia: ");
        Serial.println(cm);
        escribir(i,t);
        i=i+1;
       }
         delay(1000);
      }
      estado=ESTADO1;
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


int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
