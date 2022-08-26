#pragma once
#include <raylib.h>

class BaseCharacter
{
public:
    virtual void tick(float deltaTime);
    void SetPosition(int x, int y);
    Vector2 GetWorldPos(){return worldPos;}

protected:
    //Texture variables
    Texture2D texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("characters/knight_run_spritesheet.png");
    float scale{5.f};
    
    //Movement variables
    float moveSpeed{10.f};
    
    //Position variables
    Vector2 screenPos{};
    Vector2 worldPos{};

    //Animation variables
    float rightLeft{1.f};
    float runningTime{};
    float frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};
};
