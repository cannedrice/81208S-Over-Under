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
        toggleLeftWing();
        toggleRightWing();
    }
    if (upButton.changedToPressed())
    {
        // toggleShooter();
        toggleBlocker();
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
        toggleHang();
    }
    if (BButton.changedToPressed())
    {
        toggleLeftRearWing();
        toggleRightRearWing();
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
 * @brief extend singleUse
 *
 */
void extendShooter()
{
    shooter.set_value(false);
    shooterState = true;
}

/**
 * @brief retract singleUse
 *
 */

void retractShooter()
{
    shooter.set_value(true);
    shooterState = false;
}

/**
 * @brief toggle singleUse
 *
 */
void toggleShooter()
{
    if (shooterState == false)
    {
        extendShooter();
    }
    else
    {
        retractShooter();
    }
}

/**
 * @brief extend free
 *
 */
void extendHang()
{
    hang.set_value(false);
    hangState = true;
}

/**
 * @brief retract free
 *
 */

void retractHang()
{
    hang.set_value(true);
    hangState = false;
}

/**
 * @brief toggle free
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