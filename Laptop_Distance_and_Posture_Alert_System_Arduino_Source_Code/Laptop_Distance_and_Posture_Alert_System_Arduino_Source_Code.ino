int trigger = 8, echo = 9, buzzer = 11;
double distance = 0.0;
unsigned long lastBeep = 0, pingTT = 0;
bool buzzerState = false;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  pingTT = pulseIn(echo, HIGH, 15000);
  if(pingTT == 0)
  {
    noTone(buzzer);
    buzzerState = false;
    return;
  }
  distance = (0.0343 * pingTT) / 2.0;
  Serial.println(distance);
  if(distance>45)
  {
    noTone(buzzer);
    buzzerState = false;
  }
  else if(distance>40 && distance<=45)
    beep(1000);
  else if(distance>36 && distance<=40)
    beep(400);
  else
    beep(100);
}

void beep(unsigned long interval)
{
  if(millis() - lastBeep >= interval)
  {
    lastBeep = millis();
    if(buzzerState == false)
    {
      tone(buzzer, 3000);
      buzzerState = true;
    }
    else
    {
      noTone(buzzer);
      buzzerState = false;
    }
  }
}