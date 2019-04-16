void setup() {
  // put your setup code here, to run once:
  motorSetup();
  trackSensorSetup();
  barrierSensorSetup();
  irSetup();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  trackSensorControl();
//  barrierSensorControl();
  irControl();
}
