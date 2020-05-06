import serial, time

import matplotlib.pyplot as plt
import numpy as np


arduino = serial.Serial(port='COM4', baudrate=9600, bytesize=8)

numeros=[ 512 ,576 ,639 ,700 ,758, 812 ,862, 906, 943, 974 ,998 ,1014 , 
         1022  ,1022 , 1014 , 998 ,974, 943 ,906 ,862 ,812 ,758 ,700, 
         639, 576 ,512 ,448 ,385 ,324 ,266, 212, 162, 118 ,81 , 50 , 26 , 
         10 , 2 ,2, 10 , 26 , 50 , 81 , 118, 162, 212, 266, 324, 385, 448]



listaenvio=[0 for x in range(2000)]
grafica=[0 for x in range(1000)]
    
i=0
j=0


while(i<=99):

    b=numeros[j]
    
    if(b/10000 >=1):
        a=int(b/10000)
        c=a%10
        listaenvio[i]=c
    else: 
        listaenvio[i]=0
    
    if(b/1000 >=1):
        a=int(b/1000)
        c=a%10
        listaenvio[i+1]=c
    else: 
        listaenvio[i+1]=0
        
    
    if(b/100 >=1):
        a=int(b/100)
        c=a%10
        listaenvio[i+2]=c
    else: 
        listaenvio[i+2]=0
   
  
    if(b/10 >=1):
        a=int(b/10)
        c=a%10
        listaenvio[i+3]=c
    else: 
        listaenvio[i+3]=0
        
    c=b%10
    listaenvio[i+4]=c
    i=i+5
    j=j+1
    



i=0
j=0
h=1

# iniciar    
time.sleep(2)
arduino.write(b'#')
time.sleep(2)
rawString = arduino.readline()
print(rawString)
time.sleep(2)

# entra a opcion de escritura 

arduino.write(b'1')
time.sleep(2)
rawString = arduino.readline()
print(rawString)
    
#Envia 1000 datos del vector numeros
    
while(h<=20):    
        
    #enviando los datos
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)

    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
        
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    # numero 2
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    

    #numero 3
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    # numero 4
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
     #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 5
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 6
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
     #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    
    #numero 7
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 8
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 9
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 10
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    
    #numero 11
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 12
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 13
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 14
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 15
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 16
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 17
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 18
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 19
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 20
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 21
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 22
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 23
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 24
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'9')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 25
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'7')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 26
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 27
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 28
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 29
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 30
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 31
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 32
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 33
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    
    #numero 34
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    
    #numero 35
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 36
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 37
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 38
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 39
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 40
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 41
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 42
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 43
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 44
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 45
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 46
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'1')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 47
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'6')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 48
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'2')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 49
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'3')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'5')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    
    #numero 50
    
    arduino.write(b'0')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #guarda lo que lee de memoria
    listaenvio[i]=int(rawString)
    
    arduino.write(b'4')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    arduino.write(b'8')
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    rawString = arduino.readline()
    print(rawString)
    time.sleep(2)
    
    #lee lo que llega de memoria y crea un vector
    listaenvio[i+1]=int(rawString)
    grafica[j]=(listaenvio[i]*100)+listaenvio[i+1]
    j=j+1
    i=i+2
    h=h+1
    

if(h==21):
    plt.plot(grafica)
    # Show the plot
    plt.show()
    arduino.close()



    