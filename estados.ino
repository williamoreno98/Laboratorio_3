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
char dato[400]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int numero[400]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int address[200]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199};
int cont=0;
int num=0;
int j=0;
int i=0;
char nuevo[1]={0};

int readata=0; //Variable para leer datos de memoria

                     

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
        Serial.println(atoi(&dato[cont]));

        if(dato[cont]=='0'){
            numero[cont]=0;
           }
        if(dato[cont]=='1'){
            numero[cont]=1;
            }
           if(dato[cont]=='2'){
            numero[cont]=2;
            }
            if(dato[cont]=='3'){
            numero[cont]=3;
            }
             if(dato[cont]=='4'){
            numero[cont]=4;
            }
           if(dato[cont]=='5'){
            numero[cont]=5;
            }
            if(dato[cont]=='6'){
            numero[cont]=6;
            }
            if(dato[cont]=='7'){
            numero[cont]=7;
            }
            if(dato[cont]=='8'){
            numero[cont]=8;
            }
            if(dato[cont]=='9'){
            numero[cont]=9;
            }
            
         cont++;
        if(cont==2){
              
              num= (numero[0]*10)+(numero[1]);  
              escribir(address[0],num);
              _delay_ms(20); 
              readata=leer(address[0]);
              Serial.println(readata);
              
        }
         if(cont==4){
              num= (numero[2]*10)+(numero[3]); 
              escribir(address[1],num);
              _delay_ms(20); 
              readata=leer(address[1]);
              Serial.println(readata);
        
              
          }
         if(cont==6){
               num= (numero[4]*10)+(numero[5]); 
              escribir(address[2],num);
              _delay_ms(20); 
              readata=leer(address[2]);
              Serial.println(readata);
          
          }

          if(cont==8){
               num= (numero[6]*10)+(numero[7]); 
              escribir(address[3],num);
              _delay_ms(20); 
              readata=leer(address[3]);
              Serial.println(readata);
           
          }

          if(cont==10){
               num= (numero[8]*10)+(numero[9]); 
              escribir(address[4],num);
              _delay_ms(20); 
              readata=leer(address[4]);
              Serial.println(readata);
             
          }

          if(cont==12){
               num= (numero[10]*10)+(numero[11]); 
              escribir(address[5],num);
              _delay_ms(20); 
              readata=leer(address[5]);
              Serial.println(readata);
             
          }

          
          if(cont==14){
               num= (numero[12]*10)+(numero[13]); 
              escribir(address[6],num);
              _delay_ms(20); 
              readata=leer(address[6]);
              Serial.println(readata);
             
          }

          if(cont==16){
               num= (numero[14]*10)+(numero[15]); 
              escribir(address[7],num);
              _delay_ms(20); 
              readata=leer(address[7]);
              Serial.println(readata);
             
          }

          if(cont==18){
               num= (numero[16]*10)+(numero[17]); 
              escribir(address[8],num);
              _delay_ms(20); 
              readata=leer(address[8]);
              Serial.println(readata);
             
          }

           if(cont==20){
               num= (numero[18]*10)+(numero[19]); 
              escribir(address[9],num);
              _delay_ms(20); 
              readata=leer(address[9]);
              Serial.println(readata);
             
          }

          if(cont==22){
               num= (numero[20]*10)+(numero[21]); 
              escribir(address[10],num);
              _delay_ms(20); 
              readata=leer(address[10]);
              Serial.println(readata);
             
          }
            if(cont==24){
               num= (numero[22]*10)+(numero[23]); 
              escribir(address[11],num);
              _delay_ms(20); 
              readata=leer(address[11]);
              Serial.println(readata);
             
          }

             if(cont==26){
               num= (numero[24]*10)+(numero[25]); 
              escribir(address[12],num);
              _delay_ms(20); 
              readata=leer(address[12]);
              Serial.println(readata);
             
          }

          if(cont==28){
               num= (numero[26]*10)+(numero[27]); 
              escribir(address[13],num);
              _delay_ms(20); 
              readata=leer(address[13]);
              Serial.println(readata);
             
          }

            if(cont==30){
               num= (numero[28]*10)+(numero[29]); 
              escribir(address[14],num);
              _delay_ms(20); 
              readata=leer(address[14]);
              Serial.println(readata);  
          }

          if(cont==32){
               num= (numero[30]*10)+(numero[31]); 
              escribir(address[15],num);
              _delay_ms(20); 
              readata=leer(address[15]);
              Serial.println(readata);
             
          }

          if(cont==34){
               num= (numero[32]*10)+(numero[33]); 
              escribir(address[16],num);
              _delay_ms(20); 
              readata=leer(address[16]);
              Serial.println(readata);
             
          }

             if(cont==36){
               num= (numero[34]*10)+(numero[35]); 
              escribir(address[17],num);
              _delay_ms(20); 
              readata=leer(address[17]);
              Serial.println(readata);
             
          }

           if(cont==38){
               num= (numero[36]*10)+(numero[37]); 
              escribir(address[18],num);
              _delay_ms(20); 
              readata=leer(address[18]);
              Serial.println(readata);
          }
           if(cont==40){
               num= (numero[38]*10)+(numero[39]); 
              escribir(address[19],num);
              _delay_ms(20); 
              readata=leer(address[19]);
              Serial.println(readata);
          }
           if(cont==42){
               num= (numero[40]*10)+(numero[41]); 
              escribir(address[20],num);
              _delay_ms(20); 
              readata=leer(address[20]);
              Serial.println(readata);
          }

          if(cont==44){
               num= (numero[42]*10)+(numero[43]); 
              escribir(address[21],num);
              _delay_ms(20); 
              readata=leer(address[21]);
              Serial.println(readata);
          }

          if(cont==46){
               num= (numero[44]*10)+(numero[45]); 
              escribir(address[22],num);
              _delay_ms(20); 
              readata=leer(address[22]);
              Serial.println(readata);
          }

           if(cont==48){
               num= (numero[46]*10)+(numero[47]); 
              escribir(address[23],num);
              _delay_ms(20); 
              readata=leer(address[23]);
              Serial.println(readata);
          }

          if(cont==50){
               num= (numero[48]*10)+(numero[49]); 
              escribir(address[24],num);
              _delay_ms(20); 
              readata=leer(address[24]);
              Serial.println(readata);
          }
          if(cont==52){
               num= (numero[50]*10)+(numero[51]); 
              escribir(address[25],num);
              _delay_ms(20); 
              readata=leer(address[25]);
              Serial.println(readata);
          }

           if(cont==54){
               num= (numero[52]*10)+(numero[53]); 
              escribir(address[26],num);
              _delay_ms(20); 
              readata=leer(address[26]);
              Serial.println(readata);
          }

          if(cont==56){
               num= (numero[54]*10)+(numero[55]); 
              escribir(address[27],num);
              _delay_ms(20); 
              readata=leer(address[27]);
              Serial.println(readata);
          }

           if(cont==58){
               num= (numero[56]*10)+(numero[57]); 
              escribir(address[28],num);
              _delay_ms(20); 
              readata=leer(address[28]);
              Serial.println(readata);
          }

           if(cont==60){
               num= (numero[58]*10)+(numero[59]); 
              escribir(address[29],num);
              _delay_ms(20); 
              readata=leer(address[29]);
              Serial.println(readata);
          }

          if(cont==62){
               num= (numero[60]*10)+(numero[61]); 
              escribir(address[30],num);
              _delay_ms(20); 
              readata=leer(address[30]);
              Serial.println(readata);
          }

           if(cont==64){
               num= (numero[62]*10)+(numero[63]); 
              escribir(address[31],num);
              _delay_ms(20); 
              readata=leer(address[31]);
              Serial.println(readata);
          }

          if(cont==66){
               num= (numero[64]*10)+(numero[65]); 
              escribir(address[32],num);
              _delay_ms(20); 
              readata=leer(address[32]);
              Serial.println(readata);
          }

           if(cont==68){
               num= (numero[66]*10)+(numero[67]); 
              escribir(address[33],num);
              _delay_ms(20); 
              readata=leer(address[33]);
              Serial.println(readata);
          }

          if(cont==70){
               num= (numero[68]*10)+(numero[69]); 
              escribir(address[34],num);
              _delay_ms(20); 
              readata=leer(address[34]);
              Serial.println(readata);
          }

          if(cont==72){
               num= (numero[70]*10)+(numero[71]); 
              escribir(address[35],num);
              _delay_ms(20); 
              readata=leer(address[35]);
              Serial.println(readata);
          }

          
          if(cont==74){
               num= (numero[72]*10)+(numero[73]); 
              escribir(address[36],num);
              _delay_ms(20); 
              readata=leer(address[36]);
              Serial.println(readata);
          }

          if(cont==76){
               num= (numero[74]*10)+(numero[75]); 
              escribir(address[37],num);
              _delay_ms(20); 
              readata=leer(address[37]);
              Serial.println(readata);
          }

          if(cont==78){
               num= (numero[76]*10)+(numero[77]); 
              escribir(address[38],num);
              _delay_ms(20); 
              readata=leer(address[38]);
              Serial.println(readata);
          }

           if(cont==80){
               num= (numero[78]*10)+(numero[79]); 
              escribir(address[39],num);
              _delay_ms(20); 
              readata=leer(address[39]);
              Serial.println(readata);
          }
          if(cont==82){
               num= (numero[80]*10)+(numero[81]); 
              escribir(address[40],num);
              _delay_ms(20); 
              readata=leer(address[40]);
              Serial.println(readata);
          }

           if(cont==84){
               num= (numero[82]*10)+(numero[83]); 
              escribir(address[41],num);
              _delay_ms(20); 
              readata=leer(address[41]);
              Serial.println(readata);
          }

          if(cont==86){
               num= (numero[84]*10)+(numero[85]); 
              escribir(address[42],num);
              _delay_ms(20); 
              readata=leer(address[42]);
              Serial.println(readata);
          }

           if(cont==88){
               num= (numero[86]*10)+(numero[87]); 
              escribir(address[43],num);
              _delay_ms(20); 
              readata=leer(address[43]);
              Serial.println(readata);
          }

          if(cont==90){
               num= (numero[88]*10)+(numero[89]); 
              escribir(address[44],num);
              _delay_ms(20); 
              readata=leer(address[44]);
              Serial.println(readata);
          }
          
          if(cont==92){
               num= (numero[90]*10)+(numero[91]); 
              escribir(address[45],num);
              _delay_ms(20); 
              readata=leer(address[45]);
              Serial.println(readata);
          }

           if(cont==94){
               num= (numero[92]*10)+(numero[93]); 
              escribir(address[46],num);
              _delay_ms(20); 
              readata=leer(address[46]);
              Serial.println(readata);
          }

           if(cont==96){
               num= (numero[94]*10)+(numero[95]); 
              escribir(address[47],num);
              _delay_ms(20); 
              readata=leer(address[47]);
              Serial.println(readata);
          }

          if(cont==98){
               num= (numero[96]*10)+(numero[97]); 
              escribir(address[48],num);
              _delay_ms(20); 
              readata=leer(address[48]);
              Serial.println(readata);
          }

          if(cont==100){
               num= (numero[98]*10)+(numero[99]); 
              escribir(address[49],num);
              _delay_ms(20); 
              readata=leer(address[49]);
              Serial.println(readata);
          }

           if(cont==102){
              
              num= (numero[100]*10)+(numero[101]);  
              escribir(address[50],num);
              _delay_ms(20); 
              readata=leer(address[50]);
              Serial.println(readata);
              
        }
         if(cont==104){
              num= (numero[102]*10)+(numero[103]); 
              escribir(address[51],num);
              _delay_ms(20); 
              readata=leer(address[51]);
              Serial.println(readata);
            
              
          }
         if(cont==106){
               num= (numero[104]*10)+(numero[105]); 
              escribir(address[52],num);
              _delay_ms(20); 
              readata=leer(address[52]);
              Serial.println(readata);
            
          }

          if(cont==108){
               num= (numero[106]*10)+(numero[107]); 
              escribir(address[53],num);
              _delay_ms(20); 
              readata=leer(address[53]);
              Serial.println(readata);
         
          }

          if(cont==110){
               num= (numero[108]*10)+(numero[109]); 
              escribir(address[54],num);
              _delay_ms(20); 
              readata=leer(address[54]);
              Serial.println(readata);
             
          }

          if(cont==112){
               num= (numero[110]*10)+(numero[111]); 
              escribir(address[55],num);
              _delay_ms(20); 
              readata=leer(address[55]);
              Serial.println(readata);
             
          }

          
          if(cont==114){
               num= (numero[112]*10)+(numero[113]); 
              escribir(address[56],num);
              _delay_ms(20); 
              readata=leer(address[56]);
              Serial.println(readata);
             
          }

          if(cont==116){
               num= (numero[114]*10)+(numero[115]); 
              escribir(address[57],num);
              _delay_ms(20); 
              readata=leer(address[57]);
              Serial.println(readata);
             
          }

          if(cont==118){
               num= (numero[116]*10)+(numero[117]); 
              escribir(address[58],num);
              _delay_ms(20); 
              readata=leer(address[58]);
              Serial.println(readata);
             
          }

           if(cont==120){
               num= (numero[118]*10)+(numero[119]); 
              escribir(address[59],num);
              _delay_ms(20); 
              readata=leer(address[59]);
              Serial.println(readata);
             
          }

          if(cont==122){
               num= (numero[120]*10)+(numero[121]); 
              escribir(address[60],num);
              _delay_ms(20); 
              readata=leer(address[60]);
              Serial.println(readata);
             
          }
            if(cont==124){
               num= (numero[122]*10)+(numero[123]); 
              escribir(address[61],num);
              _delay_ms(20); 
              readata=leer(address[61]);
              Serial.println(readata);
             
          }

             if(cont==126){
               num= (numero[124]*10)+(numero[125]); 
              escribir(address[62],num);
              _delay_ms(20); 
              readata=leer(address[62]);
              Serial.println(readata);
             
          }

          if(cont==128){
               num= (numero[126]*10)+(numero[127]); 
              escribir(address[63],num);
              _delay_ms(20); 
              readata=leer(address[63]);
              Serial.println(readata);
             
          }

            if(cont==130){
               num= (numero[128]*10)+(numero[129]); 
              escribir(address[64],num);
              _delay_ms(20); 
              readata=leer(address[64]);
              Serial.println(readata);  
          }

          if(cont==132){
               num= (numero[130]*10)+(numero[131]); 
              escribir(address[65],num);
              _delay_ms(20); 
              readata=leer(address[65]);
              Serial.println(readata);
             
          }

          if(cont==134){
               num= (numero[132]*10)+(numero[133]); 
              escribir(address[66],num);
              _delay_ms(20); 
              readata=leer(address[66]);
              Serial.println(readata);
             
          }

             if(cont==136){
               num= (numero[134]*10)+(numero[135]); 
              escribir(address[67],num);
              _delay_ms(20); 
              readata=leer(address[67]);
              Serial.println(readata);
             
          }

           if(cont==138){
               num= (numero[136]*10)+(numero[137]); 
              escribir(address[68],num);
              _delay_ms(20); 
              readata=leer(address[68]);
              Serial.println(readata);
          }
           if(cont==140){
               num= (numero[138]*10)+(numero[139]); 
              escribir(address[69],num);
              _delay_ms(20); 
              readata=leer(address[69]);
              Serial.println(readata);
          }
           if(cont==142){
               num= (numero[140]*10)+(numero[141]); 
              escribir(address[70],num);
              _delay_ms(20); 
              readata=leer(address[70]);
              Serial.println(readata);
          }

          if(cont==144){
               num= (numero[142]*10)+(numero[143]); 
              escribir(address[71],num);
              _delay_ms(20); 
              readata=leer(address[71]);
              Serial.println(readata);
          }

          if(cont==146){
               num= (numero[144]*10)+(numero[145]); 
              escribir(address[72],num);
              _delay_ms(20); 
              readata=leer(address[72]);
              Serial.println(readata);
          }

           if(cont==148){
               num= (numero[146]*10)+(numero[147]); 
              escribir(address[73],num);
              _delay_ms(20); 
              readata=leer(address[73]);
              Serial.println(readata);
          }

          if(cont==150){
               num= (numero[148]*10)+(numero[149]); 
              escribir(address[74],num);
              _delay_ms(20); 
              readata=leer(address[74]);
              Serial.println(readata);
          }
          if(cont==152){
               num= (numero[150]*10)+(numero[151]); 
              escribir(address[75],num);
              _delay_ms(20); 
              readata=leer(address[75]);
              Serial.println(readata);
          }

           if(cont==154){
               num= (numero[152]*10)+(numero[153]); 
              escribir(address[76],num);
              _delay_ms(20); 
              readata=leer(address[76]);
              Serial.println(readata);
          }

          if(cont==156){
               num= (numero[154]*10)+(numero[155]); 
              escribir(address[77],num);
              _delay_ms(20); 
              readata=leer(address[77]);
              Serial.println(readata);
          }

           if(cont==158){
               num= (numero[156]*10)+(numero[157]); 
              escribir(address[78],num);
              _delay_ms(20); 
              readata=leer(address[78]);
              Serial.println(readata);
          }

           if(cont==160){
               num= (numero[158]*10)+(numero[159]); 
              escribir(address[79],num);
              _delay_ms(20); 
              readata=leer(address[79]);
              Serial.println(readata);
          }

          if(cont==162){
               num= (numero[160]*10)+(numero[161]); 
              escribir(address[80],num);
              _delay_ms(20); 
              readata=leer(address[80]);
              Serial.println(readata);
          }

           if(cont==164){
               num= (numero[162]*10)+(numero[163]); 
              escribir(address[81],num);
              _delay_ms(20); 
              readata=leer(address[81]);
              Serial.println(readata);
          }

          if(cont==166){
               num= (numero[164]*10)+(numero[165]); 
              escribir(address[82],num);
              _delay_ms(20); 
              readata=leer(address[82]);
              Serial.println(readata);
          }

           if(cont==168){
               num= (numero[166]*10)+(numero[167]); 
              escribir(address[83],num);
              _delay_ms(20); 
              readata=leer(address[83]);
              Serial.println(readata);
          }

          if(cont==170){
               num= (numero[168]*10)+(numero[169]); 
              escribir(address[84],num);
              _delay_ms(20); 
              readata=leer(address[84]);
              Serial.println(readata);
          }

          if(cont==172){
               num= (numero[170]*10)+(numero[171]); 
              escribir(address[85],num);
              _delay_ms(20); 
              readata=leer(address[85]);
              Serial.println(readata);
          }

          
          if(cont==174){
               num= (numero[172]*10)+(numero[173]); 
              escribir(address[86],num);
              _delay_ms(20); 
              readata=leer(address[86]);
              Serial.println(readata);
          }

          if(cont==176){
               num= (numero[174]*10)+(numero[175]); 
              escribir(address[87],num);
              _delay_ms(20); 
              readata=leer(address[87]);
              Serial.println(readata);
          }

          if(cont==178){
               num= (numero[176]*10)+(numero[177]); 
              escribir(address[88],num);
              _delay_ms(20); 
              readata=leer(address[88]);
              Serial.println(readata);
          }

           if(cont==180){
               num= (numero[178]*10)+(numero[179]); 
              escribir(address[89],num);
              _delay_ms(20); 
              readata=leer(address[89]);
              Serial.println(readata);
          }
          if(cont==182){
               num= (numero[180]*10)+(numero[181]); 
              escribir(address[90],num);
              _delay_ms(20); 
              readata=leer(address[90]);
              Serial.println(readata);
          }

           if(cont==184){
               num= (numero[182]*10)+(numero[183]); 
              escribir(address[91],num);
              _delay_ms(20); 
              readata=leer(address[91]);
              Serial.println(readata);
          }

          if(cont==186){
               num= (numero[184]*10)+(numero[185]); 
              escribir(address[92],num);
              _delay_ms(20); 
              readata=leer(address[92]);
              Serial.println(readata);
          }

           if(cont==188){
               num= (numero[186]*10)+(numero[187]); 
              escribir(address[93],num);
              _delay_ms(20); 
              readata=leer(address[93]);
              Serial.println(readata);
          }

          if(cont==190){
               num= (numero[188]*10)+(numero[189]); 
              escribir(address[94],num);
              _delay_ms(20); 
              readata=leer(address[94]);
              Serial.println(readata);
          }
          
          if(cont==192){
               num= (numero[190]*10)+(numero[191]); 
              escribir(address[95],num);
              _delay_ms(20); 
              readata=leer(address[95]);
              Serial.println(readata);
          }

           if(cont==194){
               num= (numero[192]*10)+(numero[193]); 
              escribir(address[96],num);
              _delay_ms(20); 
              readata=leer(address[96]);
              Serial.println(readata);
          }

           if(cont==196){
               num= (numero[194]*10)+(numero[195]); 
              escribir(address[97],num);
              _delay_ms(20); 
              readata=leer(address[97]);
              Serial.println(readata);
          }

          if(cont==198){
               num= (numero[196]*10)+(numero[197]); 
              escribir(address[98],num);
              _delay_ms(20); 
              readata=leer(address[98]);
              Serial.println(readata);
          }

          if(cont==200){
               num= (numero[198]*10)+(numero[199]); 
              escribir(address[99],num);
              _delay_ms(20); 
              readata=leer(address[99]);
              Serial.println(readata);
          }

           if(cont==202){
              
              num= (numero[200]*10)+(numero[201]);  
              escribir(address[100],num);
              _delay_ms(20); 
              readata=leer(address[100]);
              Serial.println(readata);
              
        }
         if(cont==204){
              num= (numero[202]*10)+(numero[203]); 
              escribir(address[101],num);
              _delay_ms(20); 
              readata=leer(address[102]);
              Serial.println(readata);
             
              
          }
         if(cont==206){
               num= (numero[204]*10)+(numero[205]); 
              escribir(address[102],num);
              _delay_ms(20); 
              readata=leer(address[102]);
              Serial.println(readata);
              
          }

          if(cont==208){
               num= (numero[206]*10)+(numero[207]); 
              escribir(address[103],num);
              _delay_ms(20); 
              readata=leer(address[103]);
              Serial.println(readata);
            
          }

          if(cont==210){
               num= (numero[208]*10)+(numero[209]); 
              escribir(address[104],num);
              _delay_ms(20); 
              readata=leer(address[104]);
              Serial.println(readata);
              
          }

          if(cont==212){
               num= (numero[210]*10)+(numero[211]); 
              escribir(address[105],num);
              _delay_ms(20); 
              readata=leer(address[105]);
              Serial.println(readata);
             
          }

          
          if(cont==214){
               num= (numero[212]*10)+(numero[213]); 
              escribir(address[106],num);
              _delay_ms(20); 
              readata=leer(address[106]);
              Serial.println(readata);
             
          }

          if(cont==216){
               num= (numero[214]*10)+(numero[215]); 
              escribir(address[107],num);
              _delay_ms(20); 
              readata=leer(address[107]);
              Serial.println(readata);
             
          }

          if(cont==218){
               num= (numero[216]*10)+(numero[217]); 
              escribir(address[108],num);
              _delay_ms(20); 
              readata=leer(address[108]);
              Serial.println(readata);
             
          }

           if(cont==220){
               num= (numero[218]*10)+(numero[219]); 
              escribir(address[109],num);
              _delay_ms(20); 
              readata=leer(address[109]);
              Serial.println(readata);
             
          }

          if(cont==222){
               num= (numero[220]*10)+(numero[221]); 
              escribir(address[110],num);
              _delay_ms(20); 
              readata=leer(address[110]);
              Serial.println(readata);
             
          }
            if(cont==224){
               num= (numero[222]*10)+(numero[223]); 
              escribir(address[111],num);
              _delay_ms(20); 
              readata=leer(address[111]);
              Serial.println(readata);
             
          }

             if(cont==226){
               num= (numero[224]*10)+(numero[225]); 
              escribir(address[112],num);
              _delay_ms(20); 
              readata=leer(address[112]);
              Serial.println(readata);
             
          }

          if(cont==228){
               num= (numero[226]*10)+(numero[227]); 
              escribir(address[113],num);
              _delay_ms(20); 
              readata=leer(address[113]);
              Serial.println(readata);
             
          }

            if(cont==230){
               num= (numero[228]*10)+(numero[229]); 
              escribir(address[114],num);
              _delay_ms(20); 
              readata=leer(address[114]);
              Serial.println(readata);  
          }

          if(cont==232){
               num= (numero[230]*10)+(numero[231]); 
              escribir(address[115],num);
              _delay_ms(20); 
              readata=leer(address[115]);
              Serial.println(readata);
             
          }

          if(cont==234){
               num= (numero[232]*10)+(numero[233]); 
              escribir(address[116],num);
              _delay_ms(20); 
              readata=leer(address[116]);
              Serial.println(readata);
             
          }

             if(cont==236){
               num= (numero[234]*10)+(numero[235]); 
              escribir(address[117],num);
              _delay_ms(20); 
              readata=leer(address[117]);
              Serial.println(readata);
             
          }

           if(cont==238){
               num= (numero[236]*10)+(numero[237]); 
              escribir(address[118],num);
              _delay_ms(20); 
              readata=leer(address[118]);
              Serial.println(readata);
          }
           if(cont==240){
               num= (numero[238]*10)+(numero[239]); 
              escribir(address[119],num);
              _delay_ms(20); 
              readata=leer(address[119]);
              Serial.println(readata);
          }
           if(cont==242){
               num= (numero[240]*10)+(numero[241]); 
              escribir(address[120],num);
              _delay_ms(20); 
              readata=leer(address[120]);
              Serial.println(readata);
          }

          if(cont==244){
               num= (numero[242]*10)+(numero[243]); 
              escribir(address[121],num);
              _delay_ms(20); 
              readata=leer(address[121]);
              Serial.println(readata);
          }

          if(cont==246){
               num= (numero[244]*10)+(numero[245]); 
              escribir(address[122],num);
              _delay_ms(20); 
              readata=leer(address[122]);
              Serial.println(readata);
          }

           if(cont==248){
               num= (numero[246]*10)+(numero[247]); 
              escribir(address[123],num);
              _delay_ms(20); 
              readata=leer(address[123]);
              Serial.println(readata);
          }

          if(cont==250){
               num= (numero[248]*10)+(numero[249]); 
              escribir(address[124],num);
              _delay_ms(20); 
              readata=leer(address[124]);
              Serial.println(readata);
          }
          if(cont==252){
               num= (numero[250]*10)+(numero[251]); 
              escribir(address[125],num);
              _delay_ms(20); 
              readata=leer(address[125]);
              Serial.println(readata);
          }

           if(cont==254){
               num= (numero[252]*10)+(numero[253]); 
              escribir(address[126],num);
              _delay_ms(20); 
              readata=leer(address[126]);
              Serial.println(readata);
          }

          if(cont==256){
               num= (numero[254]*10)+(numero[255]); 
              escribir(address[127],num);
              _delay_ms(20); 
              readata=leer(address[127]);
              Serial.println(readata);
          }

           if(cont==258){
               num= (numero[256]*10)+(numero[257]); 
              escribir(address[128],num);
              _delay_ms(20); 
              readata=leer(address[128]);
              Serial.println(readata);
          }

           if(cont==260){
               num= (numero[258]*10)+(numero[259]); 
              escribir(address[129],num);
              _delay_ms(20); 
              readata=leer(address[129]);
              Serial.println(readata);
          }

          if(cont==262){
               num= (numero[260]*10)+(numero[261]); 
              escribir(address[130],num);
              _delay_ms(20); 
              readata=leer(address[130]);
              Serial.println(readata);
          }

           if(cont==264){
               num= (numero[262]*10)+(numero[263]); 
              escribir(address[131],num);
              _delay_ms(20); 
              readata=leer(address[131]);
              Serial.println(readata);
          }

          if(cont==266){
               num= (numero[264]*10)+(numero[265]); 
              escribir(address[132],num);
              _delay_ms(20); 
              readata=leer(address[132]);
              Serial.println(readata);
          }

           if(cont==268){
               num= (numero[266]*10)+(numero[267]); 
              escribir(address[133],num);
              _delay_ms(20); 
              readata=leer(address[133]);
              Serial.println(readata);
          }

          if(cont==270){
               num= (numero[268]*10)+(numero[269]); 
              escribir(address[134],num);
              _delay_ms(20); 
              readata=leer(address[134]);
              Serial.println(readata);
          }

          if(cont==272){
               num= (numero[270]*10)+(numero[271]); 
              escribir(address[135],num);
              _delay_ms(20); 
              readata=leer(address[135]);
              Serial.println(readata);
          }

          
          if(cont==274){
               num= (numero[272]*10)+(numero[273]); 
              escribir(address[136],num);
              _delay_ms(20); 
              readata=leer(address[136]);
              Serial.println(readata);
          }

          if(cont==276){
               num= (numero[274]*10)+(numero[275]); 
              escribir(address[137],num);
              _delay_ms(20); 
              readata=leer(address[137]);
              Serial.println(readata);
          }

          if(cont==278){
               num= (numero[276]*10)+(numero[277]); 
              escribir(address[138],num);
              _delay_ms(20); 
              readata=leer(address[138]);
              Serial.println(readata);
          }

           if(cont==280){
               num= (numero[278]*10)+(numero[279]); 
              escribir(address[139],num);
              _delay_ms(20); 
              readata=leer(address[139]);
              Serial.println(readata);
          }
          if(cont==282){
               num= (numero[280]*10)+(numero[281]); 
              escribir(address[140],num);
              _delay_ms(20); 
              readata=leer(address[140]);
              Serial.println(readata);
          }

           if(cont==284){
               num= (numero[282]*10)+(numero[283]); 
              escribir(address[141],num);
              _delay_ms(20); 
              readata=leer(address[141]);
              Serial.println(readata);
          }

          if(cont==286){
               num= (numero[284]*10)+(numero[285]); 
              escribir(address[142],num);
              _delay_ms(20); 
              readata=leer(address[142]);
              Serial.println(readata);
          }

           if(cont==288){
               num= (numero[286]*10)+(numero[287]); 
              escribir(address[143],num);
              _delay_ms(20); 
              readata=leer(address[143]);
              Serial.println(readata);
          }

          if(cont==290){
               num= (numero[288]*10)+(numero[289]); 
              escribir(address[144],num);
              _delay_ms(20); 
              readata=leer(address[144]);
              Serial.println(readata);
          }
          
          if(cont==292){
               num= (numero[290]*10)+(numero[291]); 
              escribir(address[145],num);
              _delay_ms(20); 
              readata=leer(address[145]);
              Serial.println(readata);
          }

           if(cont==294){
               num= (numero[292]*10)+(numero[293]); 
              escribir(address[146],num);
              _delay_ms(20); 
              readata=leer(address[146]);
              Serial.println(readata);
          }

           if(cont==296){
               num= (numero[294]*10)+(numero[295]); 
              escribir(address[147],num);
              _delay_ms(20); 
              readata=leer(address[147]);
              Serial.println(readata);
          }

          if(cont==298){
               num= (numero[296]*10)+(numero[297]); 
              escribir(address[148],num);
              _delay_ms(20); 
              readata=leer(address[148]);
              Serial.println(readata);
          }

          if(cont==300){
               num= (numero[298]*10)+(numero[299]); 
              escribir(address[149],num);
              _delay_ms(20); 
              readata=leer(address[149]);
              Serial.println(readata);
          }

           if(cont==302){
              
              num= (numero[300]*10)+(numero[301]);  
              escribir(address[150],num);
              _delay_ms(20); 
              readata=leer(address[150]);
              Serial.println(readata);
              
        }
         if(cont==304){
              num= (numero[302]*10)+(numero[303]); 
              escribir(address[151],num);
              _delay_ms(20); 
              readata=leer(address[151]);
              Serial.println(readata);
            
              
          }
         if(cont==306){
               num= (numero[304]*10)+(numero[305]); 
              escribir(address[152],num);
              _delay_ms(20); 
              readata=leer(address[152]);
              Serial.println(readata);
            
          }

          if(cont==308){
               num= (numero[306]*10)+(numero[307]); 
              escribir(address[153],num);
              _delay_ms(20); 
              readata=leer(address[153]);
              Serial.println(readata);
         
          }

          if(cont==310){
               num= (numero[308]*10)+(numero[309]); 
              escribir(address[154],num);
              _delay_ms(20); 
              readata=leer(address[154]);
              Serial.println(readata);
             
          }

          if(cont==312){
               num= (numero[310]*10)+(numero[311]); 
              escribir(address[155],num);
              _delay_ms(20); 
              readata=leer(address[155]);
              Serial.println(readata);
             
          }

          
          if(cont==314){
               num= (numero[312]*10)+(numero[313]); 
              escribir(address[156],num);
              _delay_ms(20); 
              readata=leer(address[156]);
              Serial.println(readata);
             
          }

          if(cont==316){
               num= (numero[314]*10)+(numero[315]); 
              escribir(address[157],num);
              _delay_ms(20); 
              readata=leer(address[157]);
              Serial.println(readata);
             
          }

          if(cont==318){
               num= (numero[316]*10)+(numero[317]); 
              escribir(address[158],num);
              _delay_ms(20); 
              readata=leer(address[158]);
              Serial.println(readata);
             
          }

           if(cont==320){
               num= (numero[318]*10)+(numero[319]); 
              escribir(address[159],num);
              _delay_ms(20); 
              readata=leer(address[159]);
              Serial.println(readata);
             
          }

          if(cont==322){
               num= (numero[320]*10)+(numero[321]); 
              escribir(address[160],num);
              _delay_ms(20); 
              readata=leer(address[160]);
              Serial.println(readata);
             
          }
            if(cont==324){
               num= (numero[322]*10)+(numero[323]); 
              escribir(address[161],num);
              _delay_ms(20); 
              readata=leer(address[161]);
              Serial.println(readata);
             
          }

             if(cont==326){
               num= (numero[324]*10)+(numero[325]); 
              escribir(address[162],num);
              _delay_ms(20); 
              readata=leer(address[162]);
              Serial.println(readata);
             
          }

          if(cont==328){
               num= (numero[326]*10)+(numero[327]); 
              escribir(address[163],num);
              _delay_ms(20); 
              readata=leer(address[163]);
              Serial.println(readata);
             
          }

            if(cont==330){
               num= (numero[328]*10)+(numero[329]); 
              escribir(address[164],num);
              _delay_ms(20); 
              readata=leer(address[164]);
              Serial.println(readata);  
          }

          if(cont==332){
               num= (numero[330]*10)+(numero[331]); 
              escribir(address[165],num);
              _delay_ms(20); 
              readata=leer(address[165]);
              Serial.println(readata);
             
          }

          if(cont==334){
               num= (numero[332]*10)+(numero[333]); 
              escribir(address[166],num);
              _delay_ms(20); 
              readata=leer(address[166]);
              Serial.println(readata);
             
          }

             if(cont==336){
               num= (numero[334]*10)+(numero[335]); 
              escribir(address[167],num);
              _delay_ms(20); 
              readata=leer(address[167]);
              Serial.println(readata);
             
          }

           if(cont==338){
               num= (numero[336]*10)+(numero[337]); 
              escribir(address[168],num);
              _delay_ms(20); 
              readata=leer(address[168]);
              Serial.println(readata);
          }
           if(cont==340){
               num= (numero[338]*10)+(numero[339]); 
              escribir(address[169],num);
              _delay_ms(20); 
              readata=leer(address[169]);
              Serial.println(readata);
          }
           if(cont==342){
               num= (numero[340]*10)+(numero[341]); 
              escribir(address[170],num);
              _delay_ms(20); 
              readata=leer(address[171]);
              Serial.println(readata);
          }

          if(cont==344){
               num= (numero[342]*10)+(numero[343]); 
              escribir(address[171],num);
              _delay_ms(20); 
              readata=leer(address[171]);
              Serial.println(readata);
          }

          if(cont==346){
               num= (numero[344]*10)+(numero[345]); 
              escribir(address[172],num);
              _delay_ms(20); 
              readata=leer(address[172]);
              Serial.println(readata);
          }

           if(cont==348){
               num= (numero[346]*10)+(numero[347]); 
              escribir(address[173],num);
              _delay_ms(20); 
              readata=leer(address[173]);
              Serial.println(readata);
          }

          if(cont==350){
               num= (numero[348]*10)+(numero[349]); 
              escribir(address[174],num);
              _delay_ms(20); 
              readata=leer(address[174]);
              Serial.println(readata);
          }
          if(cont==352){
               num= (numero[350]*10)+(numero[351]); 
              escribir(address[175],num);
              _delay_ms(20); 
              readata=leer(address[175]);
              Serial.println(readata);
          }

           if(cont==354){
               num= (numero[352]*10)+(numero[353]); 
              escribir(address[176],num);
              _delay_ms(20); 
              readata=leer(address[176]);
              Serial.println(readata);
          }

          if(cont==356){
               num= (numero[354]*10)+(numero[355]); 
              escribir(address[177],num);
              _delay_ms(20); 
              readata=leer(address[177]);
              Serial.println(readata);
          }

           if(cont==358){
               num= (numero[356]*10)+(numero[357]); 
              escribir(address[178],num);
              _delay_ms(20); 
              readata=leer(address[178]);
              Serial.println(readata);
          }

           if(cont==360){
               num= (numero[358]*10)+(numero[359]); 
              escribir(address[179],num);
              _delay_ms(20); 
              readata=leer(address[179]);
              Serial.println(readata);
          }

          if(cont==362){
               num= (numero[360]*10)+(numero[361]); 
              escribir(address[180],num);
              _delay_ms(20); 
              readata=leer(address[180]);
              Serial.println(readata);
          }

           if(cont==364){
               num= (numero[362]*10)+(numero[363]); 
              escribir(address[181],num);
              _delay_ms(20); 
              readata=leer(address[181]);
              Serial.println(readata);
          }

          if(cont==366){
               num= (numero[364]*10)+(numero[365]); 
              escribir(address[182],num);
              _delay_ms(20); 
              readata=leer(address[182]);
              Serial.println(readata);
          }

           if(cont==368){
               num= (numero[366]*10)+(numero[367]); 
              escribir(address[183],num);
              _delay_ms(20); 
              readata=leer(address[183]);
              Serial.println(readata);
          }

          if(cont==370){
               num= (numero[368]*10)+(numero[369]); 
              escribir(address[184],num);
              _delay_ms(20); 
              readata=leer(address[184]);
              Serial.println(readata);
          }

          if(cont==372){
               num= (numero[370]*10)+(numero[371]); 
              escribir(address[185],num);
              _delay_ms(20); 
              readata=leer(address[185]);
              Serial.println(readata);
          }

          
          if(cont==374){
               num= (numero[372]*10)+(numero[373]); 
              escribir(address[186],num);
              _delay_ms(20); 
              readata=leer(address[186]);
              Serial.println(readata);
          }

          if(cont==376){
               num= (numero[374]*10)+(numero[375]); 
              escribir(address[187],num);
              _delay_ms(20); 
              readata=leer(address[187]);
              Serial.println(readata);
          }

          if(cont==378){
               num= (numero[376]*10)+(numero[377]); 
              escribir(address[188],num);
              _delay_ms(20); 
              readata=leer(address[188]);
              Serial.println(readata);
          }

           if(cont==380){
               num= (numero[378]*10)+(numero[379]); 
              escribir(address[189],num);
              _delay_ms(20); 
              readata=leer(address[189]);
              Serial.println(readata);
          }
          if(cont==382){
               num= (numero[380]*10)+(numero[381]); 
              escribir(address[190],num);
              _delay_ms(20); 
              readata=leer(address[190]);
              Serial.println(readata);
          }

           if(cont==384){
               num= (numero[182]*10)+(numero[183]); 
              escribir(address[191],num);
              _delay_ms(20); 
              readata=leer(address[191]);
              Serial.println(readata);
          }

          if(cont==386){
               num= (numero[384]*10)+(numero[385]); 
              escribir(address[192],num);
              _delay_ms(20); 
              readata=leer(address[192]);
              Serial.println(readata);
          }

           if(cont==388){
               num= (numero[386]*10)+(numero[387]); 
              escribir(address[193],num);
              _delay_ms(20); 
              readata=leer(address[193]);
              Serial.println(readata);
          }

          if(cont==390){
               num= (numero[388]*10)+(numero[389]); 
              escribir(address[194],num);
              _delay_ms(20); 
              readata=leer(address[194]);
              Serial.println(readata);
          }
          
          if(cont==392){
               num= (numero[390]*10)+(numero[391]); 
              escribir(address[195],num);
              _delay_ms(20); 
              readata=leer(address[195]);
              Serial.println(readata);
          }

           if(cont==394){
               num= (numero[392]*10)+(numero[393]); 
              escribir(address[196],num);
              _delay_ms(20); 
              readata=leer(address[196]);
              Serial.println(readata);
          }

           if(cont==396){
               num= (numero[394]*10)+(numero[395]); 
              escribir(address[197],num);
              _delay_ms(20); 
              readata=leer(address[197]);
              Serial.println(readata);
          }

          if(cont==398){
               num= (numero[396]*10)+(numero[397]); 
              escribir(address[198],num);
              _delay_ms(20); 
              readata=leer(address[198]);
              Serial.println(readata);
          }

          if(cont==400){
               num= (numero[398]*10)+(numero[399]); 
              escribir(address[199],num);
              _delay_ms(20); 
              readata=leer(address[199]);
              Serial.println(readata);
          }

 
      break;

    case ESTADO3:
      i=0;
      while(i<200){
        readata=leer(address[i]);
        Serial.println(readata);
        i=i+1;
      }
     

      estado=ESTADO1;
       break;

    case ESTADO4:

        readata=leer(address[0]);
        Serial.println(readata);
       

      estado=ESTADO1;
       break;

    case ESTADO5: 
      nuevo[0]= incomingByte;
      char crc=(char)XORChecksum8(&dato[0],2);
      char crc2=(char)XORChecksum8(&nuevo[0],2);
      if(crc==crc2){
        
        Serial.println("Llego bien"); 

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
