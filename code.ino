#include <Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;
int numberOfAngles = 23;
int offsetAngle = 90;
float servoAngle1[23] = {3.825, 4.00, 4.635, 9.274, 16.508, 27.348, 39.668, 47.047, 58.109, 60.8, 62.636, 64.693, 53.253, 41.276, 32.555, 21.387, 16.161, 10.592, 7.548, 5.823, 4.888, 4.319, 3.826};
float servoAngle2[23] = {10.438, 13.91, 20.383, 38.981, 44.338, 40.622, 31.73, 24.405, 11.712, 7.762, 3.762, 1.49, 9.348, 18.685, 24.191, 29.435, 30.715, 29.912, 26.741, 22.397, 18.297, 14.716, 10.47};
float servoAngle3[23] = {63.479, 68.659, 76.848, 82.928, 74.552, 73.868, 78.581, 86.385, 77.431, 71.187, 63.407, 53.227, 62.536, 69.449, 72.676, 75.109, 75.606, 75.322, 73.945, 71.643, 69.152, 66.769, 63.552};


void setup() {
  // Attach the servo to pin 9,10
  myServo1.attach(9);
  myServo2.attach(10);
  myServo3.attach(11);
  resetServo();
  delay(500);
  // Initialize serial communication (optional, for debugging)
  Serial.begin(9600);
}

void loop()
{
  for(int i = 0; i < numberOfAngles; i++)
  {

  myServo1.write(servoAngle1[i] + offsetAngle);
  myServo2.write(servoAngle2[i] + offsetAngle);
  myServo3.write(servoAngle3[i] + offsetAngle);
  delay(500);

  Serial.print(servoAngle1[i]);
  Serial.print(", "); 
  Serial.print(servoAngle2[i]);
  Serial.print(", "); 
  Serial.println(servoAngle3[i]);

 }
 
}
void resetServo() {

  myServo1.write(servoAngle1[0] + offsetAngle);
  myServo2.write(servoAngle2[0] + offsetAngle); // Set the servos to initial degrees
  myServo3.write(servoAngle3[0] + offsetAngle);
  delay(500);       // Wait for the servo to move to the position
  
}
