#include "Character.h"
#include <raymath.h>

Character::Character(int winWidth, int winHeight)
{
    screenPos = {
        static_cast<float>(winWidth)/2.0f - scale * (0.5f * static_cast<float>(texture.width)/6.0f),
       static_cast<float>(winHeight)/2.0f - scale * (0.5f * static_cast<float>(texture.height))
   };
}

void Character::tick(float deltaTime)
{
    BaseCharacter::tick(deltaTime);

    //Movement input
    Vector2 direction{};
    if(IsKeyDown(KEY_A)) direction.x -= 1.0f;
    if(IsKeyDown(KEY_D)) direction.x += 1.0f;
    if(IsKeyDown(KEY_W)) direction.y -= 1.0f;
    if(IsKeyDown(KEY_S)) direction.y += 1.0f;

    if(Vector2Length(direction) != 0.0f)
    {
        //Set mapPos = mapPos - direction
        worldPos = Vector2Subtract(worldPos,Vector2Scale( Vector2Normalize(direction), moveSpeed));
        direction.x < 0.f ? rightLeft =-1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
}
