#include "autons.hpp"


void Autons::addAutons(AutonSelector autonSelector) {
    autonSelector.add_autons( {
        Auton("Do nothing", Autons::doNothing),
        Auton("Offensive", Autons::offensive),
        Auton("Defensive qualifying", Autons::defensiveQual),
        Auton("Defensive elimination", Autons::defensiveElims),
    });
}
