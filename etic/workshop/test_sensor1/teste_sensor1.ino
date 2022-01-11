#include <Ultrasonic.h>
#define echoPin 13 //Pino 13 recebe o pulso do echo
#define trigPin 12 //Pino 12 envia o pulso para gerar o echo
//iniciando a função e passando os pinos
Ultrasonic ultrasonic(12,13);
int buz = 8;   //define variavel buz como pino 8
 
void setup()
{
   Serial.begin(9600); //inicia a porta serial
   pinMode(buz,OUTPUT);//define buz como saida digital
   pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)
   pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
}
 
void loop()
{
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
    digitalWrite(trigPin, LOW);
  // delay de 2 microssegundos
    delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
    digitalWrite(trigPin, HIGH);
  //delay de 10 microssegundos
    delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
    digitalWrite(trigPin, LOW);
  // função Ranging, faz a conversão do tempo de
  //resposta do echo em centimetros, e armazena
  //na variavel distancia
    int distancia = (ultrasonic.Ranging(CM));
  if (distancia < 50){
  tone(buz,2999,800);// esta linha de código é usada especialmente para o buzzer
//O seu funcionamento é : o pino(buz = 8), a frequência e o tempo de duração em milissegundos
//delay (ms)
delay(1000);
}

delay(1000); //espera 1 segundo para fazer a leitura novamente
}
