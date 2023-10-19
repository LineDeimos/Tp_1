#pragma once
#include "BaseHero.h"

class Monster : public BaseHero {
private:
    std::string appearanceDescription;

public:
    Monster(const std::string& name, const std::string& desc);

    void DisplayInfo() const override;
};
