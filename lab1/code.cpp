// дополнительных библиотек не используем

int buttonState = 0;

int lastButtonState = 0;

int buttonPushCounter = 0;

int counts = 0;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
    if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter += 1;
    }
    delay(5);
  }
  lastButtonState = buttonState;
  if (buttonPushCounter % 2 == 0) {
    if (counts < 5000) {
    	digitalWrite(13, HIGH);
    }
    if ( 10000 <= counts && counts <= 20000) {
    	digitalWrite(10, HIGH);
    	digitalWrite(13, LOW);
    }
    if (counts > 20000) {
      digitalWrite(10, LOW);
      counts = 0;
    }
    counts++;
  } else {
    counts = 0;
    digitalWrite(13, LOW);
    digitalWrite(10, LOW);
  }
}