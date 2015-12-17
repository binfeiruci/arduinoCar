#include <IRremote.h>
const int IrReceiver = 11;
IRrecv irrecv(IrReceiver);
decode_results results;

const long Forward = 0x20DF02FD;
const long Backward = 0x20DF827D;
const long Left = 0x20DFE01F;
const long Right = 0x20DF609F;
const long LongPress = 0xFFFFFFFF;

void irSetup()
{
  irrecv.enableIRIn(); // Start the receiver
}

void irControl()
{
  int direction = 100;
  unsigned long lastReceive;
  while (direction)
  {
    if (irrecv.decode(&results))
    {
      lastReceive = millis();
      Serial.println(results.value, HEX);
      switch (results.value)
      {
        case Forward:
          direction = 1;
          break;
        case Backward:
          direction = 2;
          break;
        case Left:
          direction = 3;
          break;
        case Right:
          direction = 4;
          break;
        case LongPress:
          break;
        default:
          direction = 0;
          break;
      }
      go(direction, 1);
      irrecv.resume();
    }
    else
    {
      if (millis() - lastReceive > 100)
        go(0, 0);
    }
  }
}
