#include "main.h"
bool counter = true;

void updatePneumatics()
{
    if (leftButton.changedToPressed())
    {
        toggleLeftWing();
    }
    if (rightButton.changedToPressed())
    {
        toggleRightWing();
    }
    if (downButton.changedToPressed())
    {
        globalWingState = !globalWingState;
        leftWing.set_value(globalWingState);
        rightWing.set_value(globalWingState);
    }
    if (upButton.changedToPressed())
    {
        toggleRatchet();
    }
    if (AButton.changedToPressed())
    {
        toggleRightRearWing();
    }
    if (YButton.changedToPressed())
    {
        toggleLeftRearWing();
    }
    if (XButton.changedToPressed())
    {
        togglePTO();
    }
    if (BButton.changedToPressed())
    {
        globalRearWingState = !globalRearWingState;
        leftRearWing.set_value(globalRearWingState);
        rightRearWing.set_value(globalRearWingState);
    }
}

/**
 * @brief opens the wing
 *
 */
void openLeftWing()
{
    leftWing.set_value(true);
    leftWingState = true;
}

/**
 * @brief opens the wing
 *
 */
void openRightWing()
{
    rightWing.set_value(true);
    rightWingState = true;
}

/**
 * @brief closes the wing
 *
 */
void closeLeftWing()
{
    leftWing.set_value(false);
    leftWingState = false;
}

/**
 * @brief closes the wing
 *
 */
void closeRightWing()
{
    rightWing.set_value(false);
    rightWingState = false;
}

/**
 * @brief toggles the wing
 *
 */
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

/**
 * @brief toggles the wing
 *
 */
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

/**
 * @brief opens the wing
 *
 */
void openLeftRearWing()
{
    leftRearWing.set_value(true);
    leftRearWingState = true;
}

/**
 * @brief closes the wing
 *
 */
void closeLeftRearWing()
{
    leftRearWing.set_value(false);
    leftRearWingState = false;
}

/**
 * @brief opens the wing
 *
 */
void openRightRearWing()
{
    rightRearWing.set_value(true);
    rightRearWingState = true;
}

/**
 * @brief closes the wing
 *
 */
void closeRightRearWing()
{
    rightRearWing.set_value(false);
    rightRearWingState = false;
}

/**
 * @brief toggles the wing
 *
 */
void toggleLeftRearWing()
{
    if (leftRearWingState == false)
    {
        openLeftRearWing();
    }
    else
    {
        closeLeftRearWing();
    }
}

/**
 * @brief toggles the wing
 *
 */
void toggleRightRearWing()
{
    if (rightRearWingState == false)
    {
        openRightRearWing();
    }
    else
    {
        closeRightRearWing();
    }
}

/**
 * @brief extend Blocker
 *
 */
void extendPTO()
{
    PTOPiston.set_value(true);
    PTOState = true;
}

/**
 * @brief retract Blocker
 *
 */
void retractPTO()
{
    PTOPiston.set_value(false);
    PTOState = false;
}

/**
 * @brief toggle Blocker
 *
 */
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

/**
 * @brief extend hang
 *
 */
void extendRatchet()
{
    ratchet.set_value(true);
    ratchetState = true;
}

/**
 * @brief retract hang
 *
 */

void retractRatchet()
{
    ratchet.set_value(false);
    ratchetState = false;
}

/**
 * @brief toggle hang
 *
 */
void toggleRatchet()
{
    if (ratchetState == false)
    {
        extendRatchet();
    }
    else
    {
        retractRatchet();
    }
}