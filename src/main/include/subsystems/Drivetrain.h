// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;
  void InitHardware();
  void TankDrive(double left, double right);

 private:
 WPI_TalonSRX *backRight;
 WPI_TalonSRX *frontRight;
 WPI_TalonSRX *backLeft;
 WPI_TalonSRX *frontLeft;
 
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
