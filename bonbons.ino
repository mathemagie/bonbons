#include <Process.h>
#include <Bridge.h>
#include <Console.h>
#include <Servo.h>

//Servo monServo;
const int ledPin = 6; 

void setup() {
  Bridge.begin();   // Initialize the Bridge
  Console.begin(); 
  //monServo.attach(9); 
  pinMode(ledPin, OUTPUT);
   //monServo.write(0);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
 
}

void loop() {
  Process p;
  p.runShellCommand("/usr/bin/curl http://mathemagie.net/projects/bonbons/index.php");
  Console.println("run curl command");
  
  while(p.running());  

  // Read command output. runShellCommand() should have passed "Signal: xx&":
  while (p.available()) {
    int result = p.parseInt();          // look for an integer
    if (result > 0) {
      Serial.println("YES !! un nouveau like");
      digitalWrite(ledPin, HIGH);
    
    }
  
    if (result == 0) {
        digitalWrite(ledPin, LOW);//bug in parsing process
       Serial.println("pas de nouveau likes");
    }
  
    
  } 
  delay(3000);  // wait 5 seconds before you do it again
}
