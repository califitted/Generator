
int Generator = 5;
int Compressor = 6;
int buttonApin = 9;


byte leds = 0;

void setup() 
{
  pinMode(Generator, OUTPUT);
  pinMode(Compressor, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  

}

bool started = false;

bool isHot() {
  return digitalRead(buttonApin) == LOW;
}

void loop() 
{
  if (isHot()) {
    // temperature is warm
    
    if (!started) {
      // we haven't started the compressor yet
      started = true;
      digitalWrite(Generator, HIGH);
      delay(10000);
      digitalWrite(Compressor, HIGH);
      delay(10000);
      digitalWrite(Generator, LOW);
    }
  } else {
    // temperature is cold
    digitalWrite(Compressor, LOW);
    started = false;
    delay(10000);
  }
}



