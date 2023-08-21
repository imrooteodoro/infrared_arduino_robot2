// C++ code
//
#include <IRremote.h>
const int led = 3;
const int motor = 4;
int RECV_PIN=2;
IRrecv irrecv(RECV_PIN);
decode_results res;


void setup()
{Serial.begin(9600);
 pinMode(led, OUTPUT);
 pinMode(motor,OUTPUT);
 irrecv.enableIRIn();
  
}

void loop()
{ if (irrecv.decode(&res)){
  Serial.print("HEX: ");
  Serial.println(res.value,HEX);
  Serial.print("DEC:");
  Serial.println(res.value);
  Serial.println("________________");
  if(res.value==0xFD8877){digitalWrite(led,HIGH);}
  if (res.value==0xFD6897){digitalWrite(led, LOW);}
  if(res.value==0xFD08F7){digitalWrite(motor, HIGH);}
  irrecv.resume();
  delay(100);}
}
