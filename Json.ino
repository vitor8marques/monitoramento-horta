void verificar_serial(){
   String dados_serial="";
     //Serial.println("enviando dados");


     while (mySerial.available())  //verifica se tem dados diponível para leitura
  {
    dados_serial += mySerial.readString(); //le byte mais recente no buffer da serial
  }

if (dados_serial != ""){
  Serial.println(dados_serial);
  StaticJsonBuffer<200> jsonBuffer; 
  JsonObject& root = jsonBuffer.parseObject(dados_serial);

  // Test if parsing succeeds.
  if (!root.success()) {
  // mySerial.println("parseObject() failed");
  mySerial.println("");
    return;
  }



//{"buzz":"3","TonB":"300","ToffB":"250"}
  buzina(root["buzz"],root["TonB"],root["ToffB"]);


if(root["comando"]=="sensores"){
//{"comando":"sensores","amostras":"3","amostragem":"25"}
leituraSensores(root["amostras"],root["amostragem"]);

}else if(root["comando"]=="rega"){
//{"comando":"rega","ini":"25","fim":"100","tmp":"25","rpt":"3"}
regar( root["ini"], root["fim"], root["tmp"], root["rpt"]);
}else if(root["comando"]=="relogio_e"){
//{"comando":"relogio_e","d":14,"m":7,"a":2018,"H":19,"M":58,"s":13}
gravarHora(root["d"],root["m"],root["a"],root["H"],root["M"],root["s"],root["ds"]);
}else if(root["comando"]=="relogio_l"){
//{"comando":"relogio_l"}
lerHora();  
}else{
   // mySerial.println("comando nao encontrado");
}
}
}

  

