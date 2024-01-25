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
