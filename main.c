#define PinTrig 12
#define PinEcho 11
#define led 13


 
void setup() {
  Serial.begin (9600); //initialisation of seriall port, 9600kbps
  pinMode(PinTrig, OUTPUT); //configuration of a pin as output
  pinMode(PinEcho, INPUT); //configuration of a pin as input
  pinMode(led, OUTPUT);
}


void loop() {  
  //the distance is measured once the button is pressed
  if(digitalRead(7)==HIGH){
  if(zmierzOdleglosc()==0){
    Serial.print(zmierzOdleglosc());
    Serial.println(" cm, zly odczyt");
  }else{
    Serial.print(zmierzOdleglosc()); 
    Serial.println(" cm");  
  }
  }
  delay(500);
} 
 
  int zmierzOdleglosc() {
  long czas, dystans; 
 
  digitalWrite(PinTrig, LOW); 
  delayMicroseconds(2);       
  digitalWrite(PinTrig, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(PinTrig, LOW); 
 
  czas = pulseIn(PinEcho, HIGH);  //info read from the pin when high state
  dystans = czas / 58;  //according to documentation
  //wrong data handling
  if(dystans>500){
    digitalWrite(led, LOW); //the diode is off when the measurement is wrong
    return 0;
    
  }else{
  return dystans;
  digitalWrite(led, HIGH); //the diode is o when the measurement is correct
  }
}