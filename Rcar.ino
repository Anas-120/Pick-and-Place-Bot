#include<Servo.h>

Servo shoulder, wrist, gripper;

//Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 6;
int in3 = 4;
int in4 = 5;

int command;

void setup() {
  shoulder.attach(3);
  wrist.attach(10);
  gripper.attach(11);

  shoulder.write(90);
  wrist.write(90);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    command=Serial.read();
    Serial.println(command);
    switch(command)
    {
      case 201:
        forward();
        break;
      case 202:
        backward();
        break;
      case 203:
        left();
        break;
      case 204:
        right();
        break;
      case 205:
        Stop();
        break;
      case 206:
        shup();
        break;  
      case 207:
        shdwn();
        break;  
      case 208:
        wrup();
        break;  
      case 209:
        wrdwn();
        break;
      case 210:
        shstop();
        break;                                                                      
      case 211:
        wrstop();
        break;
      default:
        gripperc();
        break;   
    }
  }
}
void forward() {
  
  analogWrite(enA, 180);
  analogWrite(enB, 180);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void backward() {
  
  analogWrite(enA, 180);
  analogWrite(enB, 180);

  // Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void left() {
  
  analogWrite(enA, 150);
  analogWrite(enB, 150);

  // Turn on motor A & B
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void right() {
  
  analogWrite(enA, 150);
  analogWrite(enB, 150);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}  
void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}       
void shup(){
  shoulder.write(80);
}
void shdwn(){
  shoulder.write(110);
}
void wrup(){
  wrist.write(80);
}
void wrdwn(){
  wrist.write(110);
}
void shstop(){
  shoulder.write(90);
}
void wrstop(){
  wrist.write(90);
}
void gripperc(){
  gripper.write(120-command);
}
