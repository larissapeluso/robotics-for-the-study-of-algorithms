int ledPin = 2; //declara a variável ledPin, atribuindo o valor 2, que corresponde ao pino a ser conectado na placa

void setup() {
  // define ledPin como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (contador = 0; contador < 10; contador++) { //enquanto o contador não for = 10, repete o que está dentro do laço de repetição
    digitalWrite(ledPin, HIGH); //define ledPin como nível alto (ligado)
    delay(1000); //espera 1 segundo
    digitalWrite(ledPin, LOW); //define ledPin como nível baixo (desligado)
    delay(1000); //espera 1 segundo
    contador = contador + 1; //incrementa o contador em 1 a cada repetição do processo até chegar a 10
  }
}
