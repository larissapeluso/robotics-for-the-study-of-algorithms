//Define as cores normais (contidas no datasheet do controlador)
#define BLACK 0
#define RED 0xE0
#define GREEN 0x1C
#define BLUE 0x03
#define ORANGE 0xFC
#define MAGENTA 0xE3
#define TEAL 0x1F
#define WHITE 0xFF

//Define os pinos do Arduino a serem conectados na matriz de LED
int saida = 10;
int entrada = 8;
int sclk = 12;
int cs = 11;

//Define as variáveis que precisam conter no programa
char cor_buffer [64]; //64 representa a quantidade de LEDs da matriz (8x8=64)

void setup() {
  //configuração SPI (representa os dados de entrada e saída da matriz de LED)
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1); //Habilita SPI em nível HIGH, Modo Master, e divide clock por 16

  //Define o modo do pino para a matriz RGB
  pinMode(saida, OUTPUT);
  pinMode(entrada, INPUT);
  pinMode(sclk,OUTPUT);
  pinMode(cs,OUTPUT);

  //Faz a matriz RGB estar desativada
  digitalWrite(cs,HIGH);
}

void loop() {
  //Carrega cores dentro da primeira linha de cor do buffer array.
  //Este é um array de cores definidas para a matriz RGB.
  cor_buffer[0]=BLACK; //primeiro valor do array inicia em 0
  cor_buffer[1]=RED;
  cor_buffer[2]=GREEN;
  cor_buffer[3]=BLUE;
  cor_buffer[4]=ORANGE;
  cor_buffer[5]=MAGENTA;
  cor_buffer[6]=TEAL;
  cor_buffer[7]=WHITE;

  //Ativação da matriz RGB
  digitalWrite(cs, LOW);
  //Envia a cor do buffer para a matriz RGB
  for(int LED=0; LED<64; LED++) {
    spi_transferencia(cor_buffer[LED]);
  }
  //Desativação da matriz RGB
  digitalWrite(cs, HIGH);
  while(1);
}

//Este comando é usado para enviar um único valor de cor para a matriz RGB (tem 64 valores de cores que são enviados para a matriz RGB)
char spi_transferencia(volatile char dado) {
  SPDR = dado; //Começa a transmissão
  while (!(SPSR & (1<<SPIF))) { //Espera até o fim da transmissão
  };
  return SPDR; // retorna o byte recebido
}

