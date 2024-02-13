#include "main.h"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    chassis.calibrate();

    Motors::intake.tare_position();
    Motors::catapult.tare_position();
    Sensors::catapultRotationSensor.reset_position();
    // reset_position is currently bugged and doesn't work
    pros::delay(500);
    Tunables::catapultHoldAngle += Sensors::getCatapultAngle();

    //Motors::intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    ms::set_autons({
        ms::Category("Tuning", {
            ms::Auton("Drive", Autons::tuneDrive),
            ms::Auton("Turn", Autons::tuneTurn)
        }),
        ms::Category("Offensive", {
            ms::Auton("Nothing", Autons::doNothing),
            ms::Auton("6 ball", Autons::offensive)
        }),
        ms::Category("Defensive", {
            ms::Auton("Qualifying", Autons::defensiveQual),
            ms::Auton("Eliminations", Autons::defensiveElims)
        }),
        ms::Category("Skills", {
            ms::Auton("Skills", Autons::skills)
        })
    });
    ms::initialize();
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
    Motors::setDriveBrake(pros::E_MOTOR_BRAKE_HOLD);
    ms::call_selected_auton();
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
    Motors::setDriveBrake(pros::E_MOTOR_BRAKE_COAST);
    Pistons::frontWings.set(false);
    Pistons::backWings.set(false);

    while (true) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        chassis.arcade(leftY, rightX, 10.0);

        EventHandler::handleAll();

        pros::delay(ez::util::DELAY_TIME);
    }
}
