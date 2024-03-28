#include "main.h"
bool counter = true;

void updatePneumatics()
{
    /*left control pad*/
    if (rightButton.changedToPressed())
    {
        toggleRightRearWing();
    }
    if (leftButton.changedToPressed())
    {
        toggleLeftRearWing();
    }
    if (downButton.changedToPressed())
    {
        globalRearWingState = !globalRearWingState;
        leftRearWing.set_value(globalRearWingState);
        rightRearWing.set_value(globalRearWingState);
    }

    /*right control pad*/
    if (YButton.changedToPressed())
    {
        toggleLeftWing();
    }
    if (AButton.changedToPressed())
    {
        toggleRightWing();
    }
    if (BButton.changedToPressed())
    {
        globalWingState = !globalWingState;
        leftWing.set_value(globalWingState);
        rightWing.set_value(globalWingState);
    }    

    /*--other--*/
    if(r1.changedToPressed()){
        toggleHang();
    }
    if(r2.changedToPressed()){
        togglePTO();
    }
}

/*--Front Wings--*/
void openLeftWing()
{
    leftWing.set_value(true);
    leftWingState = true;
}

void openRightWing()
{
    rightWing.set_value(true);
    rightWingState = true;
}

void closeLeftWing()
{
    leftWing.set_value(false);
    leftWingState = false;
}

void closeRightWing()
{
    rightWing.set_value(false);
    rightWingState = false;
}

void toggleLeftWing()
{
    if (leftWingState == false)
    {
        openLeftWing();
    }
    else
    {
        closeLeftWing();
    }
}

void toggleRightWing()
{
    if (rightWingState == false)
    {
        openRightWing();
    }
    else
    {
        closeRightWing();
    }
}

/*--Rear Wings--*/
void openLeftRearWing()
{
    leftRearWing.set_value(true);
    leftRearWingState = true;
}

void openRightRearWing()
{
    rightRearWing.set_value(true);
    rightRearWingState = true;
}

void closeLeftRearWing()
{
    leftRearWing.set_value(false);
    leftRearWingState = false;
}

void closeRightRearWing()
{
    rightRearWing.set_value(false);
    rightRearWingState = false;
}

void toggleLeftRearWing()
{
    if (leftRearWingState == false)
    {
        openLeftWing();
    }
    else
    {
        closeLeftWing();
    }
}

void toggleRightRearWing()
{
    if (rightRearWingState == false)
    {
        openRightWing();
    }
    else
    {
        closeRightWing();
    }
}

/*--Hang & PTO--*/
void extendHang()
{
    leftHang.set_value(true);
    rightHang.set_value(true);
    hangState = true;
}

void retractHang()
{
    leftHang.set_value(false);
    rightHang.set_value(false);
    hangState = false;
}

void toggleHang()
{
    if (hangState == false)
    {
        extendHang();
    }
    else
    {
        retractHang();
    }
}

void extendPTO()
{
    frontPTO.set_value(true);
    backPTO.set_value(true);
    PTOState = true;
}

void retractPTO()
{
    frontPTO.set_value(false);
    backPTO.set_value(false);
    PTOState = false;
}

void togglePTO()
{
    if (PTOState == false)
    {
        extendPTO();
    }
    else
    {
        retractPTO();
    }
}