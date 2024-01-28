#include <functional>
#include "pros/apix.h"


class Auton {
public:
    std::string name;
    std::function<void()> callback;

    Auton(std::string name, std::function<void()>& callback);
};


class Category {
public:
    std::string name;
    std::vector<Auton> autons;

    Category(std::string name, std::vector<Auton>* autons);
};
