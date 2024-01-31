#include "util/PID_controller.hpp"
#include <cstdint>

void rotationTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values);

void pivotTurn(double angle, double turnVoltage, double momentum, uint32_t timeout, bool isLeft, PIDvalues values);

void radiusTurn(double distance, double angle, double turnVoltage, double momentum, uint32_t timeout, PIDvalues values);