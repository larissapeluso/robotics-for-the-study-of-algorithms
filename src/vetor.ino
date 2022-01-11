//define constante para cada nota musical
#define DO 261
#define RE 294
#define MI 329
#define FA 349
#define SOL 392
#define LA 440
#define SI 493

//define o pino 11 a ser utilizado na placa
int pino = 11;
//cria um vetor com todas as 7 notas musicais
int notas_musicais[] = {DO, RE, MI, FA, SOL, LA, SI};
//cria um vetor com a duração de cada uma das 7 notas musicais
int duracaodecadanota[] = {100,100,100,100,100,100,100};

void setup() {
  //"for" utilizado para garantir que as 7 notas sejam tocadas, começando no 0 até 7
  for (int nota_musical = 0; nota_musical < 7; nota_musical++) { //enquanto o valor for menor que 7, incrementa-se o contador
    //atribui um tempo de duração para cada nota musical
    int duracao_nota = duracaodecadanota[nota_musical];
    //gera o som no pino
    tone(pino, notas_musicais[nota_musical], duracao_nota);
    //pausa depois das notas
    int pausa_nota_musical[] = {1000,1000,1000,1000,1000,1000,1000};
    delay(pausa_nota_musical[nota_musical]);
  }
}

void loop() {
}
