const int TrackSensorLeft = 6; //左循迹
const int TrackSensorRight = 2; //右循迹

void trackSensorSetup()
{
  pinMode(TrackSensorLeft, INPUT);
  pinMode(TrackSensorRight, INPUT);
}

void trackSensorControl()
{
  int sl = digitalRead(TrackSensorLeft);
  int sr = digitalRead(TrackSensorRight);
  
  if (sl == HIGH && sr == HIGH)
  {
    goForward(0, 1);
  }
  else if (sl == HIGH && sr == LOW)
  {
    turnLeft(1);
  }
  else if (sl == LOW && sr == HIGH)
  {
    turnRight(1);
  }
  else
  {
    goForward(0,0);
  }
}
