const int BarrierSensorLeft = 12; //左避障
const int BarrierSensorRight = 13; //右避障

void barrierSensorSetup()
{
  pinMode(BarrierSensorLeft, INPUT);
  pinMode(BarrierSensorRight, INPUT);
}

void barrierSensorControl()
{
  
  int sl = digitalRead(BarrierSensorLeft);
  int sr = digitalRead(BarrierSensorRight);
  
  if (sl == HIGH && sr == HIGH)
  {
    goForward(0, 1);
  }
  else if (sl == HIGH && sr == LOW)
  {
    turnLeft(100);
  }
  else if (sl == LOW && sr == HIGH)
  {
    turnRight(100);
  }
  else
  {
    goBackward(5,1);
    long r = random(10);
    if (r >= 2)
    {
      turnLeft(500);
    }
    else
    {
      turnRight(500);
    }
  }
}
