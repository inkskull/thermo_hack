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
}

void pulse(char dir,int notif) {
  int  z= digitalRead(p1);
  Serial.print(z);
  for (int i=0; i==notif*2;i++){
    if (z==0){
      z=1;
      } else {
      z=0;
      }
    if (dir=="+") {
      digitalWrite(p1,z);
      delay(5000);
      digitalWrite(p2,z);
      delay(5000);
    } else {
      digitalWrite(p2,z);
      delay(5000);
      digitalWrite(p1,z);
      delay(5000);
    }
  }
}
  

void settemp(int temp) {
  int tt=temp*2-10;
  pulse("-",60);
  pulse("+",tt);
}

