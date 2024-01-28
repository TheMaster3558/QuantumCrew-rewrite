#pragma once

#include "EZ-Template/api.hpp"


class EventHandler {
public:
    static void handleFlaps();
    static void handleCatapult();
    static void handleIntake();
    static void updateDisplay();
    static void handleAll();
};
