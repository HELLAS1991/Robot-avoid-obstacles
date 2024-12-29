//ΑΠΑΛΛΑΚΤΙΚΗ ΕΡΓΑΣΙΑ ΕΞΑΜΗΝΟΥ
//ΠΩΣ ΝΑ ΑΠΟΦΥΓΕΙ ΤΟ ΟΧΗΜΑ ΕΜΠΟΔΙΑ
// ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ - ΑΡΧΙΚΟΠΟΙΗΣΗ ΤΙΜΩΝ

#include <Servo.h>  //Ο ΜΕΤΑΓΛΩΤΙΣΤΗΣ C++ ΘΑ ΛΑΒΕΙ ΥΠΟΨΗ ΟΛΑ ΤΑ ΑΡΧΕΙΑ ΠΟΥ ΑΦΟΡΟΥΝ ΤΟΥΣ ΚΙΝΗΤΗΡΕΣ SERVO//
Servo Myservo; // ΟΝΟΜΑΤΟΛΟΓΙΑ ΤΟΥ  SERVO ΚΙΝΗΤΗΡΑ//
const int trig = 11; //ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ ΑΙΣΘΗΤΗΡΑ ΥΠΕΡΗΧΩΝ HC-SR04//
const int echo = 10;
float timing = 0.0; //ΑΡΧΙΚΗ ΤΙΜΗ 0//
float dis = 0.0;  //ΑΡΧΙΚΗ ΤΙΜΗ 0//
const int buzzer = 12; //ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ ΗΧΕΙΟΥ//
// ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ 1ΟΥ ΚΙΝΗΤΗΡΑ//
int in1 = 7;
int in2 = 6;
// ΔΗΛΩΣΗ ΜΕΤΑΒΛΗΤΩΝ 2ΟΥ ΚΙΝΗΤΗΡΑ//
int in3 = 5;
int in4 = 4;


void setup()      //ΚΩΔΙΚΑΣ ΠΟΥ ΘΑ ΕΚΤΕΛΕΣΤΕΙ ΜΙΑ ΦΟΡΑ//
{
  // ΔΗΛΩΣΗ ΤΑ PIN ΤΩΝ ΚΙΝΗΤΗΡΩΝ ΩΣ ΕΞΟΔΟΙ//
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);   
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode(trig, OUTPUT); // ΔΗΛΩΣΗ ΤΟ PIN ΤRIG ΤΟΥ HC-SR04 ΩΣ ΕΞΟΔΟ//
  pinMode(echo, INPUT); // ΔΗΛΩΣΗ ΤΟ PIN ECHO ΤΟΥ HC-SR04 ΩΣ ΕΙΣΟΔΟ ΓΙΑ ΤΗ ΛΗΨΗ ΤΩΝ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ //   
  pinMode(buzzer, OUTPUT);// ΔΗΛΩΣΗ ΤΟΥ ΗΧΕΙΟΥ ΩΣ ΕΞΟΔΟ//
  digitalWrite(trig, LOW);//ΟΧΙ ΕΚΠΟΜΠΗ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ//
  digitalWrite(buzzer, LOW);//ΑΡΧΙΚΗ ΤΙΜΗ 0,ΧΩΡΙΣ ΗΧΟ//
  Myservo.attach(9);//ΕΠΙΣΥΝΑΨΗ ΤΟΥ ΚΙΝΗΤΗΡΑ SERVO ΣΤΗΝ ΑΚΙΔΑ 9//
   
  Serial.begin(9600);
}
long dura, distance; //Η ΔΙΑΡΚΕΙΑ ΚΙΝΗΣΗΣ ΕΞΑΡΤΑΤΑΙ ΤΗΣ ΑΠΟΣΤΑΣΗΣ//

