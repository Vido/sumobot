
#define LEFT_RFINDER_PIN A0
#define RIGHT_RFINDER_PIN A1

void setup()
{
  Serial.begin(9600);
  pinMode(LEFT_RFINDER_PIN, INPUT);
  pinMode(RIGHT_RFINDER_PIN, INPUT);
}

void loop(){

  static int maxx_left = 0;
  static int minn_left = 1023;
  static int maxx_right = 0;
  static int minn_right = 1023;

  int left_value = analogRead(LEFT_RFINDER_PIN);
  int right_value = analogRead(RIGHT_RFINDER_PIN);
  delayMicroseconds(70);

  /* RIGHT */
  if(right_value > maxx_right) maxx_right = right_value;
  if(right_value < minn_right) minn_right = right_value;
  Serial.print(minn_right); // min = 0
  Serial.print("-");
  Serial.print(right_value);
  Serial.print("-");
  Serial.println(maxx_right);// max = 698
  // Serial.println(read_value);
  Serial.print("\t");

    /* LEFT */
  if(left_value > maxx_left) maxx_left = left_value;
  if(left_value < minn_left) minn_left = left_value;
  Serial.print(minn_left); // min = 0
  Serial.print("-");
  Serial.print(left_value);
  Serial.print("-");
  Serial.println(maxx_left);// max = 698

}
