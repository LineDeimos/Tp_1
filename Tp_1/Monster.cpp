#include "Monster.h"
#include <iostream>

Monster::Monster(const std::string& name, const std::string& desc)
    : BaseHero(name, "", nullptr, 0), appearanceDescription(desc) { }

void Monster::DisplayInfo() const {
    std::cout << "Monster Name: " << name << std::endl;
    std::cout << "Appearance Description: " << appearanceDescription << std::endl;
}
