int s1;
int s2;
int s3;
int s4;
int s5;
int s6;
int s7;
int s8;

char ar[20];
int i;
int j;
char temp[20];

const int ENA = 3;
const int IN1=2;
const int IN2=4;
const int ENB = 11;
const int IN3=10;
const int IN4=12;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);

  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  readsensors();
  
  //black=1
  //white=0
  //left
  if(
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
  )
  {
    if(ar[i-1]!='L')
    {
      ar[i]='L';
      i++;
      if(ar[i-2]=='B'){ 
        shortpath(); }
    } 
    left();
  }
  //forward then right
  else
  {
    LeftHandOnWall();
  }

}
void readsensors()
{
  s1=digitalRead(A0);
  s2=digitalRead(A1);
  s3=digitalRead(A2);
  s4=digitalRead(5);
  s5=digitalRead(6);
  s6=digitalRead(7);
  s7=digitalRead(8);
  s8=digitalRead(9);
}

void LeftHandOnWall()
{
  //forward
  if(
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  //((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  
  ((s1==0)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==0)&&(s8==0))||
  ((s1==0)&&(s2==0)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
  )
  {
    if(ar[i-1]!='S')
    {
      ar[i]='S';
      i++;
      if(ar[i-2]=='B'){ 
        shortpath(); }
    } 
    forward();
  }
  else if(
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==1)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))|
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
  ((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))
  )
  {
    if(ar[i-1]!='R')
    {
      ar[i]='R';
      i++;
      if(ar[i-2]=='B'){ 
        shortpath(); }
    }
    right();
  }
  //back
  else if((s1==0)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==0))
  {
    if(ar[i-1]!='B')
    {
      ar[i]='B';
      i++;
    } 
    back();
  }
  //stop
  else if(
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||    
    
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||

    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))
    )
  {
    motor_stop();
    delay(5000);
    replay();
    
  }
}
void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 65);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 65);
}
void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 70);
}
void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 70);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void back()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 90);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 90);
}
void motor_stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  
}
void shortpath()                                                   
{  
  int shortdone=0;
  if(ar[i-3]=='L'&&ar[i-1]=='R')
     { i=i-3;
        ar[i]='B';
        shortdone=1;
     }
   if(ar[i-3]=='L'&&ar[i-1]=='S'&&shortdone==0)
     { i=i-3;
        ar[i]='R';
        shortdone=1;
     }
    if(ar[i-3]=='L'&&ar[i-1]=='L'&&shortdone==0)
     { i=i-3;
        ar[i]='S';
        shortdone=1;
     }
   if(ar[i-3]=='S'&&ar[i-1]=='L'&&shortdone==0)
     { i=i-3;
        ar[i]='R';
        shortdone=1;
     }
   if(ar[i-3]=='S'&&ar[i-1]=='S'&&shortdone==0)
     { i=i-3;
        ar[i]='B';
        shortdone=1;
     }        
   if(ar[i-3]=='R'&&ar[i-1]=='L'&&shortdone==0)
     { i=i-3;
        ar[i]='B';
        shortdone=1;
     }
}
void replay()        //Function to retrace the path through new saved shortest route
{
   for(i=0;ar[i]!='\0';i++)
    { temp[i]=ar[i];
    }
    temp[i]='\0';
   for(j=0;temp[j]!='\0';j++)
      {  if(temp[j]=='L')
         { left();}
        else if(temp[j]=='R')
          { right();}
        else if(temp[j]=='S')
          { forward();}
        else if(temp[j]=='B')
           { back();}
     }
  if(
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
    
    
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
    
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==0)&&(s5==0)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==0)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==0)&&(s4==0)&&(s5==1)&&(s6==1)&&(s7==1)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==0)&&(s8==1))||
    ((s1==1)&&(s2==1)&&(s3==1)&&(s4==1)&&(s5==0)&&(s6==0)&&(s7==1)&&(s8==1))
    )
    {
      motor_stop();
    }
  
}
