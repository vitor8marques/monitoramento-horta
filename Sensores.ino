void leituraSensores(int amostras, int amostragem){
  /*funcao para realizar leitura de chuva,humidade e luminosidade
   *recebe o numero de amostras  que devem ser tomadas e o periodo de amostragem em ms 
   *esta funcao filtra os dados para que sejam entre 3 e 100 amostras e 10 a 100ms de amostragem
   */
   double luminosidade=0,temperatura=0,chuva=0; 
   int indice=0;
    
   //filtra os dados recebidos
   if(amostras<3){amostras=3;}
   if(amostras>100){amostras=100;}
   if(amostragem<10){amostragem=10;}
   if(amostragem>100){amostragem=100;}

for(indice=0;indice<amostras;indice++){//loop para coletar os dados
  
  luminosidade+=analogRead(pin_lum);
  temperatura+=analogRead(pin_temp);
  chuva+=analogRead(pin_chuva);

  delay(amostragem);
  }
  
  luminosidade=luminosidade/amostras;
  temperatura=temperatura/amostras;
  chuva=chuva/amostras;
//cria o objeto Json

StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
root["modo"] = "sensores"; 
root["lum"] = int(luminosidade);
root["temp"] = int(temperatura);
root["chuva"] = int(chuva); 
root["Status"] = "OK";//status
root.printTo(mySerial);
  } 
