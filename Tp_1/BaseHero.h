#pragma once
#include <iostream>
#include <string>

const int MAX_SKILLS = 5;

class BaseHero {
public:
    BaseHero(const std::string& name, const std::string& weapon, const std::string* skills, int numSkills);

    virtual ~BaseHero();

    virtual void DisplayInfo() const = 0;

    const std::string& GetName() const;

    const std::string& GetWeapon() const;

    const std::string* GetSkills() const;

    int GetNumSkills() const;

protected:
    std::string name;
    std::string weapon;
    std::string skills[MAX_SKILLS];
    int numSkills;
};