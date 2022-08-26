#include "BaseCharacter.h"

void BaseCharacter::tick(float deltaTime)
{
    //Update running time
    runningTime += GetFrameTime();
    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if(frame > maxFrames) frame = 0;
    }

    //Draw character
    Rectangle source{frame * static_cast<float>(texture.width)/6.0f,0.f,  rightLeft * static_cast<float>(texture.width)/6.0f, static_cast<float>(texture.height)};
    Rectangle dest{screenPos.x, screenPos.y, scale * static_cast<float>(texture.width)/6.0f, scale * static_cast<float>(texture.height)};
    DrawTexturePro(texture,source,dest, Vector2{}, 0.f, WHITE);
}
