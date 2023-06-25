#include "god.h"

bool operator==(const God& g1, const God& g2) {
    return g1.name == g2.name;
}

bool operator<(const God& g1, const God& g2) {
    return g1.name < g2.name;
}

std::ostream& operator<<(std::ostream& os, const God& g) {
    return os << '(' << g.name << ',' << g.mythology << ',' << g.vehicle << ',' << g.weapon << ')';
}
