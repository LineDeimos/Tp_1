#include "Monster.h"
#include <iostream>

Monster::Monster(const std::string& name, const std::string& desc)
    : BaseHero(name, "", nullptr, 0, CharacterType::TypeMonster), appearanceDescription(desc) { }

std::string Monster::GetAppearanceDescription()
{
    return appearanceDescription;
}

void Monster::DisplayInfo() const {
    std::cout << "Monster Name: " << name << std::endl;
    std::cout << "Appearance Description: \n" << appearanceDescription << std::endl;
}
