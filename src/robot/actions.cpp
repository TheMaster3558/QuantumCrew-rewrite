#include "robot.hpp"


void Actions::Intake::intake() {
    Motors::intake.move(127);
}


void Actions::Intake::outtake() {
    Motors::intake.move(-127);
}


void Actions::Intake::brake() {
    Motors::intake.brake();
}


lemlib::PID catapultPID(5, 0, 0);


void Actions::Catapult::lower() {
    Motors::catapult.move_velocity(Tunables::catapultVelocity);
}


void Actions::Catapult::brake() {
    Motors::catapult.brake();
}


void Actions::Wings::setFront(bool leftState, bool rightState) {
    Pistons::frontLeftWing.set(leftState);
    Pistons::frontRightWing.set(rightState);
}


void Actions::Wings::setRear(bool leftState, bool rightState) {
    Pistons::rearLeftWing.set(leftState);
    Pistons::rearRightWing.set(rightState);
}
