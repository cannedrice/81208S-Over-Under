#include "main.h"
bool counter = true;

void updatePneumatics()
{
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
}

// /**
//  * @brief opens the wing
//  *
//  */
// void openLeftWing()
// {
//     leftWing.set_value(true);
//     leftWingState = true;
// }

// /**
//  * @brief opens the wing
//  *
//  */
// void openRightWing()
// {
//     rightWing.set_value(true);
//     rightWingState = true;
// }

// /**
//  * @brief closes the wing
//  *
//  */
// void closeLeftWing()
// {
//     leftWing.set_value(false);
//     leftWingState = false;
// }

// /**
//  * @brief closes the wing
//  *
//  */
// void closeRightWing()
// {
//     rightWing.set_value(false);
//     rightWingState = false;
// }

// /**
//  * @brief toggles the wing
//  *
//  */
// void toggleLeftWing()
// {
//     if (leftWingState == false)
//     {
//         openLeftWing();
//     }
//     else
//     {
//         closeLeftWing();
//     }
// }

// /**
//  * @brief toggles the wing
//  *
//  */
// void toggleRightWing()
// {
//     if (rightWingState == false)
//     {
//         openRightWing();
//     }
//     else
//     {
//         closeRightWing();
//     }
// }

// /**
//  * @brief extend Blocker
//  *
//  */
// void extendBlocker()
// {
//     blocker.set_value(true);
//     blockerState = true;
// }

// /**
//  * @brief retract Blocker
//  *
//  */
// void retractBlocker()
// {
//     blocker.set_value(false);
//     blockerState = false;
// }

// /**
//  * @brief toggle Blocker
//  *
//  */
// void toggleBlocker()
// {
//     if (blockerState == false)
//     {
//         extendBlocker();
//     }
//     else
//     {
//         retractBlocker();
//     }
// }

// /**
//  * @brief extend hang
//  *
//  */
// void extendHang()
// {
//     hang.set_value(true);
//     hangState = true;
// }

// /**
//  * @brief retract hang
//  *
//  */

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
