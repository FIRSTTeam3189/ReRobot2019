// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "Constants.h"

Drivetrain::Drivetrain() {
  InitHardware();
}

void Drivetrain::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void Drivetrain::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void Drivetrain::InitHardware(){
  frontLeft = new WPI_TalonSRX(DRIVE_LEFT_FRONT);
  frontRight = new WPI_TalonSRX(DRIVE_RIGHT_FRONT);
  backLeft = new WPI_TalonSRX(DRIVE_LEFT_BACK);
  backRight = new WPI_TalonSRX(DRIVE_RIGHT_BACK);

  //  Resets all the settings on the talon. Talons have a long memory, and this prevents problems with random settings still on the talons. Trust me, it has happened.
  frontLeft->ConfigFactoryDefault();
  frontRight->ConfigFactoryDefault();
  backLeft->ConfigFactoryDefault();
  backRight->ConfigFactoryDefault();

  backLeft->SetInverted(true);
  frontLeft->SetInverted(true);

  backLeft->Set(ControlMode::Follower, frontLeft->GetDeviceID());
  backRight->Set(ControlMode::Follower, frontRight->GetDeviceID());

  backRight->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
  frontLeft->ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::QuadEncoder, 0, 0);
}

void Drivetrain::TankDrive(double left, double right) {
  frontLeft->Set(left);
  frontRight->Set(right);
}
