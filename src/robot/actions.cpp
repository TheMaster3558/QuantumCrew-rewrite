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


void Actions::Catapult::stepToHoldAngle() {
    Motors::catapult.move(
            catapultPID.update(
                    Tunables::catapultHoldAngle - Sensors::getCatapultAngle()
            )
    );
}


void Actions::Catapult::moveToHoldAngle() {
    while (abs(Sensors::getCatapultAngle() - Tunables::catapultHoldAngle) > 1.0) {
        stepToHoldAngle();
    }
    Actions::Catapult::brake();
}


void Actions::Catapult::brake() {
    Motors::catapult.brake();
}


void Actions::Wings::setFront(bool leftState, bool rightState) {
    Pistons::frontLeftWing.set(leftState);
    Pistons::frontRightWing.set(rightState);
}


void Actions::Wings::setBack(bool state) {
    Pistons::backWings.set(state);
}
