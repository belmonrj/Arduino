int switchState = 0; // define switch state at global scope

void setup()
{
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  // query the switch state (switch is on pin 2, see above)
  switchState = digitalRead(2);

  // if the switch is open turn pin 3 (green LED) on and pins 4 and 5 (red LED) off
  if ( switchState == LOW )
  {
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  }
  // if the switch is closed turn pin 3 off and switch pins 4 and 5
  else
  {
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(250);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(250);
  }
}

