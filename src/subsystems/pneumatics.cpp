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
        toggleBlocker();
    }
    if (XButton.changedToPressed())
    {
        toggleHang();
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
 * @brief extend Blocker
 *
 */
void extendBlocker()
{
    blocker.set_value(true);
    blockerState = true;
}

/**
 * @brief retract Blocker
 *
 */
void retractBlocker()
{
    blocker.set_value(false);
    blockerState = false;
}

/**
 * @brief toggle Blocker
 *
 */
void toggleBlocker()
{
    if (blockerState == false)
    {
        extendBlocker();
    }
    else
    {
        retractBlocker();
    }
}

/**
 * @brief extend hang
 *
 */
void extendHang()
{
    hang.set_value(true);
    hangState = true;
}

/**
 * @brief retract hang
 *
 */

void retractHang()
{
    hang.set_value(false);
    hangState = false;
}

/**
 * @brief toggle hang
 *
 */
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