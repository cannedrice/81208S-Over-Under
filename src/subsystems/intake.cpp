#include "main.h"

void updateIntake()
{
  if (l1.isPressed())
  {
    intake.moveVoltage(12000);
  }
  else if (l2.isPressed())
  {
    intake.moveVoltage(-12000);
  }
  else
  {
    intake.moveVoltage(0);
  }
}