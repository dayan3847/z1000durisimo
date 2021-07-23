void changeSpeed() {
  myArraySpeed[currentSpeed][1] = false;
  int nextSpeed = (currentSpeed < lastSpeed ) ? currentSpeed + 1 : 0 ;
  currentSpeed = nextSpeed;
  myArraySpeed[currentSpeed][1] = true;
}

void loopSpeed() {
  if (buttonPressed) {
    if (!changed) {
      changeSpeed();
      //updateIndicators();
      changed = true;
    }
  } else {
    if (changed) {
      changed = false;
    }
  }
}

void setupSpeed () {
  lastSpeed = AMOUNT_OF_SPEED - 1;
  currentSpeed = 0;
  changed = false;
  myArraySpeed[0][0] = FIRST_LED_PIN;
  myArraySpeed[0][1] = true;
  for (int i = 1; i < AMOUNT_OF_SPEED ; i++ ) {
    myArraySpeed[i][0] = i + myArraySpeed[0][0];
    myArraySpeed[i][1] = false;
  }
}
