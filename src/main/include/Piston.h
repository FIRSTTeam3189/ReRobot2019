#pragma once

#include <frc/WPILib.h>
#include <frc/Solenoid.h>

enum class PistonState {
    Extend,
    Retract,
};

class Piston
{
  private:
	frc::Solenoid *extended;
    frc::Solenoid *retracted;

  public:
    Piston(int extend, int retract);
	void Set(PistonState);
    PistonState Get();

	/**
	 * Toggles the state of the piston.f
	 */
	void Toggle();
};

