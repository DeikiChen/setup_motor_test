void setup() {
  // put your setup code here, to run once:
 pinMode(7,OUTPUT);
 pinMode(A1,INPUT);
 Serial.begin(9600);
}
float run_time;
float angle;
float distan;

void loop() {
distan=20;//set the distan，(mm)

angle=distan/2*360; //edit the 2 
digitalWrite(7,HIGH);//set the DIR
run_time=angle/360;
run_time=run_time/4;
run_time=run_time*1000;

Serial.print("run_time=");
Serial.println(run_time);
Serial.print("angle=");
Serial.println(angle);

tone(6,6400,run_time);
while(1);

}
