//Commande un thermostat equiva en émulant son encodeur rotatif.



const int p1 = 3;
const int p2 = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(p1, OUTPUT);
pinMode(p2, OUTPUT);
Serial.begin(9600);
Serial.print("test");
}

void loop() {
  // put your main code here, to run repeatedly:
  settemp(15);
  delay(10000);
  settemp(20);
  delay(10000);
}

void pulse(char di,int notif) {
  int sigl=6;
  Serial.print("di : ");
  Serial.print(di);
  int  z= digitalRead(p1);
  Serial.print("z init : ");
  Serial.print(z);
  for (int i=0; i < notif*2; i++){
    if (z==0) {
      z=1;
      } else {
      z=0;
      };
    if (di=='+') {
      digitalWrite(p1,z);
      delay(sigl);
      digitalWrite(p2,z);
      delay(sigl);
    } else {
      digitalWrite(p2,z);
      delay(sigl);
      digitalWrite(p1,z);
      delay(sigl);
    }
  }
}
  

void settemp(int temp) {
  int tt=(temp*2)-10;
  Serial.print("tt :");
  Serial.print(tt);
  pulse('-',60);
  pulse('+',tt);
}

