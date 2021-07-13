#define echopin 5
#define trigpin 7

long duration;
int distance ,trigPin,echoPin ;


void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  while(getDistance() > 25){} 
  
  int startTime = millis(); 
  
   while(getDistance() < 25)
   {
     int currntTime = millis();
     
     if (currntTime -startTime > 3000)
     {
       digitalWrite(11, HIGH);
       delay(3000);
       digitalWrite(11, LOW);
       break; 
     }
   }
}


int getDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034 / 2;
  
  return distance; 
}