void loop()        //ΚΩΔΙΚΑΣ ΠΟΥ ΘΑ ΕΠΑΝΑΛΑΜΒΑΝΕΤΑΙ//
{     
  digitalWrite(trig, LOW);  //ΟΧΙ ΕΚΠΟΜΠΗ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ//
  delay(200);              //ΑΝΑΜΟΝΗ ΓΙΑ 0,2 SECONDS//
  digitalWrite(trig, HIGH);//ΕΚΠΟΜΠΗ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ//
  delay(100);              //ΑΝΑΜΟΝΗ ΓΙΑ 0,1 SECONDS//
  digitalWrite(trig, LOW);  //ΠΑΥΣΓΗ ΕΚΠΟΜΠΗΣ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ//
  timing = pulseIn(echo, HIGH);//ΛΗΨΗ ΜΙΚΡΟΚΥΜΑΤΙΚΩΝ ΣΗΜΑΤΩΝ//
  distance = (timing * 0.034) / 2; //ΜΕΤΡΗΣΗ ΑΠΟΣΤΑΣΗΣ
  
//ΣΥΝΘΗΚΗ ΕΚΤΥΠΩΣΗΣ//

  Serial.print("Distance: ");//ΕΚΤΥΠΩΣΕ :ΑΠΟΣΤΑΣΗ:"  "//
  Serial.print(distance);   //ΕΚΤΥΠΩΣ ΜΟΝΟ ΤΟΝ ΑΡΙΘΜΟ//
  Serial.print("cm l ");    //ΕΚΤΥΠΩΣΕ :"CM  l "//
  Serial.print(distance / 2.54);  //ΕΚΤΥΠΩΣΕ ΤΟΝ ΥΠΟΛΟΓΙΣΜΟ ΤΗΣ ΠΡΑΞΗΣ
  Serial.println("in");         //ΕΚΤΥΠΩΣΕ ΣΕ ΑΛΛΗ ΓΡΑΜΜΗ ΤΟ "IN"//
  
// ΣΥΝΘΗΚΗ ΓΙΑ ΑΠΟΦΥΓΗ ΕΜΠΟΔΙΟΥ// 

    if (distance > 15)    //ΕΛΕΓΧΟΣ ΕΑΝ Η ΑΠΟΣΤΑΣΗ ΕΙΝΑΙ ΜΕΓΑΛΥΤΕΡΗ ΑΠΟ ΤΗΝ ΤΙΜΗ 15 ΤΟΤΕ ΚΑΝΕ ΤΟ ΠΑΡΑΚΑΤΩ// 
  {
    Myservo.write(90);    //TIMH ΣΤΟ SERVO ΚΙΝΗΤΗΡΑ 90 ΜΟΙΡΕΣ//
    digitalWrite(in3, HIGH);   // ΚΙΝΗΣΗ ΕΜΠΡΟΣ//
    digitalWrite(in4, LOW);
    digitalWrite(in2, HIGH);                                
    digitalWrite(in1, LOW);                                                       
  }
  else if ((distance < 10)&(distance > 0))  //ΕΛΕΓΧΟΣ ΑΠΟΣΤΑΣΗΣ ΓΙΑ ΑΝΑΓΝΩΡΙΣΗ ΕΜΠΟΔΙΟΥ//
  {
    digitalWrite(in3, LOW);     //ΑΚΙΝΗΤΟΠΟΙΗΣΗ=STOP//              
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, LOW);
    tone(buzzer, 500);       //ΗΧΟΣ ΑΠΟ ΤΟ ΗΧΕΙΟ//
    } else {
  	noTone(buzzer);         //ΠΑΥΣΗ ΗΧΕΙΟΥ//
  }

    delay(100);         //ΑΝΑΜΟΝΗ ΓΙΑ 0,1 SECONDS//
    
    Myservo.write(0);  //ΣΥΝΘΗΚΗ ΓΙΑ ΣΤΡΟΦΗ ΤΟΥ SERVO ΚΙΝΗΤΗΡΑ ΔΕΞΙΑ-ΑΡΙΣΤΕΡΑ//
    delay(500);         //ΑΝΑΜΟΝΗ ΓΙΑ 0,5 SECONDS//
    Myservo.write(180);  //TIMH ΣΤΟ SERVO ΚΙΝΗΤΗΡΑ 180 ΜΟΙΡΕΣ//
    delay(500);          //ΑΝΑΜΟΝΗ ΓΙΑ 0,5 SECONDS//
    Myservo.write(90);  //TIMH ΣΤΟ SERVO ΚΙΝΗΤΗΡΑ 90 ΜΟΙΡΕΣ//
    delay(500);            //ΑΝΑΜΟΝΗ ΓΙΑ 0,5 SECONDS//
    
    digitalWrite(in3, LOW); //ΣΥΝΘΗΚΗ ΓΙΑ ΤΗΝ ΚΙΝΗΣΗ ΤΟΥ ΟΧΗΜΑΤΟΣ ΠΙΣΩ//             
    digitalWrite(in4, HIGH);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, HIGH);
    delay(500);               //ΑΝΑΜΟΝΗ ΓΙΑ 0,5 SECONDS//
    digitalWrite(in3, LOW); //ΣΥΝΘΗΚΗ ΓΙΑ ΤΗΝ ΑΚΙΝΗΤΟΠΟΙΗΣΗ=ΠΑΥΣΗ ΤΟΥ ΟΧΗΜΑΤΟΣ//               
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);                                
    digitalWrite(in1, LOW);  
    delay(100);               //ΑΝΑΜΟΝΗ ΓΙΑ 0,1 SECONDS//
    digitalWrite(in3, HIGH);// ΣΥΝΘΗΚΗ ΓΙΑ ΤΗΝ ΚΙΝΗΣΗ ΤΟΥ ΟΧΗΜΑΤΟΣ  ΔΕΞΙΑ//     
    digitalWrite(in4, LOW);   
    digitalWrite(in1, LOW);                                 
    digitalWrite(in2, LOW);  
    delay(500);             //ΑΝΑΜΟΝΗ ΓΙΑ 0,5 SECONDS//
 }
