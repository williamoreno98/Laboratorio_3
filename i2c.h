
#ifndef I2C_H_
#define I2C_H_

void i2c_iniciar();      //función para iniciar el módulo TWI I2C AVR
void i2c_espera();       //función de espera
void i2c_inicia_com();   //función que inicia la comunicación I2C AVR
void i2c_detener();      //función que detiene la comunicación I2C AVR
void i2c_envia_dato(unsigned char );   //función para enviar o escribir
                                       //datos en el esclavo
unsigned char i2c_recibe_dato_ack();   //función para recibir o leer datos del esclavo
                                       //enviando el bit ACK si se quiere leer mas datos
                     //después del último leído
unsigned char i2c_recibe_dato_nack();  //función para recibir o leer datos del esclavo
                                       //sin enviar el bit ACK si no se quiere leer mas datos
                     //después del último leido
uint8_t i2c_estado_com();  //función para averiguar el estado de la comunicación I2C AVR
                           //útil para detectar errores
             
///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//inicialización del módulo TWI I2C AVR en el ATMEL STUDIO en una función////
//para el ATMEGA328P como maestro
//a 400KHz con un oscilador de 8Mhz

void i2c_iniciar(){
  PORTC|=((1<<4)|(1<<5));  //activa resistencias pull upp para SCL y SDA
  TWBR=12;                  //velocidad 400Khz, Fosc 16Mhz, prescaler de 1
  TWCR|=(1<<TWEN);         //módulo TWI iniciado
}


  
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// Función de espera: mientras el bit7 o bit TWINT del registro
// TWCR sea 0, el IC2 AVR se esperará
// antes de realizar algún trabajo


void i2c_espera(){
  while ((TWCR & (1<<TWINT)) == 0);//espera mientras el  bit de interrupcion sea 0
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// Función de inicio de la comunicación I2C AVR

void i2c_inicia_com() {
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//bandera de interrupción a 1, start, habilita I2C AVR
  i2c_espera();       //espera mientras el bit TWINT sea 0
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// Función de parada de la comunicación I2C I2C

void i2c_detener() {
  TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);//bandera de interrupción a 1, detener, habilita I2C AVR
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//Función de transmisión de datos del maestro al esclavo

void i2c_envia_dato(unsigned char dato) {
  TWDR = dato;
  TWCR = (1<<TWINT)|(1<<TWEN);//para empezar a enviar el dato
  i2c_espera();//cuando TWINT se ponga a 1 se habrá terminado de enviar el dato
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//Función de recepción de datos enviados por el esclavo al maestro
//esta función es para leer los datos que están en el esclavo
//en forma continua, esto es tras leer uno se volverá a leer otro

unsigned char i2c_recibe_dato_ack(){//maestro envia ack para seguir recibiendo
                                  //mas  datos
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
  i2c_espera();
  return TWDR;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//Función de recepción de datos enviados por el esclavo al maestro
//esta función es para leer solo un dato desde el esclavo
//esto es tras leer uno ya no se volverá a leer otro

unsigned char i2c_recibe_dato_nack(){//maestro no envia ack para no seguir recibiendo
                                   //mas  datos
  TWCR = (1<<TWINT)|(1<<TWEN);
  i2c_espera();
  return TWDR;
}


/////////////////////////////////////////////////////////////////
//función para averiguar el estado de la comunicación I2C AVR
//útil para detectar errores, el valor que retorna esta función
//se compara con el estado que deberían indicar los bits del 7 al 3
//del registro TWSR según tabla, durante la comunicación I2C AVR,

uint8_t i2c_estado_com(){
  uint8_t estado;        //variable donde se almacena el estado de la comunicación
                         //I2C AVR
  estado = TWSR & 0xf8;  //en la variable estado se guarda el valor de los 5 bits de
                         //mas peso del registro TWSR seguidos de 3 ceros,
               //el número obtenido indica 
               //el estado en que se encuentra la comunicación I2C AVR
               
  return estado;         //la función retorna el estado de la comunicación
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

#endif
