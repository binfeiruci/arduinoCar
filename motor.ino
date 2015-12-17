const int MotorLeftEn = 5;
const int MotorLeftForward = 15;
const int MotorLeftReverse = 14;
const int MotorRightEn = 3;
const int MotorRightForward = 16;
const int MotorRightReverse = 17;

const int speedArr[6][2] = {
  {0,0},
  {125,110},
  {170,170},
  {200,200},
  {230,230},
  {255,255}
};

void motorSetup()
{
  pinMode(MotorLeftEn, OUTPUT);
  pinMode(MotorLeftForward, OUTPUT);
  pinMode(MotorLeftReverse, OUTPUT);
  pinMode(MotorRightEn, OUTPUT);
  pinMode(MotorRightForward, OUTPUT);
  pinMode(MotorRightReverse, OUTPUT);
}

void go(int direction, int speed)
{
  switch (direction)
  {
    case 0:
      goForward(0, 0);
      break;
    case 1:
      goForward(0, speed);
      break;
    case 2:
      goBackward(0, speed);
      break;
    case 3:
      turnLeft(0);
      break;
    case 4:
      turnRight(0);
      break;
  }
}

void goForward(int time, int speed)
{
  digitalWrite(MotorLeftForward, HIGH);
  digitalWrite(MotorLeftReverse, LOW);
  digitalWrite(MotorRightForward, HIGH);
  digitalWrite(MotorRightReverse, LOW);
  
  analogWrite(MotorLeftEn, speedArr[speed][0]);
  analogWrite(MotorRightEn, speedArr[speed][1]);
  
  delay(time * 100);
}

void goBackward(int time, int speed)
{
  digitalWrite(MotorLeftForward, LOW);
  digitalWrite(MotorLeftReverse, HIGH);
  digitalWrite(MotorRightForward, LOW);
  digitalWrite(MotorRightReverse, HIGH);
  
  analogWrite(MotorLeftEn, speedArr[speed][0]);
  analogWrite(MotorRightEn, speedArr[speed][1]);
  
  delay(time * 100);
}

void turnLeft(int time)
{
  digitalWrite(MotorLeftForward, LOW);
  digitalWrite(MotorLeftReverse, LOW);
  digitalWrite(MotorRightForward, HIGH);
  digitalWrite(MotorRightReverse, LOW);
  
  analogWrite(MotorLeftEn, 0);
  analogWrite(MotorRightEn, speedArr[1][1]);
  
  delay(time);
}

void turnRight(int time)
{
  digitalWrite(MotorLeftForward, HIGH);
  digitalWrite(MotorLeftReverse, LOW);
  digitalWrite(MotorRightForward, LOW);
  digitalWrite(MotorRightReverse, LOW);
  
  analogWrite(MotorLeftEn, speedArr[1][0]);  
  analogWrite(MotorRightEn, 0);
  
  delay(time);
}
