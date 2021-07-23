float getTemperature(int myReading) {
  int Vo = myReading;
  float R1 = 10000;              // resistencia fija del divisor de tension
  float logR2, R2, myTemperature;

    //float c1 = 2.229674985e-03, c2 = 1.211871252e-04, c3 = 8.713435086e-07; //para 1k
    float c1 = 2.108508173e-03, c2 = 0.7979204727e-04, c3 = 6.535076315e-07; //para 10k
    //float c1 = 2.114990448e-03, c2 = 0.3832381228e-04, c3 = 5.228061052e-07; //para 100k

  R2 = R1 * (1023.0 / (float)Vo - 1.0); // conversion de tension a resistencia
  logR2 = log(R2);      // logaritmo de R2 necesario para ecuacion
  myTemperature = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // ecuacion S-H
  myTemperature = myTemperature - 273.15;   // Kelvin a Centigrados (Celsius)
  return myTemperature;
}


void calculateTemperatures() {
  boxTemperature = getTemperature(boxReadPin);
  engineTemperature = getTemperature(engineReadPin);
}

void loopThermistor() {
  calculateTemperatures();
  temperatureLedPinStatus = boxTemperature > TEMPERATURE_LIMIT
                            or engineTemperature > TEMPERATURE_LIMIT;
}
