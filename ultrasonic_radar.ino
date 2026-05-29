#include <Servo.h>

const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;

Servo myServo;

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
myServo.attach(10);
}

void loop() {
// Servo rotation and distance measurement
myServo.write(90);
delay(30);

distance = calculateDistance();

Serial.print("Angle: ");
Serial.print(90);
Serial.print(", Distance: ");
Serial.println(distance);
}

// Function to calculate distance
int calculateDistance() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

return distance;
}
