#include <IRremote.h>

const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int leftForward=2;
const int leftBackward=3;
const int rightForward=4;
const int rightBackward=5;

void setup()
{
   // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
  
  irrecv.blink13(true);
  
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
  irrecv.resume();
  
    if(results.value!=0xFFFFFF){
    if(results.value==0xFD50AF)
  //foreWard
  forward();
  else if(results.value==0xFD10EF)
  //backward
  backward();
  else if(results.value==0xFD20DF)
  //turn left
  left();
  else if(results.value==0xFD609F)
  //turn right
  right();
  else if(results.value==0xFD00FF)
  stop();
    }
  delay(10); // Wait for 10 millisecond(s)
  }
}

void forward()
{
   //foreWard
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void left()
{
  //turn left
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void right()
{
  //turn right
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}

void backward()
{
  //backward
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}

void stop()
{
  //stop
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}