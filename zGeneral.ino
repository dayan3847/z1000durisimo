void declarePin() {
  pinMode (BUTTON_PIN, INPUT) ;
  for (int i = 0; i < AMOUNT_OF_SPEED ; i++ ) {
    pinMode (i + FIRST_LED_PIN, OUTPUT);
  }
  pinMode (TEMPERATURE_LED_PIN, OUTPUT);
}

void captureValues() {
  buttonPressed = !digitalRead(BUTTON_PIN);
  boxReadPin = analogRead(BOX_TERMISTOR_PIN);
  engineReadPin = analogRead(ENGINE_TERMISTOR_PIN);
}

void updateIndicators() {
  for (int i = 0; i < AMOUNT_OF_SPEED ; i++ ) {
    digitalWrite(myArraySpeed[i][0], myArraySpeed[i][1]);  // !  invertir polaridad
  }
  digitalWrite(TEMPERATURE_LED_PIN, temperatureLedPinStatus);
}
