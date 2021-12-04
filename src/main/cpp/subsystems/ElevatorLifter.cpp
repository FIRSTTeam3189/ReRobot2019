// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ElevatorLifter.h"
#include "Constants.h"

ElevatorLifter::ElevatorLifter() {
    lifter = new Piston(ELEVATOR_LIFER_EXTEND, ELEVATOR_LIFER_RETRACT);
}

// This method will be called once per scheduler run
void ElevatorLifter::Periodic() {}

void ElevatorLifter::Toggle(){
    lifter->Toggle();
}
