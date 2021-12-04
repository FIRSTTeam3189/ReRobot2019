#include "Piston.h"

Piston::Piston(int extend, int retract){
    extended = new frc::Solenoid(extend);
    retracted = new frc::Solenoid(retract);
}

void Piston::Set(PistonState state) {
    if (state == PistonState::Extend) {
        extended->Set(true);
        retracted->Set(false);
    }else{
        extended->Set(false);
        retracted->Set(true);
    }
}

PistonState Piston::Get(){
    if (extended->Get()) {
        return PistonState::Extend;
    }else{
        return PistonState::Retract;
    }
}

void Piston::Toggle() {
    extended->Set(!extended->Get());
    retracted->Set(!extended->Get());
}