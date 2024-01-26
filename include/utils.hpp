#include <cstdint>
#include "pros/misc.hpp"
#include "EZ-Template/auton_selector.hpp"
#include "robot.hpp"


// this class mimics pros::ADIDigitalIn
class ControllerDigitalIn {
private:
    pros::Controller controller;
    pros::controller_digital_e_t button;
public:
    ControllerDigitalIn(pros::Controller controller, pros::controller_digital_e_t button);
    std::int32_t get_new_press();
};


class ControllerAutonSelector : public AutonSelector {
private:
    pros::Controller controller;
public:
    ControllerAutonSelector(pros::Controller controller);
    void print_selected_auton();
};


void setAutonSelectorToController();
void removeAutonSelectorButtons();
