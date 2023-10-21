#pragma once
#include "BaseHero.h"

class Monster : public BaseHero {
private:
    std::string appearanceDescription;

public:
    Monster(const std::string& name, const std::string& desc);

    std::string GetAppearanceDescription();

    void DisplayInfo() const override;
};
