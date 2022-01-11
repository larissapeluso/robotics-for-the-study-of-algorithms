int ledAmarelo = 4; //declara a variável ledAmarelo, atribuindo o valor 4, que corresponde ao pino a ser conectado na placa
int pinoBotao = 5; //declara a variável pinoBotao, atribuindo o valor 5, que corresponde ao pino a ser conectado na placa

int estadoBotao = 0; //declara e inicializa a variável estadoBotao com o valor 0

void setup() {
  pinMode(ledAmarelo, OUTPUT); //define o ledAmarelo como dado de saída (OUTPUT)
  pinMode(pinoBotao, INPUT_PULLUP); //define o pinoBotao como dado de entrada do tipo INPUT_PULLUP
}

void loop() {
  estadoBotao = digitalRead(pinoBotao); //faz a leitura do estadoBotao em pinoBotao
  //ledAmarelo permanece apagado (LOW) enquanto não for pressionado o botão
  if(estadoBotao == LOW) { //verifica se estadoBotao não mudou (se foi pressionado)
    digitalWrite(ledAmarelo, HIGH); //acende ledAmarelo
  }else{
    digitalWrite(ledAmarelo, LOW); //apaga ledAmarelo
  }
}
