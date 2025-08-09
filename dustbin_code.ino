#include <Servo.h>

Servo myservo;  

// Pin connections
const int trigPin = 9;   
const int echoPin = 10;  
const int servoPin = 5;  

// Variables for distance calculation
long duration;
int distance;

void setup() {
  myservo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.write(90); // Closed position
  Serial.begin(9600);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // If object is within 20 cm, open lid
  if (distance <= 20) {
    myservo.write(30);  // Open lid
    delay(2000);        // Wait 3 seconds
    myservo.write(90);   // Close lid
  }

  delay(200); // Small delay before next reading
}
