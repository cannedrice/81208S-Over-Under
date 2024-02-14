#include "subsystems/hang.hpp"

void updateHang()// wip but idea is that have the two buttons that were for blocker and hang instead just have this move to a predetermined position for ease of access and use the r1 and 2 to control the motor.
{
//pseudo code for now, assumes that reverse is going down and reg is going up
/*
    manual control

    if r1 is pressed
        if pot position is less than max
            set bool to false
            move hang motor full voltage
    if r2 is pressed
        if pot position is greater than min
            set bool to false
            move hang motor reverse full voltage

    preprogrammed position
    if up button is changed to pressed
        set a bool to true
    if bool is true and pot value is less than x
        move hang motor full voltage
    else if pot value is in the range
        stop motor
        set bool to false


    constraints so that i dont do something stupid and kill myself

    if pot position is greater than max
        move hang motor reverse full voltage
    if pot position is less than min
        move hang motor full voltage
*/
}