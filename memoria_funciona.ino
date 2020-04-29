
#define F_CPU 16000000ul //Definicion de reloj ATMEGA328P externo que está en Arduino UNO
#include <avr/io.h> // Libreria estándar avr
#include <util/delay.h> //Librería para tiempo
#include "i2c.h"      //inclusion libreria memoria
                      
int readata=0; //Variable para leer datos de memoria

void escribir(uint16_t address, unsigned char dato); //para escribir o enviar datos a la memoria EEPROM 24LC256
unsigned char leer(uint16_t address);    //recibir datos de la memoria EEPROM 24LC256
                  
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop(){
 
  i2c_iniciar();      //empezar la comunicación
  
  while(1)
  {
    for(uint8_t i=0;i<=100;i++){  //en las direccienes que van desde 0 a 100
      escribir(i,i+25);      //de la EEPROM se enviarán o escribirán sus
                                //mismas direcciones
      _delay_ms(20);            //pausa de 20ms para darle tiempo a la eeprom
    }                             //a que reciba bien los datos

    for(uint8_t i=0;i<=100;i++){  //para las direcciones de memoria de la EEPROM
                                //de la 0 a la 100
      readata=leer(i);     //menvia al puerto D el valor leido en la
      Serial.println(readata);      //posición de memoria, será visto en forma
                                //binaria con leds
      
      _delay_ms(1000);          //pausa para que el dato leído en el puerto D
    }                             //sea visto cada segundo
  }
}
