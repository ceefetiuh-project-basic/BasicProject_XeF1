#include <Servo.h>
const int banh_trai1 = 2;
const int banh_trai2 = 3;
const int banh_phai1 = 4;
const int banh_phai2 = 5;
Servo myservo1;
char state ;
// prototype
void tien();
void lui();
void trai();
void phai();
void dung();
void thang();

void setup(){
  Serial.begin(9600);
pinMode(banh_trai1,OUTPUT);
pinMode(banh_trai2,OUTPUT);
pinMode(banh_phai1,OUTPUT);
pinMode(banh_phai2,OUTPUT);
myservo1.attach(6);
  }
  void loop()
  {
if(Serial.available() >0)
  { state = Serial.read();
  Serial.print(state);
  }
  else state = 0;

    switch (state){
    case 'A':
    tien(128);
    break;
    case 'L':
    lui(135);
    break;
    case 'P':
    phai();
      //myservo1.write(60);
    break;
    case 'T':
    trai();
    //myservo1.write(130); 
    break;
    case 'D':
    dung();
    break;
   case 'U':
   thang();    
    }
}
       
    
void tien(int _speed)
{
 analogWrite(banh_trai1,_speed);
 digitalWrite(banh_trai2,LOW);
 analogWrite(banh_phai1,_speed);
 digitalWrite(banh_phai2,LOW);
}
void lui(int _speed)
{
analogWrite(banh_trai2,_speed);
 digitalWrite(banh_trai1,LOW);
 analogWrite(banh_phai2,_speed);
 digitalWrite(banh_phai1,LOW);
}
void trai()  
  {  
  myservo1.write(60);
  }
void phai()
  {
    myservo1.write(120);
  }
void dung()
{
  analogWrite(banh_trai1,LOW);
  digitalWrite(banh_trai2,LOW);
  analogWrite(banh_phai1,LOW);
  digitalWrite(banh_phai2,LOW);
}   
  void thang()
{
    myservo1.write(90);
}
