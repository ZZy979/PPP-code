#pragma once

#include <iostream>
#include <string>

struct God {
    std::string name, mythology, vehicle, weapon;
};

bool operator==(const God& g1, const God& g2);
bool operator<(const God& g1, const God& g2);
std::ostream& operator<<(std::ostream& os, const God& g);
