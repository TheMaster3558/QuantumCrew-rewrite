#include "autons.hpp"


void Autons::addAutons(AutonSelector autonSelector) {
    autonSelector.add_autons({
        Auton("Do nothing", Autons::doNothing),
        Auton("Defensive qualifying", Autons::defensiveQual),
        Auton("Defensive elimination", Autons::defensiveElims),
        Auton("Offensive qualifying", Autons::offensiveQual),
        Auton("Offensive elimination", Autons::offensiveElims),
    });
}
