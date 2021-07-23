//**********VARIABLES_SPEED_BEGIN**************

const int BUTTON_PIN = 2;
const int FIRST_LED_PIN = 8;
const int AMOUNT_OF_SPEED = 3;  //cantidad de velocidades

int myArraySpeed [AMOUNT_OF_SPEED][2];
int lastSpeed;
int currentSpeed;
bool changed;
int buttonPressed;

//**********VARIABLES_SPEED_END**************


//**********VARIABLES_TEMPERATURE_BEGIN**************

const int TEMPERATURE_LED_PIN = 7;
const int BOX_TERMISTOR_PIN = A0;
const int ENGINE_TERMISTOR_PIN = A1;
const int TEMPERATURE_LIMIT = 35; //in Celsius

float boxReadPin; //lectura del pin de la caja
float engineReadPin; //lectura del pin del motor
float boxTemperature; //temperatura de la caja
float engineTemperature; //temperatura del motor
bool temperatureLedPinStatus = false;

//**********VARIABLES_TEMPERATURE_END**************
void setup () {
  Serial.begin(9600);
  delay(10);
  declarePin();

  setupSpeed();

  updateIndicators();
}

void loop() {
  Serial.println(boxTemperature);
  Serial.println(engineTemperature);
  Serial.println(temperatureLedPinStatus);
  
  captureValues();
  loopSpeed();
  loopThermistor();
  updateIndicators();
}
