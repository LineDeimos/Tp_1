#pragma once
#include "BaseHero.h"

class Hero : public BaseHero {
public:
    Hero(const std::string& name, const std::string& weapon, const std::string* skills, int numSkills);

    void DisplayInfo() const override;
};
