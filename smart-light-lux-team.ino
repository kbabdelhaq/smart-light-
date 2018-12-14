//smart light -lux team -project AEC 2018 
//program of a simple prototype of smart light system project
const int pir2 = 3; // broche of PIR sensor 2
const int led2 = 12; // la LED 2  du systeme  
int  pir1inf = 8 ;  //  infotmation of  pir sensor 1 
int  pir3inf =10 ;   //  infotmation of  pir sensor 3 
int pir2topir1 = 9 ; //to send information from this systeme to systeme number 1
int pir2topir3 = 11 ;  //to send information from this systeme to systeme number 3
int pir2state = 0; // etat de la sortie du capteur
int pir1infstate = 0 ;
int pir3infstate = 0 ;
void setup()
{
  pinMode(led2, OUTPUT); //la broche de la LED est mise en sortie" LED is in OUTPUT"
  pinMode(pir2, INPUT); //la broche du capteur est mise en entree "pir sensor is in INPUT"
  pinMode(pir1inf, INPUT);
  pinMode(pir3inf, INPUT);
  pinMode(pir2topir1, OUTPUT);
  pinMode(pir2topir3, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  pir2state = digitalRead(pir2);//READ INFORMATION FROM THE PIR SENSOR 2
  pir1infstate = digitalRead(pir1inf);  //READ INFORMATION FROM THE PIR SENSOR 1
  pir3infstate = digitalRead(pir3inf);   //READ INFORMATION FROM THE PIR SENSOR 3

  if (pir2state == HIGH || pir1inf == HIGH || pir3inf == HIGH  ) //"if something was detected in any sensor"
  {
    digitalWrite(led2, HIGH); // LED 2 "ON" 
  
 
digitalWrite(pir2topir1, HIGH); //send information to the system number 1
digitalWrite(pir2topir3, HIGH); //send information to the system number 3
Serial.println("Motion detected in the systeme number 2 ");
delay(3000); // LED stay ON for just 3s if there is no other detection 
  }
  else 
  {
    digitalWrite(led2, LOW); // LED OFF 
 Serial.println("Motion ended "); 
 delay(500);
  }
}
