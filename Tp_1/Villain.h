#pragma once
#include "BaseHero.h"

class Villain : public BaseHero {
private:
    std::string crime;
    std::string location;

public:
    Villain(const std::string& name, const std::string& weapon, const std::string& crime, const std::string& location, const std::string* skills, int numSkills);

    std::string GetCrime();

    std::string GetLocation();

    void DisplayInfo() const override;
};
