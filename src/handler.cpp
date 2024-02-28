#include "handler.hpp"
#include "robot.hpp"


void EventHandler::handleWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        Pistons::frontLeftWing.set(true);
        Pistons::frontRightWing.set(true);
    }
    else {
        Pistons::frontLeftWing.set(false);
        Pistons::frontRightWing.set(false);
    }
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Pistons::rearLeftWing.set(true);
        Pistons::rearRightWing.set(true);
    }
    else {
        Pistons::rearLeftWing.set(false);
        Pistons::rearRightWing.set(false);
    }
}


void EventHandler::handleCatapult() {
    static bool autoLaunch = false;

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
        autoLaunch = !autoLaunch;
    }

    if (autoLaunch || controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        Actions::Catapult::lower();
    }
    else {
        Actions::Catapult::brake();
    }

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        Tunables::catapultVelocity--;
    }
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
        Tunables::catapultVelocity++;
    }
}


void EventHandler::handleIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        Actions::Intake::outtake();
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        Actions::Intake::intake();
    } else {
        Actions::Intake::brake();
    }
}


void EventHandler::handleCurve() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
        Tunables::driveCurve++;
    }
    else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        Tunables::driveCurve--;
    }
}


void EventHandler::updateDisplay() {
    static int counter = 0;
    if (counter++ % (50 / ez::util::DELAY_TIME) == 0) {
        controller.print(0, 0, "Curve: %d", Tunables::driveCurve);
    }
}


void EventHandler::handleAll() {
    EventHandler::handleWings();
    EventHandler::handleCatapult();
    EventHandler::handleIntake();
    EventHandler::updateDisplay();
}


