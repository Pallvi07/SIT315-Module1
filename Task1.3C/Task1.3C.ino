// Pallvi - 2110994824
// SIT315 TASK1.3C
// Use interrupt while working with two sensors

// motion sensor connected to digital pin 2
const int MotionSensor = 2;
// motion sensor connected to digital pin 3
const int SoilMoistureSensor = 3;
// red and gren led connected to pin 8 and 9
const int RedLed = 8;
const int GreenLed = 9;

// initial state of sensor declared LOW
volatile int MotionSensorState = LOW;

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize pins as output or input pins
  pinMode(MotionSensor, INPUT);
  pinMode(SoilMoistureSensor, INPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(MotionSensor), motionInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(SoilMoistureSensor), moistureInterrupt, CHANGE);
}

void loop() {
}

void motionInterrupt() {
  Serial.println("Motion Interrupt");
  MotionSensorState = digitalRead(MotionSensor);
  digitalWrite(GreenLed, MotionSensorState);
 
  if (MotionSensorState == HIGH) {
    Serial.println("Motion detected - LED turned on");}
  else {
    Serial.println("Motion ended - LED turned off");}
}

void moistureInterrupt() {
  int moistureLevel = analogRead(SoilMoistureSensor);
  Serial.println("Moisture Interrupt");
  Serial.print("Moisture level: ");
  Serial.println(moistureLevel);
  // red led blinks for half second in case of interrupt
  digitalWrite(RedLed, HIGH);
  delay(500);
  digitalWrite(RedLed, LOW);
}
