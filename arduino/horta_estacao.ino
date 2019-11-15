//biblioteca para objetos json
#include <ArduinoJson.h>

//biblioteca para servomotor
#include <Servo.h>
Servo servo1;//cria o objeto servo
//biblioteca rtc
#include <DS1307.h>
// Inicia o DS1307
DS1307 rtc(A4, A5);

//porta serial virtual
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

//pino do servo
#define pin_servo1 9
//pino do relé da solenoide
#define pin_solenoide 6

//pinos analogicos
#define pin_lum A0
#define pin_temp A1
#define pin_chuva A2

//pino da buzzina 
#define pin_buzz 8

void setup() {

mySerial.begin(9600);

//configura pinos analogicos
pinMode(pin_lum,INPUT);
pinMode(pin_temp,INPUT);
pinMode(pin_chuva,INPUT);

//configura os pinos digitais da rega
pinMode(pin_servo1,OUTPUT);
pinMode(pin_solenoide,OUTPUT);
digitalWrite(pin_solenoide,1);//o relé é desligado em nivel alto  
pinMode(pin_buzz,OUTPUT);//pinos da buzzina
digitalWrite(pin_buzz,0);

  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) continue;


  //inicializacao do rtc
  rtc.halt(false);
  
  //As linhas abaixo setam a data e hora do modulo
  //e podem ser comentada apos a primeira utilizacao
  //rtc.setDOW(FRIDAY);      //Define o dia da semana
  //rtc.setTime(20, 37, 0);     //Define o horario
  //rtc.setDate(6, 6, 2014);   //Define o dia, mes e ano
  
  //Definicoes do pino SQW/Out
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);
  


  char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";
//{"sensor":"gps","time":1351824120,"data":[48.756080,2.302038]}
  
}

void loop() {
verificar_serial();
 
}
