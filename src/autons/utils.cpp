#include "autons.hpp"


void Autons::utils::moveRelative(double distance, int timeout, bool forwards) {
    lemlib::Pose pose = chassis.getPose(true);
    double angle = -pose.theta + M_PI_2;
    double x = std::cos(angle) * distance;
    double y = std::sin(angle) * distance;
    chassis.moveToPoint(pose.x + x, pose.y + y, timeout, forwards);
}


void Autons::utils::waitUntilBelowBar() {
    while (Sensors::getIntakeUpInches() > 3) {
        pros::delay(ez::util::DELAY_TIME);
    }
}
