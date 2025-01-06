//ΑΠΑΛΛΑΚΤΙΚΗ ΕΡΓΑΣΙΑ ΕΞΑΜΗΝΟΥ
//ΠΩΣ ΝΑ ΑΠΟΦΥΓΕΙ ΤΟ ΟΧΗΜΑ ΕΜΠΟΔΙΑ
// ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ - ΑΡΧΙΚΟΠΟΙΗΣΗ ΤΙΜΩΝ

#include <Servo.h>  //THE C++ COMPILER WILL TAKE INTO ACCOUNT ALL RECORDS RELATED TO SERVO ENGINES//
Servo Myservo; // NAMED SERVO ENGINE//
#define trig 11 //VARIABLE ULTRASONIC SENSOR DECLARATION HC-SR04//
#define echo = 10
// VARIABLE 1ST ENGINE//
#define in1 7
#define in2 6
// VARIABLE 2ST ENGINE//
#define in3 5
#define in4 4

void setup()      //CODE THAT WILL CHECK ONCE//
{
  // VARIABLE ENGINE΄S PINS 0UTPUT/
  Serial.begin(9600);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);   
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode(trig, OUTPUT); // VARIABLE PIN ΤRIG ΤΟΥ HC-SR04 OUTPUT//
  pinMode(echo, INPUT); // VARIABLE PIN ECHO ΤΟΥ HC-SR04 INPUT TO RECEIVE MICROWAVE SIGNALS //   
 Myservo.attach(9);//ATTACH SERVO ENGINE PIN 9//
}
void loop()        //CODE THAT WILL REPEAT//
{ 
  Serial.begin(9600); STARTING PRICE
  digitalWrite(trig, LOW);  //NO EMISSION MICROWAVE SIGNALS//
  delay(200);              //DELAY 0,2 SECONDS//
  digitalWrite(trig, HIGH);//EMISSION MICROWAVE SIGNALS//
  delay(100);              //DELAY ΓΙΑ 0,1 SECONDS//
  duration = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  distance = duration / 58.2;          //DISTANCE MEASUREMENT
  Serial.println(distance);     //PRINTING CONDITION//
  delay(10);
  
// TREATY TO AVOID OBSTACLE// 

    if (distance > 15)    //CHECK IF THE DISTANCE IS HIGHER THAN 15 THEN DO THIS// 
  {
    Myservo.write(90);    //VARIABLE SERVO ENGINE 90 DEGREES//
    digitalWrite(in3, HIGH);   // MOVE FORWARD//
    digitalWrite(in4, LOW);
    digitalWrite(in2, HIGH);                                
    digitalWrite(in1, LOW);                                                       
  }
  else if ((distance < 10)&(distance > 0))  //CHECK DISTANCE FOR OBSTACLE IDENTIFICATION//
  {
    digitalWrite(in3, LOW);     //STOP//              
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, LOW);
    delay(100);         //DELAY-STOP 0,1 SECONDS//
    
    Myservo.write(0);  //ΤRΕΑΤΥ ΤΟ ΤΘΡΝ  ENGINE SERVO RIGHT-LRFT//
    delay(500);         //DELAY-STOP 0,5 SECONDS//
    Myservo.write(180);  //VARIABLE SERVO ENGINE 180 DG//
    delay(500);          //DELAY-STOP 0,5 SECONDS//
    Myservo.write(90);  //VARIABLE SERVO ENGINE 90 DG//
    delay(500);            //DELAY-STOP 0,5 SECONDS//
    
    digitalWrite(in3, LOW); //TREATY MOVE BACK//             
    digitalWrite(in4, HIGH);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, HIGH);
    delay(500);               //DELAY-STOP 0,5 SECONDS//
    digitalWrite(in3, LOW); //TREATY TO STOP THE VEHICLE//               
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, LOW);  
    delay(100);               //DELAY-STOP 0,1 SECONDS//
    digitalWrite(in3, HIGH);// TREATY TO MOVE RIGHT//     
    digitalWrite(in4, LOW);   
    digitalWrite(in1, LOW);                                 
    digitalWrite(in2, LOW);  
    delay(500);             //DELAY-STOP 0,5 SECONDS//
 }
}
