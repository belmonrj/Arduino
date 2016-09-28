const int redLEDPin = 11;
const int greenLEDPin = 9;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(redLEDPin,OUTPUT);
  pinMode(greenLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
}

void loop()
{
  // read from the sensor pins
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  // convert from 10 bit to 8 bit
  // AUR3 has 10 bit input and 8 bit output
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  // write to the LED pins
  analogWrite(redLEDPin,redValue);
  analogWrite(greenLEDPin,greenValue);
  analogWrite(blueLEDPin,blueValue);

  delay(1000);

  analogWrite(greenLEDPin,0);
  analogWrite(blueLEDPin,0);
  for ( int i = 0; i < redValue; ++i )
  {
    analogWrite(redLEDPin,i);
    delay(5);
  }

  analogWrite(redLEDPin,0);
  for ( int i = 0; i < greenValue; ++i )
  {
    analogWrite(greenLEDPin,i);
    delay(5);
  }

  analogWrite(greenLEDPin,0);
  for ( int i = 0; i < blueValue; ++i )
  {
    analogWrite(blueLEDPin,i);
    delay(5);
  }

  for ( int i = 0; i < 256; ++i )
  {
    int redindex = i;
    int greenindex = i;
    int blueindex = i;
    if ( i > redValue ) redindex = redValue;
    if ( i > greenValue ) greenindex = greenValue;
    if ( i > blueValue ) blueindex = blueValue;
    analogWrite(redLEDPin,i);
    analogWrite(greenLEDPin,i);
    analogWrite(blueLEDPin,i);
    delay(5);
  }

  delay(500);
}

