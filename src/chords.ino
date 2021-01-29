#define SEED_PIN A0

void setup() {
  randomSeed(analogRead(SEED_PIN));
}

void loop() {
  
}