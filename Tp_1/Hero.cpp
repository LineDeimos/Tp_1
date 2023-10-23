#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name, const std::string& weapon, const std::string* skills, int numSkills)
    : BaseHero(name, weapon, skills, numSkills, CharacterType::TypeHero) { 
    std::cout << "Hero constructor called" << std::endl;
}

void Hero::DisplayInfo() const {
    std::cout << "Hero Name: " << name << std::endl;
    std::cout << "Weapon: " << weapon << std::endl;
    std::cout << "Skills:\n";
    for (int i = 0; i < numSkills; i++) {
        std::cout << "- " << skills[i] << std::endl;
    }
}