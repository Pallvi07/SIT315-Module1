// Pallvi - 2110994824
// SIT315 TASK1.1P
// C++ code
// Blink LED on detecting motion

// motion sensor connected to digital pin 2
const int SensorPin = 2;  
// initial state of sensor is LOW
int SensorState = LOW;

void setup() {
  // initialize pin2 as input pin
  pinMode(SensorPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // read the state of Sensor
  SensorState = digitalRead(SensorPin);

  // turn on led if motion detected
  if (SensorState == HIGH) {
    Serial.println("Motion detected - LED turned on");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  // turn off led if motion not detected
  else {
    Serial.println("Motion not detected - LED turned off");
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(1000);
}
