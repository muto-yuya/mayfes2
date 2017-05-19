int leftHP    = 4;
int rightHP   = 5;
int vrefHP    = 3;  
int openTime   = 280;
int closeTime  = 330;
int leftKP    = 12;
int rightKP   = 13;
int vrefKP    = 11;  
int upTime   = 2000;
int downTime = 1000;
int riseLevel = 0;

void setup() {
pinMode(leftHP, OUTPUT);
pinMode(rightHP, OUTPUT);
pinMode(vrefHP, OUTPUT);
pinMode(leftKP, OUTPUT);
pinMode(rightKP, OUTPUT);
pinMode(vrefKP, OUTPUT);
Serial.begin(9600);
//リファレンス電圧
digitalWrite(vrefHP, HIGH);
digitalWrite(vrefKP, HIGH);

digitalWrite(rightKP, LOW);
digitalWrite(leftKP, LOW);
digitalWrite(rightHP, LOW);
digitalWrite(leftHP, LOW);
}
void loop() {
int inputchar;
 
  // シリアルポートより1文字読み込む
  inputchar = Serial.read();
 
  if(inputchar != -1 ){
    // 読み込んだデータが -1 以外の場合　以下の処理を行う
 
    switch(inputchar){
      //成長
      case 'a':
        Serial.print("kuki Up\n");
        if(riseLevel < 2){
          kukiUp();
          riseLevel += 1;
        }
        else if(riseLevel == 2){
          hanaOpen();
          riseLevel += 1;
        }
        break;
      //茎を下げる
      case 'b':  
        Serial.print("kuki Down\n");
        kukiDown();
        break;
      //花を開ける
      case 'c':  
        Serial.print("haba Open\n");
        hanaOpen();
        break;
      //花を閉じる
      case 'd':  
        Serial.print("haba Close\n");
        hanaClose();
        break;
       //リセット
      case 'r':  
        Serial.print("RESET\n");
        riseLevel = 0;
        break;
      //緊急停止
      case 'q':  
        Serial.print("STOP!!!!!\n");
        stopAll();
        break;
      //少し茎あげる
      case 'e':  
        Serial.print("kuki Up Short\n");
        kukiUpShort();
        break;
      //少し茎下げる
      case 'f':  
        Serial.print("kuki Down Short\n");
        kukiDownShort();
        break;
      //花を少し開ける
      case 'g':  
        Serial.print("haba Open Short\n");
        hanaOpenShort();
        break;
      //花を少し閉じる
      case 'h':  
        Serial.print("haba Close Short\n");
        hanaCloseShort();
        break;

    }
  } else {
    // 読み込むデータが無い場合は何もしない
  }
}

void kukiUp(){
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, HIGH);
  delay(upTime/2);
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, LOW);
}

void kukiDown(){
  digitalWrite(rightKP, HIGH);
  digitalWrite(leftKP, LOW);
  delay(downTime);
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, LOW);
  delay(200);
}

void kukiUpShort(){
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, HIGH);
  delay(100);
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, LOW);
  delay(200);
}

void kukiDownShort(){
  digitalWrite(rightKP, HIGH);
  digitalWrite(leftKP, LOW);
  delay(100);
  digitalWrite(rightKP, LOW);
  digitalWrite(leftKP, LOW);
  delay(200);
}

void hanaOpen(){
  digitalWrite(rightHP, HIGH);
  digitalWrite(leftHP, LOW);
  delay(openTime);
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, LOW);
  delay(200);
}

void hanaClose(){
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, HIGH);
  delay(closeTime);
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, LOW);
  delay(200);
}

void hanaOpenShort(){
  digitalWrite(rightHP, HIGH);
  digitalWrite(leftHP, LOW);
  delay(100);
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, LOW);
  delay(200);
}

void hanaCloseShort(){
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, HIGH);
  delay(100);
  digitalWrite(rightHP, LOW);
  digitalWrite(leftHP, LOW);
  delay(200);
}

void stopAll(){
    digitalWrite(rightKP, LOW);
    digitalWrite(leftKP, LOW);
    digitalWrite(rightHP, LOW);
    digitalWrite(leftHP, LOW);
    while(1){
  delay(1000);
}
}

void testLED(){
  digitalWrite(13,HIGH);
  delay(1000);
}

