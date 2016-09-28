// --- Based on built-in Blink tutorial

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  xrb_led13_fast();
  xrb_led13_fast();
  xrb_led13_fast();
  xrb_led13_slow();
  xrb_led13_slow();
  xrb_led13_slow();
  xrb_led13_fast();
  xrb_led13_fast();
  xrb_led13_fast();
  delay(400);
}

void xrb_led13_fast()
{
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}

void xrb_led13_slow()
{
  delay(200);
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
}

