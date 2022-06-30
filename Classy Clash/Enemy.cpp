#include "Enemy.h"

Enemy::Enemy(Vector2 pos, float move_speed, Texture2D idle_texture, Texture2D run_texture) 
{
    worldPos = pos;
    moveSpeed = move_speed;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
    width = texture.width/maxFrames;
    height = texture.height;
}

void Enemy::Tick(float deltaTime)
{
    worldPosLastFrame = worldPos;
    
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
