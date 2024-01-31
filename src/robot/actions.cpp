#include "robot.hpp"


bool Robot::Actions::Flaps::leftFlapState = false;
bool Robot::Actions::Flaps::rightFlapState = false;


void Robot::Actions::Flaps::setFlaps(bool left, bool right) {
    Robot::Actions::Flaps::leftFlapState = left;
    Robot::Actions::Flaps::rightFlapState = right;

    Robot::Pistons::leftFlap.set_value(left);
    Robot::Pistons::rightFlap.set_value(right);
};


void Robot::Actions::Flaps::reverseFlaps() {
    Robot::Actions::Flaps::setFlaps(!Robot::Actions::Flaps::leftFlapState, !Robot::Actions::Flaps::rightFlapState);
}


void Robot::Actions::Intake::intake() {
    Robot::Motors::intake.move(127);
}


void Robot::Actions::Intake::outtake() {
    Robot::Motors::intake.move(-127);
}


void Robot::Actions::Intake::brake() {
    Robot::Motors::intake.brake();
}


lemlib::PID Robot::Actions::Catapult::catapultPID(0.5, 0, 0);


void Robot::Actions::Catapult::lower() {
    Robot::Motors::catapult.move_velocity(Robot::Tunables::catapultVelocity);
}


void Robot::Actions::Catapult::stepToHoldAngle() {
    Robot::Motors::catapult.move(
            ez::util::sgn(Robot::Tunables::catapultVelocity) *
            Robot::Actions::Catapult::catapultPID.update(
                        Robot::Sensors::getCatapultAngle() - Robot::Tunables::catapultHoldAngle
                    )
    );
}


void Robot::Actions::Catapult::moveToHoldAngle() {
    while (abs(Robot::Sensors::getCatapultAngle() - Robot::Tunables::catapultHoldAngle) > 1.0) {
        stepToHoldAngle();
    }
    Robot::Actions::Catapult::brake();
}


void Robot::Actions::Catapult::brake() {
    Robot::Motors::catapult.brake();
}
