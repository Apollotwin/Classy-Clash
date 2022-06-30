#include "Character.h"
#include "raylib.h"
#include "raymath.h"

Character::Character(int windowWidth, int windowHeight)
{
    width = texture.width/maxFrames;
    height = texture.height;
    screenPos = {
        windowWidth/2.0f - scale * (0.5f * width),
        windowHeight/2.0f - scale * (0.5f * height)
    };
}

void Character::Tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
    Vector2 direction{};
    if(IsKeyDown(KEY_A)) direction.x -= 1.0;
    if(IsKeyDown(KEY_D)) direction.x += 1.0;
    if(IsKeyDown(KEY_W)) direction.y -= 1.0;
    if(IsKeyDown(KEY_S)) direction.y += 1.0;

    if(Vector2Length(direction) != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), moveSpeed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }

    //Update animation frame
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if(frame > maxFrames) frame = 0;
    }
        
    //Draw characters
    Rectangle source{frame * width, 0.f,rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height };
    DrawTexturePro(texture, source,dest, Vector2{}, 0.f, WHITE);
}
