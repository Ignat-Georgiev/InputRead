int pinread;
int highsig = 0;
int lowsig = 0;
int period = 0;
unsigned long currenttime = 0;
unsigned long previoustime = 0;
unsigned long t;

void setup() {
  // put your setup code here, to run once:
pinMode(2, INPUT);
pinMode(3, OUTPUT);
Serial.begin(9600);
//defining the interupt for the rising edge of the square wave signal.
attachInterrupt(digitalPinToInterrupt(2), nullify, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Samples the input on pin 2 and adds 1 to either high or low variable.
  pinread = digitalRead(2);
  digitalWrite(3, pinread);
  Serial.println("input is: " + String(pinread));
  
  if (pinread == HIGH){
    highsig++;
  }
    
  if (pinread == LOW){
    lowsig++;
  }
  //This section essentialy counts the run time of the program.  
  currenttime = micros();
  
  t = currenttime - previoustime;
  previoustime = currenttime;
  
  //Some prints to help in testing.
  Serial.println("Program Run time is: " + String(period));
  Serial.println("High signal value is:" + String(highsig));
  Serial.println("Low signal value is:" + String(lowsig));

}
void nullify() {
  //When we encounter a rising edge, this is supposed to calculate the period of the square wave and reset the variables.
  
  period = (highsig + lowsig) * t;
  highsig = 0;
  lowsig = 0;

}


