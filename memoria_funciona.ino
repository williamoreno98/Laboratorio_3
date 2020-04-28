
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
      escribir(i,i+50);      //de la EEPROM se enviarán o escribirán sus
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

//Función para enviar o escribir datos en la memoria EEPROM 24LC256
//creada con las funciones que están en el archivo de cabecera i2c.h
//la función se le ha llamado leer_eeprom, hay que darle dos parámetros
//uno será la dirección del registro de la memoria EEPROM que se desea leer
//o de donde se quiere recibir el dato y el otro el dato a enviar

void escribir(uint16_t address, unsigned char dato){
  i2c_inicia_com();    //inicia la comunicación serial i2C AVR
  
  i2c_envia_dato(0xa0);   //envía la dirección del esclavo con el que el maestro se
              //se quiere comunicar, en este cado de la EEPROM de quien su
              //dirección es de 7 bits (1010000) junto con el bit 0
              //que es el que le indica al esclavo que el maestro quiere
              //enviar o escribir un dato en la EEPROM,
              //por lo que se envia 10100000 que en hexadecimal es 0xa0
  
  //lo que sigue es enviar la dirección del registro de la memoria EEPROM donde se
  //escribirá el dato enviado por el maestro ATMEGA88, como estas direcciones en
  //la EEPROM 24LC256 son de 2 bytes, se envía primero la parte alta de esta dirección
  //y luego la parte baja de esta dirección
  i2c_envia_dato(address>>8); //envia parte alta de la direccion del registro
                  //de la EEPROM donde se guardará el dato
  i2c_envia_dato(address);    //envia parte baja de la direccion del registro
                  //de la EEPROM donde se guardará el dato
  
  //Lo que sigue es enviar el dato a la dirección del registro de la memoria EEPROM
  //donde se guardará el dato.
  i2c_envia_dato(dato); //envia o escribe el dato en la dirección del registro
              //elegido de la memoria EEPROM
  
  //una vez que el esclavo recibe el dato se terminará la comunicación I2C AVR
  i2c_detener(); //finaliza la comunicación I2C AVR
}

//Función para recibir o leer datos desde la memoria EEPROM 24LC256
//creada con las funciones que están en el archivo de cabecera i2c.h
//la función se le ha llamado leer_eeprom, hay que darle un parámetro
//que será la dirección del registro de la memoria EEPROM que se desea leer
//o de donde se quiere recibir el dato

unsigned char leer(uint16_t address){
  unsigned char dato;//variable donde se guardará el dato leído desde la EEPROM
  
  i2c_inicia_com();    //inicia la comunicación serial i2C AVR
  
  i2c_envia_dato(0xa0); //envía la dirección del esclavo con el que el maestro se
              //se quiere comunicar, en este cado de la EEPROM de quien su
              //dirección es de 7 bits (1010000) junto con el bit 0
              //que es el que le indica al esclavo que el maestro quiere
              //enviar o escribir un dato en la EEPROM,
              //por lo que se envia 10100000 que en hexadecimal es 0xa0
  
  //lo que sigue es enviar la dirección del registro de la memoria EEPROM de donde
  //el maestro AATMEGA88 leerá o recibirá el dato, como estas direcciones en
  //la EEPROM 24LC256 son de 2 bytes, se envía primero la parte alta de esta dirección
  //y luego la parte baja de esta dirección
  i2c_envia_dato(address>>8); //envia la parte alta de la direccion del registro
                  //de la EEPROM de donde se leerá el dato
  i2c_envia_dato(address);    //envia la parte baja de la direccion del registro
                  //de la EEPROM de donde se leerá el dato
  
  //lo que sigue una vez que ya se le dijo al esclavo donde se leerá es reiniciar la
  //comunicación serial I2C PIC se hace con la misma función
  //i2c_inicia_com(); el módulo TWI reconoce que se reiniciará la comunicación I2C AVR
  i2c_inicia_com();  //para reiciar la comunicación I2C AVR
  
  //a continuación se vuelve a enviar la dirección del esclavo con el que el maestro se
  //está comunicanco, en este cado de la EEPROM de quien su dirección es de 7 bits (1010000)
  //pero esta vez junto con el bit 1 que es el que le indica al esclavo que el maestro
  //quiere leer o recibir un dato de la EEPROM, por lo que se envia 10100001
  //que en hexadecimal es 0xa1
  i2c_envia_dato(0xa1); //dirección de la eeprom junto con el 1 para lectura
  
  //luego se lee el dato de la ubicación de la memoria elegida de la EEPROM
  //y se guarda en la variable dato creada en un inicio dentro de esta función
  dato=i2c_recibe_dato_nack(); //lectura del dato de la ubicación de la memoria elegida
                               //se utiliza nack porque no se quiere leer los datos en 
                 //forma  continua, para poder verlos en los leds
                 
  //una vez que el maestro lee o recibe el dato se terminará la comunicación I2C AVR
  i2c_detener(); //finaliza la comunicación I2C AVR
  
  return dato; //la función devolverá el dato leído desde la EEPROM y guardado en
               //la variable dato
}
