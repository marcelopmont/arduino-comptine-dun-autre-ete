#define nota_do       262
#define nota_do_sus   277
#define nota_re	      294
#define nota_re_sus   311
#define nota_mi       330
#define nota_fa       349
#define nota_fa_sus   370
#define nota_sol      392
#define nota_sol_sus  415
#define nota_la       440
#define nota_la_sus   466
#define nota_si       494

#define nota_DO       523
#define nota_DO_sus   554
#define nota_RE       587
#define nota_RE_sus   622
#define nota_MI	      659
#define nota_FA       698
#define nota_FA_sus   740
#define nota_SOL      784
#define nota_SOL_sus  831
#define nota_LA	      880
#define nota_LA_sus   932
#define nota_SI       988

#define coracao_1  2
#define coracao_2  3
#define coracao_3  4
#define coracao_4  5
#define coracao_5  6
#define luz_1      7
#define luz_2      8
#define luz_3      9
#define luz_4      11  // o 10 é o buzzer

int tempo=3000;  // tempo da semibreve
int luz_dentro=0;
int i;
int linha_apagada=0;// linha do coração que está sendo apagada

void comptine();
void inverte_luz();
void apaga_luz();
void apaga_luz_lateral();

void rotaciona_linha(); // apaga uma das linhas do coração


void setup() {
  pinMode(coracao_1,OUTPUT);
  pinMode(coracao_2,OUTPUT);
  pinMode(coracao_3,OUTPUT);
  pinMode(coracao_4,OUTPUT);
  pinMode(coracao_5,OUTPUT);
  pinMode(luz_1,OUTPUT);
  pinMode(luz_2,OUTPUT);
  pinMode(luz_3,OUTPUT);
  pinMode(luz_4,OUTPUT);
  pinMode(10,OUTPUT); //Pino do buzzer
  
  digitalWrite(coracao_1,HIGH);
  digitalWrite(coracao_2,HIGH);
  digitalWrite(coracao_3,HIGH);
  digitalWrite(coracao_4,HIGH);
  digitalWrite(coracao_5,HIGH);
  digitalWrite(luz_1,HIGH);
  digitalWrite(luz_2,HIGH);
  digitalWrite(luz_3,HIGH);
  digitalWrite(luz_4,HIGH);
  
  digitalWrite(coracao_1,LOW);
  digitalWrite(coracao_2,LOW);
  digitalWrite(coracao_3,LOW);
  digitalWrite(coracao_4,LOW);
  digitalWrite(coracao_5,LOW);
  digitalWrite(luz_1,LOW);
  digitalWrite(luz_2,LOW);
  digitalWrite(luz_3,LOW);
  digitalWrite(luz_4,LOW);
}

void loop()
{
  comptine();   
}
  
void inverte_luz(){
  if(luz_dentro==1){
    luz_dentro=0;
    digitalWrite(luz_1,HIGH);
    digitalWrite(luz_2,LOW);
    digitalWrite(luz_3,LOW);
    digitalWrite(luz_4,HIGH);
  }
  else{
    luz_dentro=1;
    digitalWrite(luz_1,LOW);
    digitalWrite(luz_2,HIGH);
    digitalWrite(luz_3,HIGH);
    digitalWrite(luz_4,LOW);
  }
}

void apaga_luz(){
  digitalWrite(luz_1,LOW);
  digitalWrite(luz_2,LOW);
  digitalWrite(luz_3,LOW);
  digitalWrite(luz_4,LOW);
}

void acende_luz(){
  digitalWrite(luz_1,HIGH);
  digitalWrite(luz_2,HIGH);
  digitalWrite(luz_3,HIGH);
  digitalWrite(luz_4,HIGH);
}

void apaga_luz_lateral(){
  digitalWrite(luz_1,LOW);
  digitalWrite(luz_2,HIGH);
  digitalWrite(luz_3,HIGH);
  digitalWrite(luz_4,LOW);
}

