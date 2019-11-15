void buzina(int quantidade,int tempoON,int tempoOFF ){
  //funcao para buzzinar,quando o valor for maior que zero ele buzzina a quantidade indicada
  //assim se for especificada a quantidade 0 ou se nao for passado o parametro buzz nao vai buzzinar
  //a variavel tempo indica o tempo que vai ficar ligada/desligada
  if(tempoON<10 or tempoON>700){tempoON=500;}
  if(tempoOFF<10 or tempoOFF>700){tempoOFF=500;}
  
if (quantidade>0){
 if (quantidade>10){quantidade=10;}
  for(;quantidade>0;quantidade--){
    delay(tempoOFF); 
    digitalWrite(pin_buzz,1);
    delay(tempoON);
    digitalWrite(pin_buzz,0);
    }  
    //mySerial.println("{\"Status\":\"OK\"}");
  }

  }

void lerHora(){
  StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

Time t;
t=rtc.getTime();

root["d"] = t.date;//dia 
root["m"] = t.mon;//mes
root["a"] = t.year;//ano
root["H"] = t.hour;//hora
root["M"] = t.min;//minuto
root["s"] = t.sec;//segundo
root["ds"] = t.dow;//dia da semana
root["Status"] = "OK";//status
root.printTo(mySerial);
  }

void gravarHora(int dia,int mes,int ano,int hora,int minuto,int segundo,int diaSemana){
  if((dia>0)and(dia<32)){
    if((mes>0)and(mes<13)){
        
          if((hora>0)and(hora<24)){
            if((minuto>0)and(minuto<60)){
              if((segundo>0)and(segundo<60)){

                  rtc.setTime(hora,minuto,segundo);     //Define o horario
                  rtc.setDate(dia,mes,ano);   //Define o dia, mes e ano
                  
                  if((diaSemana>1)and(diaSemana<7)){
                  rtc.setDOW(diaSemana); 
                 }
                 mySerial.println("{\"Status\":\"OK\"}");
              }
            }
          }
        
      }  
   }
  
  }

