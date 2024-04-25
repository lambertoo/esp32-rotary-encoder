
 #define outputA 14
 #define outputB 12

 int counter = 0; 
 int aState;
 int aLastState;  

void IRAM_ATTR Rotarycheck()
{
 aState = digitalRead(outputA); // Reads the "current" state of the outputA
   if (aState != aLastState){     
    if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
    
   } 
   aLastState = aState;
}
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (115200);
   // Reads the initial state of the outputA
    attachInterrupt(digitalPinToInterrupt(outputA), Rotarycheck, CHANGE);
    attachInterrupt(digitalPinToInterrupt(outputB), Rotarycheck, CHANGE);
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
  
     Serial.print("Position: ");
     Serial.println(counter);
   
 }

 