void rotaciona_linha(){
  linha_apagada++;
  if(linha_apagada>4){
    linha_apagada=1;
  }
  switch(linha_apagada){
    case 1:
      digitalWrite(coracao_1,LOW);
      digitalWrite(coracao_4,HIGH);
      break;
    case 2:
      digitalWrite(coracao_1,HIGH);
      digitalWrite(coracao_2,LOW);
      break;
    case 3:
      digitalWrite(coracao_2,HIGH);
      digitalWrite(coracao_3,LOW);
      digitalWrite(coracao_5,LOW);
      break;
    case 4:
      digitalWrite(coracao_3,HIGH);
      digitalWrite(coracao_4,LOW);
      digitalWrite(coracao_5,HIGH);
  }
}

void comptine(){
  // Lembrando que o fa é sustenido
  
  linha_apagada=0;
  digitalWrite(coracao_1,HIGH);
  digitalWrite(coracao_2,HIGH);
  digitalWrite(coracao_3,HIGH);
  digitalWrite(coracao_4,HIGH);
  digitalWrite(coracao_5,HIGH);
  for(i=0;i<2;i++){
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_sol,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_sol,tempo/8);
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_DO,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_si,tempo/2);
    delay(tempo/2);
    
    apaga_luz();
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_sol,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/8);
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_sol,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_sol,tempo/2);
    delay(tempo/2);
    
    apaga_luz();
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_mi,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/8);
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_DO,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_si,tempo/2);
    delay(tempo/2);
    
    apaga_luz();
    delay(tempo/8);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_mi,tempo/16);
    delay(tempo/16);
    inverte_luz();
    tone(10,nota_fa_sus,tempo/2);
    delay(tempo/2);
  }
  
  // Terceira linha
  acende_luz();
  tone(10,nota_MI,tempo/3);
  delay(tempo/3);
  apaga_luz();
  tone(10,nota_si,tempo/2);
  delay(tempo/2);
  
  acende_luz();
  tone(10,nota_RE,tempo/3);
  delay(tempo/3);
  apaga_luz();
  tone(10,nota_si,tempo/2);
  delay(tempo/2);
  
  acende_luz();
  tone(10,nota_FA_sus,tempo/3);
  delay(tempo/3);
  apaga_luz();
  tone(10,nota_si,tempo/2);
  delay(tempo/2);
  
  acende_luz();
  tone(10,nota_FA_sus,tempo/3);
  delay(tempo/3);
  apaga_luz();
  tone(10,nota_si,tempo/2);
  delay(tempo/2);
    
  // Quarta linha
  acende_luz();
  tone(10,nota_SOL,tempo/3);
  delay(tempo/3);
  apaga_luz_lateral();
  tone(10,nota_MI,tempo/2);
  delay(tempo/2);
    
  acende_luz();
  tone(10,nota_SOL,tempo/3);
  delay(tempo/3);
  apaga_luz_lateral();
  tone(10,nota_RE,tempo/2);
  delay(tempo/2);
  
  acende_luz();
  tone(10,nota_FA_sus,tempo/3);
  delay(tempo/3);
  apaga_luz_lateral();
  tone(10,nota_RE,tempo/2);
  delay(tempo/2);
  
  acende_luz();
  tone(10,nota_FA_sus,tempo/3);
  delay(tempo/3);
  apaga_luz_lateral();
  tone(10,nota_RE,tempo/2);
  delay(tempo/2);
  
  // 2ª página, quando a musica começa a ficar agitada
  for(i=0;i<2;i++){
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_DO,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_MI,tempo/16);
    delay(tempo/16);
    
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_SI,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    acende_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    apaga_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    
    // Segunda linha
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_FA_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_FA_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_FA_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_FA_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_fa_sus,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_sol,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_si,tempo/16);
    delay(tempo/16);
    
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_LA,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_LA,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_LA,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_LA,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_la,tempo/16);
    delay(tempo/16);
    inverte_luz();
    rotaciona_linha();
    tone(10,nota_RE,tempo/16);
    delay(tempo/16);
    
    if(i==0){
      inverte_luz();
      rotaciona_linha();
      tone(10,nota_si,tempo/16);
      delay(tempo/16);
      inverte_luz();
      rotaciona_linha();
      tone(10,nota_RE,tempo/16);
      delay(tempo/16);
    }
    else{
      acende_luz();
      rotaciona_linha();
      tone(10,nota_LA,tempo/8);
      delay(tempo/8);
    }
  }
  
}
