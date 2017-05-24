//Define Variables we'll be connecting to
double Setpoint = 0;
double LInput, LOutput, RInput, ROutput;

//Define the aggressive and conservative Tuning Parameters
double aggKp=5, aggKi=0.2, aggKd=1;
//double aggKp=4, aggKi=0.1, aggKd=1;
double consKp=1, consKi=0.05, consKd=0.25;

//Specify the links and initial tuning parameters
PID leftPID(&LInput, &LOutput, &Setpoint, aggKp, aggKi, aggKd, DIRECT);
PID rightPID(&RInput, &ROutput, &Setpoint, aggKp, aggKi, aggKd, DIRECT);

double pid_tranlation1(){
  return ((r5*4)+(r4*2)+(r3*1)) - ((r0*4)+(r1*2)+(r2*1)) * 10.0;
}

double pid_tranlationL(){
  return ((r0*48)+(r1*24)+(r2*20));
}          
double pid_tranlationR(){
  return ((r5*48)+(r4*24)+(r3*20));
}

