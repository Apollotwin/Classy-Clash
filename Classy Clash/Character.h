#pragma once
#include "BaseCharacter.h"

class Character : public BaseCharacter
{
public:
    Character(int windowWidth, int windowHeight);
    void Tick(float deltaTime);
private:
    
};
