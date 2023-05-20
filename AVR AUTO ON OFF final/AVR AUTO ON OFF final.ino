
bool switchState = true;
const int switchPin = 2;
const int checkPin = 13;
bool lastState = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(switchPin, OUTPUT);
  //pinMode(checkPin, INPUT);
  pinMode( checkPin, INPUT );
  Serial.begin( 9600 );
}

// the loop function runs over and over again forever
void loop() {

  int value;
    
  value = digitalRead( checkPin );
  Serial.println( value );

  digitalWrite(LED_BUILTIN, value);
   if(value != lastState){
     lastState = value;
     switchState = true;
   }

  delay( 100 );
    
  if(switchState == true){
      digitalWrite(switchPin, LOW);
      delay(300);
      digitalWrite(switchPin, HIGH);
      switchState = false;
  }

}
