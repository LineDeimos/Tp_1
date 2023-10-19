#include "BaseHero.h"

BaseHero::BaseHero(const std::string& name, const std::string& weapon, const std::string* skills, int numSkills)
    : name(name), weapon(weapon), numSkills(numSkills) {
    if (numSkills > MAX_SKILLS) {
        std::cerr << "Too many skills specified for " << name << ". Maximum allowed: " << MAX_SKILLS << std::endl;
        numSkills = MAX_SKILLS;
    }
    for (int i = 0; i < numSkills; i++) {
        this->skills[i] = skills[i];
    }
}

BaseHero::~BaseHero() { }

const std::string& BaseHero::GetName() const {
    return name;
}

const std::string& BaseHero::GetWeapon() const {
    return weapon;
}

const std::string* BaseHero::GetSkills() const {
    return skills;
}

int BaseHero::GetNumSkills() const {
    return numSkills;
}