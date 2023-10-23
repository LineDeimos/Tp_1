#include "Villain.h"
#include <iostream>

Villain::Villain(const std::string& name, const std::string& weapon, const std::string& crime, const std::string& location, const std::string* skills, int numSkills)
    : BaseHero(name, weapon, skills, numSkills, CharacterType::TypeVillain), crime(crime), location(location) { 
    std::cout << "Villain constructor called" << std::endl;
}

std::string Villain::GetCrime()
{
    return crime;
}

std::string Villain::GetLocation()
{
    return location;
}

void Villain::DisplayInfo() const {
    std::cout << "Villain Name: " << name << std::endl;
    std::cout << "Weapon: " << weapon << std::endl;
    std::cout << "Crime: " << crime << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Skills:\n";
    for (int i = 0; i < numSkills; i++) {
        std::cout << "- " << skills[i] << std::endl;
    }
}