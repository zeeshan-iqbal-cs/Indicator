class Indicator{
private:
  int indication_pin;
public:
  static const bool NORMAL = HIGH; // This will go high and then low
  static const bool INVERTED = LOW;// This will go low first and than high
  Indicator();
  Indicator(int);
  void blink(int cycleLength = 1000,
              int numberOfCycles = 1,
              bool transition = Indicator::NORMAL,
              float ratio = 0.5);
};

Indicator::Indicator(){
  indication_pin = LED_BUILTIN;
  pinMode(indication_pin, OUTPUT);
}

Indicator::Indicator(int pin){
  indication_pin = pin;
  pinMode(indication_pin, OUTPUT);
}


void Indicator::blink(int cycleLength,
              int numberOfCycles,
              bool transition,
              float ratio){
  for(int i = 0; i < numberOfCycles; i++){
    digitalWrite(indication_pin, transition);
    delay(cycleLength * ratio);
    digitalWrite(indication_pin, !transition);
    delay(cycleLength * (1 - ratio));
  }
}
