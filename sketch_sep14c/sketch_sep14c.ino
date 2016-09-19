const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup()
{
  // Open a serial port---I don't understand what this number means yet...
  Serial.begin(9600);
  // loop from pin 3 to pin 5 to set pins to accept output and set state to off
  for ( int i = 3; i < 6; ++i )
    {
      pinMode(i,OUTPUT);
      digitalWrite(i,LOW);
    }
}

void loop()
{
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value (ADC): ");
  Serial.print(sensorVal);
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if ( temperature < baselineTemp )
    {
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
  else if ( temperature >= baselineTemp && temperature <= baselineTemp + 2 )
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
    }
  else if ( temperature > baselineTemp +3 && temperature <= baselineTemp + 4 )
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
    }
  else // anything higher
    {
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
    }

  // add a delay to prevent querying the ADC too quickly
  delay(1);
}

