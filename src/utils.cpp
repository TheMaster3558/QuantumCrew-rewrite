#include "utils.hpp"


ControllerDigitalIn::ControllerDigitalIn(
        pros::Controller controller,
        pros::controller_digital_e_t button)
        : controller(controller), button(button)
{

}


std::int32_t ControllerDigitalIn::get_new_press() {
    return controller.get_digital_new_press(button);
}


ControllerAutonSelector::ControllerAutonSelector(pros::Controller controller)
                                                 : AutonSelector(),
                                                 controller(controller){

};


void ControllerAutonSelector::print_selected_auton() {
    controller.print(0, 0, Autons[current_auton_page].Name.c_str());
}


void setAutonSelectorToController() {
    ControllerDigitalIn leftButton(Robot::controller, pros::E_CONTROLLER_DIGITAL_LEFT);
    ControllerDigitalIn rightButton(Robot::controller, pros::E_CONTROLLER_DIGITAL_RIGHT);
    ez::as::limit_switch_lcd_initialize(
            reinterpret_cast<pros::ADIDigitalIn*>(&leftButton),
            reinterpret_cast<pros::ADIDigitalIn*>(&rightButton)
    );
}


void removeAutonSelectorButtons() {
    ez::as::limit_switch_lcd_initialize(nullptr, nullptr);
}
