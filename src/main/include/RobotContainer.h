// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/RunCommand.h>
#include <frc/Joystick.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/ElevatorLifter.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  Drivetrain m_drivetrain;
  ElevatorLifter m_evevator_lifter;
  frc::Joystick m_pilot_left{0};
  frc::Joystick m_pilot_right{1};
  frc2::RunCommand m_autonomousCommand{
            [this] {
                m_drivetrain.TankDrive(m_pilot_left.GetY(), m_pilot_right.GetY());
            },
            {&m_drivetrain}
        };

  void ConfigureButtonBindings();
};
