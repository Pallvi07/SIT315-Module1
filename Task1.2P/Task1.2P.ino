// Pallvi - 2110994824
// SIT315 TASK1.2P
// Using Interrupt to blink LED on detecting motion

// motion sensor connected to digital pin 2
const int SensorPin = 2;
// initial state of sensor declared LOW
volatile int SensorState = LOW;

void setup() {
  //initialize pin 2 as input pin
  pinMode(SensorPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // creating external interrupt
  attachInterrupt(digitalPinToInterrupt(SensorPin), Interrupt, CHANGE);
  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
}

void Interrupt() {
  Serial.println("Motion interrupted");
  SensorState = digitalRead(SensorPin);
  digitalWrite(LED_BUILTIN, SensorState);
  
  if(SensorState == HIGH){
    Serial.println("Motion detected - LED turned on");}
  else{
    Serial.println("Motion ended - LED turned off");}
}
