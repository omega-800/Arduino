//Positionen, an denen der Joystick sich befindet
int valueX = 0;
int valueY = 0;
int valueZ = 0;

//4 LEDs
int ledONE = 8;
int ledTWO = 9;
int ledTHREE = 10;
int ledFOUR = 11;

//Setup-Methode
void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  }

//Loop-Methode
void loop() {
  //X-Werte einlesen und ausgeben
  valueX = analogRead(0);
  Serial.print("X:");
  Serial.print(valueX, DEC);
  
  //Y-Werte einlesen und ausgeben
  valueY = analogRead(1);
  Serial.print(" | Y:");
  Serial.print(valueY, DEC);
  
  //Z-Werte einlesen und ausgeben
  valueZ = digitalRead(7);
  Serial.print(" | Z: ");
  Serial.println(valueZ, DEC);

  //Falls Joystick nach oben zeigt, oberes Lämpchen aufleuchten usw
  if(valueX<500){
    digitalWrite(ledONE, HIGH);
    digitalWrite(ledTHREE, LOW);
  } else{
    digitalWrite(ledONE, LOW);
    digitalWrite(ledTHREE, HIGH);
  }
  
  //Falls Joystick nach rechts zeigt, rechtes Lämpchen aufleuchten usw
  if(valueY<500){
    digitalWrite(ledTWO, HIGH);
    digitalWrite(ledFOUR, LOW);
  } else{
    digitalWrite(ledTWO, LOW);
    digitalWrite(ledFOUR, HIGH);
  }
  
  delay(100);
  }
