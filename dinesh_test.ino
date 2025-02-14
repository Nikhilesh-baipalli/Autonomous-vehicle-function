#include <AFMotor.h>
#include <Servo.h>

#define TRIG_PIN 10
#define ECHO_PIN A0
String command;

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;



void setup() {
  
Serial.begin(9600);
myservo.attach(10);
myservo.write(0);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}

void loop() {
  
 delay(1000);
 while(Serial.available()) {
  command = "";  
  command = Serial.readString();
  
    Serial.print(command);
}
  if(command == "*move forward#"){
    forward(); Serial.println("moving forward");
  }else if(command == "*move backward#"){
    backward();Serial.println("moving backward");
  }else if(command == "*turn left#"){
    left();Serial.println("turning left");
  }else if(command == "*turn right#"){
    right();Serial.println("turning right");
  }else if(command == "*stop#") {
    Stop();
 }
  command = "";
}

void right() {
  myservo.write(145);
  delay(1500);
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  
}

void left() {
  myservo.write(60);
  delay(1500);
  myservo.write(180);
  delay(1000);myservo.write(90);
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void backward() {
  
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
  delay(5500);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void forward() {
 
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
  delay(5000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
