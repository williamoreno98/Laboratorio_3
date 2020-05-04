
#ifndef I2C_H_
#define I2C_H_

void i2c_iniciar();      //función para iniciar el módulo TWI I2C AVR
void i2c_espera();       //función de espera
void i2c_inicia_com();   //función que inicia la comunicación I2C AVR
void i2c_detener();      //función que detiene la comunicación I2C AVR
void i2c_envia_dato(unsigned char );   //función para enviar o escribir
                                       
unsigned char i2c_recibe_dato_ack();   
                                       
unsigned char i2c_recibe_dato_nack();  
                                      
uint8_t i2c_estado_com();  //función para averiguar el estado de la comunicación I2C AVR
                           //útil para detectar errores
             

void i2c_iniciar(){
  PORTC|=((1<<4)|(1<<5));  //activa resistencias pull upp para SCL y SDA
  TWBR=12;                  //velocidad 400Khz, Fosc 16Mhz, prescaler de 1
  TWCR|=(1<<TWEN);         //módulo TWI iniciado
}


 
void i2c_espera(){
  while ((TWCR & (1<<TWINT)) == 0);//espera mientras el  bit de interrupcion sea 0
}


void i2c_inicia_com() {
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//bandera de interrupción a 1, start, habilita I2C AVR
  i2c_espera();       //espera mientras el bit TWINT sea 0
}


void i2c_detener() {
  TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);//bandera de interrupción a 1, detener, habilita I2C AVR
}

void i2c_envia_dato(unsigned char dato) {
  TWDR = dato;
  TWCR = (1<<TWINT)|(1<<TWEN);//para empezar a enviar el dato
  i2c_espera();//cuando TWINT se ponga a 1 se habrá terminado de enviar el dato
}

unsigned char i2c_recibe_dato_ack(){//maestro envia ack para seguir recibiendo
                                  //mas  datos
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
  i2c_espera();
  return TWDR;
}

unsigned char i2c_recibe_dato_nack(){//maestro no envia ack para no seguir recibiendo
                                   //mas  datos
  TWCR = (1<<TWINT)|(1<<TWEN);
  i2c_espera();
  return TWDR;
}

uint8_t i2c_estado_com(){
  uint8_t estado;        //variable donde se almacena el estado de la comunicación
                         //I2C AVR
  estado = TWSR & 0xf8;  //en la variable estado se guarda el valor de los 5 bits de
                         //mas peso del registro TWSR seguidos de 3 ceros,
               //el número obtenido indica 
               //el estado en que se encuentra la comunicación I2C AVR
               
  return estado;         //la función retorna el estado de la comunicación
}



void escribir(uint16_t address, unsigned char dato){
  i2c_inicia_com();    //inicia la comunicación serial i2C AVR
  i2c_envia_dato(0xa0);   //envía la dirección del esclavo 

  i2c_envia_dato(address>>8); //envia parte alta de la direccion del registro
                  //de la EEPROM donde se guardará el dato
                  
  i2c_envia_dato(address);    //envia parte baja de la direccion del registro
                  //de la EEPROM donde se guardará el dato
 
  i2c_envia_dato(dato); //envia o escribe el dato en la dirección del registro
              //elegido de la memoria EEPROM
  i2c_detener(); //finaliza la comunicación I2C AVR
}


unsigned char leer(uint16_t address){
  unsigned char dato;//variable donde se guardará el dato leído desde la EEPROM
  
  i2c_inicia_com();    //inicia la comunicación serial i2C AVR
  
  i2c_envia_dato(0xa0); //envía la dirección del esclavo 
 
  i2c_envia_dato(address>>8); //envia la parte alta de la direccion del registro
                  //de la EEPROM de donde se leerá el dato
  i2c_envia_dato(address);    //envia la parte baja de la direccion del registro
                  //de la EEPROM de donde se leerá el dato

  i2c_inicia_com();  //para reiciar la comunicación I2C AVR
 
  i2c_envia_dato(0xa1); //dirección de la eeprom junto con el 1 para lectura
  
  dato=i2c_recibe_dato_nack(); //lectura del dato de la ubicación de la memoria
                
  i2c_detener(); //finaliza la comunicación I2C AVR
  
  return dato; //la función devolverá el dato leído desde la EEPROM y guardado en
               //la variable dato
}

#endif
