#include <Servo.h>

Servo myServo1;       //Declaration of the servos and the angles
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;
Servo myServo8;
Servo myServo9;
Servo myServo10;
Servo myServo11;
Servo myServo12;
const int numberOfAngles = 14;
int offsetAngle = 90;
int delayTime = 1500;
unsigned long previousTime1 = 0;
unsigned long previousTime2 = 0;
float servoAngle1[numberOfAngles] = {2.075, 0, -1.494, -1.611, -1.732, -1.921, -2.099, 0, 4.548, 5.102, 8.546, 11.016, 15.091, 25.011};
float servoAngle2[numberOfAngles] = {25.474, 29.179, 19.739, 14.957, 12.944, 10.785, 9.95, 15.567, 20.881, 22.789, 28.723, 30.342, 32.448, 33.365};
float servoAngle3[numberOfAngles] = {27.749, 44.572, 38.29, 25.903, 18.391, 9.308, 9.95, 8.545, 8.91, 9.06, 5.656, 3.61, 6.471, 9.808};
int offsetAngle1 = 90;


void setup() {
  Serial.begin(9600);
  myServo1.attach(11); // Attach the servo to pin 9,10,11
  myServo2.attach(12);
  myServo3.attach(13);
  myServo4.attach(8);
  myServo5.attach(9);
  myServo6.attach(10);
  myServo7.attach(5); 
  myServo8.attach(6);
  myServo9.attach(7);
  myServo10.attach(2);
  myServo11.attach(3);
  myServo12.attach(4);

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
  myServo4.write(offsetAngle);
  myServo5.write(offsetAngle);    
  myServo6.write(offsetAngle);
  myServo7.write(offsetAngle);
  myServo8.write(offsetAngle);    
  myServo9.write(offsetAngle);
  myServo10.write(offsetAngle);
  myServo11.write(offsetAngle);    
  myServo12.write(offsetAngle);
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

  myServo4.write(offsetAngle1 - servoAngle1[j% numberOfAngles]);      //Set the angles of the servos to the correct parameter in the array
  myServo5.write(offsetAngle1 - servoAngle2[j% numberOfAngles]);
  myServo6.write(offsetAngle1 - servoAngle3[j %numberOfAngles]);
  

  Serial.print(servoAngle1[j% numberOfAngles]);        //Show the results in serial monitor
  Serial.print(", "); 
  Serial.print(servoAngle2[j% numberOfAngles]);
  Serial.print(", "); 
  Serial.println(servoAngle3[j% numberOfAngles]);

  myServo7.write(servoAngle1[i] + offsetAngle1);      //Set the angles of the servos to the correct parameter in the array
  myServo8.write(servoAngle2[i] + offsetAngle1);
  myServo9.write(servoAngle3[i] + offsetAngle1);


  myServo10.write(offsetAngle - servoAngle1[j% numberOfAngles]);      //Set the angles of the servos to the correct parameter in the array
  myServo11.write(offsetAngle - servoAngle2[j% numberOfAngles]);
  myServo12.write(offsetAngle - servoAngle3[j %numberOfAngles]);

  j++;
  i++;
  delay(1500);

}

}