void regar( int anguloInicial, int anguloFinal, int velocidadeAngular,int repetir){
/*funcao para realizar as regas
 * recebe o angulo inicial do servo, o angulo final e o tempo que deve durar cada mudança de grau
 * filtra os dados para que o angulo final seja maior que o inicial (caso nao seja ele troca um com outro) e seus valores sejam entre 1 e 180
 * e a velocidade angular entre 10 e 40 e as repeticoes entre 1 e 10
 */

//filtra os dados
   if((anguloInicial<0) or (anguloInicial>180)){anguloInicial=10;}
   if((anguloFinal<0) or (anguloFinal>180)){anguloFinal=80;}
   if(velocidadeAngular<10){velocidadeAngular=10;}
   if(velocidadeAngular>40){velocidadeAngular=40;}
   if(repetir<1){repetir=1;}
   if(repetir>10){repetir=10;}


      
   if(anguloInicial>anguloFinal){
    int aux=anguloInicial;
    anguloInicial=anguloFinal;
    anguloFinal=aux;
    }
    
/*Serial.println(anguloInicial);
Serial.println(anguloFinal);
Serial.println(velocidadeAngular);
Serial.println(repetir);
Serial.println();
*/
  servo1.attach(pin_servo1);//liga o motor e o relé
  digitalWrite(pin_solenoide,0);

for (int i =0;i<repetir;i++){
  for (int pos = anguloInicial; pos <= anguloFinal; pos += 1) {
    servo1.write(pos);
    delay(velocidadeAngular);                            
  }
  
  for (int pos = anguloFinal; pos >= anguloInicial; pos -= 1) {
    servo1.write(pos); 
    delay(velocidadeAngular);                           
  }

}

  servo1.detach();//desliga o motor e o relé
  digitalWrite(pin_solenoide,1);
mySerial.println("{\"Status\":\"OK\"}");
  
  }
