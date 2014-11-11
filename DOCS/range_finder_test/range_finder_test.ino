void setup() 
{ 
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop(){
  int read_value;
  static int maxx = 0;
  static int minn = 1023;
  
  read_value = analogRead(A0);
  delayMicroseconds(70);
  
  if(read_value > maxx){
    maxx = read_value;
  }
  
  if(read_value < minn){
    minn = read_value;
  }
  
  Serial.print(minn); // min = 0
  Serial.print("-");
  Serial.print(read_value);  
  Serial.print("-");
  Serial.println(maxx);// max = 747
  
}
