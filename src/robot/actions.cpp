#include "robot.hpp"


bool leftFlapState = false;
bool rightFlapState = false;


void Actions::Flaps::setFlaps(bool left, bool right) {
    leftFlapState = left;
    rightFlapState = right;

    Pistons::leftFlap.set_value(left);
    Pistons::rightFlap.set_value(right);
};


void Actions::Flaps::reverseFlaps() {
    Actions::Flaps::setFlaps(!leftFlapState, !rightFlapState);
}


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
