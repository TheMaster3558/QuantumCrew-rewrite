#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    Robot::chassis.calibrate();

    Robot::Motors::intake.tare_position();
    Robot::Motors::catapult.tare_position();
    Robot::Sensors::catapultRotationSensor.reset_position();
    // reset_position is currently bugged and doesn't work
    pros::delay(500);
    Robot::Tunables::catapultHoldAngle += Robot::Sensors::getCatapultAngle();

    Robot::Motors::intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    auton_selector::set_autons({
        auton_selector::Category("Offensive", {
            auton_selector::Auton("Nothing", Autons::doNothing),
            auton_selector::Auton("6 ball", Autons::offensive)
        }),
        auton_selector::Category("Defensive", {
            auton_selector::Auton("Qualifying", Autons::defensiveQual),
            auton_selector::Auton("Eliminations", Autons::defensiveElims)
        }),
        auton_selector::Category("Skills", {
            auton_selector::Auton("Skills", Autons::skills)
        })
    });
    auton_selector::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}


/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    Robot::Motors::setDriveBrake(pros::E_MOTOR_BRAKE_HOLD);
    auton_selector::call_selected_auton();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    Robot::Motors::setDriveBrake(pros::E_MOTOR_BRAKE_COAST);
    Robot::Actions::Flaps::setFlaps(false, false);

    while (true) {
        int leftY = Robot::controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = Robot::controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        Robot::chassis.arcade(leftY, rightX, 10.0);

        EventHandler::handleAll();

        pros::delay(ez::util::DELAY_TIME);
    }
}
