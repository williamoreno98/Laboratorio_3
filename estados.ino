int incomingByte = 0; // for incoming serial data
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

int estado=ESTADO0;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
int n=0;
void loop() {
  // send data only when you receive data:
  
  switch(estado){

    case ESTADO0:
         
         Serial.write(4);
         
        //if(Serial.available()>0){
        
          incomingByte = Serial.read();
         Serial.print("I received: ");
         Serial.println(incomingByte, DEC);
         estado= ESTADO1;
        //}
       estado= ESTADO0; 
       break;
    case ESTADO1:
       break;
     }
}
  
