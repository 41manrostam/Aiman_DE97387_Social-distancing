int buzzerPin= 12; //set buzzer pin to pin 12
int RedLed=6;      //set Red LED pin to pin 6
int YellowLed=7;   //set Yellow LED pin to pin 7

float posi=0; //to input position values distance

//function to get the distance
float calcDistance(int trig, int echo)
{
  pinMode(trig, OUTPUT); //set trigger pin as output
  //clears trig pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  //set the trig pin on HIGH for 10 micro second
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); //generating the Ultra sound wave we have to set the trigPin on HIGH State for 10 
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT); //set echo pin as input //sending out wave
  //return the sound wave travel time and calculating distance
  return pulseIn(echo,HIGH,30000)/58.0;
} //This pin goes high for a period of time which will be equal to the time taken for the wave to return back to the sensor.

void setup() //setting up pins become input or output //call once the programme start
{
  pinMode(12, OUTPUT); // set buzzer as output
  pinMode(6, OUTPUT); //set Red LED as output
  pinMode(7, OUTPUT); //set Yellow LED as output
  Serial. begin(9600); //to view in serial monitor
}
  

void loop() //function where the programme will run continuously in a loop unless simualtion stop
{
  posi=calcDistance(4,5); //result of the distance
  Serial.print("Distance= "); //print "Distance= " in serial moinitor
  Serial.print(posi); //print the distance value in serial monitor
  Serial.println("cm"); //print unit of distance "cm" in serial monitor
  delay(800); //delay of 8 second to ease viewing in serial monitor
  
  if(posi <= 100) //minimum distance between user and other people
  {
    digitalWrite(buzzerPin, HIGH); //buzzer energize
    tone(buzzerPin, 100, 100); //tone(pin, frequency, duration)//set the pin, frequency of buzzer and the duration of the tone
    delay(200); //delay between the next tone
    tone(buzzerPin, 100, 100); //tone(pin, frequency, duration)//set the pin, frequency of buzzer and the duration of the tone
    delay(200); //delay between the next tone
    digitalWrite(RedLed, HIGH); //Red LED energize as a warning
    digitalWrite(YellowLed, LOW); //Yellow LED deenergize 
  }
  else
  {
    digitalWrite(buzzerPin, LOW); //buzzer deenergize
    digitalWrite(YellowLed, HIGH); //Yellow LED energize (safe distance)
    digitalWrite(RedLed, LOW); // Red LED deenergize
  }
    
}

 
  

