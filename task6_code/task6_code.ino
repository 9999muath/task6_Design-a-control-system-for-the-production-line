#include <Servo.h>
                  // servo motors
Servo motor_A;  
Servo motor_B;
Servo motor_C;
                  // Input LDR sensor  
int led10 = A0;   
int led20 = A1;
int led30 = A2;
                   // LED for EROR
int LED = A5;     
                    // variables
int C_led10;
int C_led20;
int C_led30;
                    // to STOP movement DC motor by mosfet
int moveoff = 7; 


void setup() {
  motor_A.attach(13);
  motor_B.attach(12);
  motor_C.attach(8);
  pinMode(LED, OUTPUT);
  pinMode(moveoff, OUTPUT);


  pinMode(led10, INPUT_PULLUP);
  pinMode(led20, INPUT_PULLUP);
  pinMode(led30, INPUT_PULLUP);
  Serial.begin(9600);


}

void loop() { 
  C_led10 = digitalRead(led10);
   C_led20 = digitalRead(led20);
  C_led30 = digitalRead(led30);

  if (C_led10 == HIGH && C_led20 == HIGH && C_led30 == HIGH )      // No box has passed           
    { 
      motor_A.write(92); // Equal = 0 in proteus
      motor_B.write(92); // Equal = 0 in proteus
      motor_C.write(92); // Equal = 0 in proteus
      digitalWrite(moveoff, LOW);
      digitalWrite(LED , LOW);
    }
      
  else if (C_led10 == LOW && C_led20 == HIGH && C_led30 == HIGH )     // box 10*10 has passed
    {motor_A.write(92); // Equal = 0 in proteus
      motor_B.write(117);// Equal = 45 in proteus
      motor_C.write(180);// Equal = 92 in proteus
      digitalWrite(moveoff, HIGH);
      digitalWrite(LED , LOW);
      
      }
      
  else if (C_led10 == LOW && C_led20 == LOW && C_led30 == HIGH)     // box 20*20 has passed
    {motor_A.write(92);  // Equal = 0 in proteus
      motor_B.write(68); // Equal = -45 in proteus
      motor_C.write(0);  // Equal = -92 in proteus
      digitalWrite(moveoff, HIGH);
      digitalWrite(LED , LOW);
      
      }
      
  else if (C_led10 == LOW && C_led20 == LOW && C_led30 == LOW)     // box 30*30 has passed      
   { motor_A.write(92);// Equal = 0 in proteus
      motor_B.write(92);// Equal = 0 in proteus
      motor_C.write(92);// Equal = 0 in proteus
      digitalWrite(moveoff, HIGH);
      digitalWrite(LED , LOW);
      
     }
        
else{ digitalWrite(LED , HIGH);      
digitalWrite(moveoff, LOW);

}
  
 
}
