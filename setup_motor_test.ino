void setup() {
  // put your setup code here, to run once:
 pinMode(7,OUTPUT);
 pinMode(A0,INPUT);
 Serial.begin(115200);
 //attachInterrupt(0, count, RISING);//int0=pin2
}
float run_time;
float angle;
float distan;
float old_distan;
float pianli;
float pianliliang;
int num;
char flag;

//measuring the deviation


float dev_mea(){  
 int i;
 for (i=0;i<20;i++){
 pianli=pianli+analogRead(A0);}
 pianli=pianli/20;
 pianli=pianli/1021*40;
 return pianli;
}


void loop() {
    //
    //Serial.println(distan);
      distan=dev_mea();
      pianli=distan-old_distan;   
      
      //Serial.println(pianli);
      if(pianli>0)
      {
      angle=pianli/5*360; //edit the 5 
      digitalWrite(7,HIGH);//set the DIR
      run_time=angle/360/4*1000;  
      Serial.println(run_time);
      if(run_time>1){
      tone(6,6400,run_time); } 
      }
      
      if(pianli<0)
      {
      pianli=abs(pianli);
      angle=pianli/5*360; //edit the 5 
      digitalWrite(7,LOW);//set the DIR
      run_time=angle/360/4*1000;    
      if(run_time>1){
      tone(6,6400,run_time); } 
      }
      
      run_time=0;
      old_distan=distan;
      
    
    }
    
    




