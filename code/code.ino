#include <Servo.h>

Servo myServo1;       //Declaration of the servos and the angles
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
const int numberOfAngles = 14;
int offsetAngle = 90;
int delayTime = 1500;
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;
float servoAngle1[numberOfAngles] = {64, 45, 72, 97, 84, 85, 86, 87 , 88 , 88 ,88 , 88 ,88 ,89};
float servoAngle2[numberOfAngles] = {42, 39, 37, 33 , 26, 20, 10 ,12 ,14 ,15 ,17 ,21 ,27 ,41};
float servoAngle3[numberOfAngles] = {12, 3, 7, 35, 40, 37,32, 21, 8, 1, 9, 22, 39,17};


void setup() {
  Serial.begin(9600);
  myServo1.attach(9); // Attach the servo to pin 9,10,11
  myServo2.attach(10);
  myServo3.attach(11);

 // resetServo();
  delay(500);
  // Initialize serial communication (optional, for debugging)
}

void loop()
{
 unsigned long currentTime = millis(); 
   if( currentTime - previousTime1 >= delayTime ){
  goForward();

  previousTime1 = currentTime;
 }


}
void resetServo() {

  myServo1.write(offsetAngle);
  myServo2.write(offsetAngle);    // Set the servos to initial degrees
  myServo3.write(offsetAngle);
  delay(500);      // Wait for the servo to move to the position
  
}

void goForward(){
int j = 4;
int i = 0;
  while(i < numberOfAngles){
  myServo1.write(servoAngle1[i] + offsetAngle);      //Set the angles of the servos to the correct parameter in the array
  myServo2.write(servoAngle2[i] + offsetAngle);
  myServo3.write(servoAngle3[i] + offsetAngle);

  Serial.print(servoAngle1[i]);        //Show the results in serial monitor
  Serial.print(", "); 
  Serial.print(servoAngle2[i]);
  Serial.print(", "); 
  Serial.println(servoAngle3[i]);

 /* myServo4.write(servoAngle1[j% numberOfAngles] + offsetAngle);      //Set the angles of the servos to the correct parameter in the array
  myServo5.write(servoAngle2[j% numberOfAngles] + offsetAngle);
  myServo6.write(servoAngle3[j% numberOfAngles] + offsetAngle);

  Serial.print(servoAngle1[j% numberOfAngles]);        //Show the results in serial monitor
  Serial.print(", "); 
  Serial.print(servoAngle2[j% numberOfAngles]);
  Serial.print(", "); 
  Serial.println(servoAngle3[j% numberOfAngles]);
  */
  j++;
  i++;
  delay(500);
  
}

}