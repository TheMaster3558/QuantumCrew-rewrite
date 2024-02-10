#include "robot.hpp"


void Actions::Flaps::setFlaps(Flap flap, FlapState state) {
    std::unique_ptr<pros::ADIDigitalOut> leftFlap;
    std::unique_ptr<pros::ADIDigitalOut> rightFlap;

    if (flap == FRONT) {
        leftFlap = std::make_unique<pros::ADIDigitalOut>(Pistons::frontLeftFlap);
        rightFlap = std::make_unique<pros::ADIDigitalOut>(Pistons::frontRightFlap);
    }
    else {
        leftFlap = std::make_unique<pros::ADIDigitalOut>(Pistons::backLeftFlap);
        rightFlap = std::make_unique<pros::ADIDigitalOut>(Pistons::backRightFlap);
    }

    leftFlap->set_value(state.first);
    rightFlap->set_value(state.second);
}


FlapState reverseState(FlapState state) {
    state.first = !state.first;
    state.second = !state.second;
    return state;
}


void Actions::Flaps::reverseFlaps(Flap flap) {
    static FlapState frontFlapStates = makeFlapState(false, false);
    static FlapState backFlapStates = makeFlapState(false, false);

    FlapState state = (flap == FRONT) ? frontFlapStates : backFlapStates;
    Actions::Flaps::setFlaps(flap, reverseState(state));
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
