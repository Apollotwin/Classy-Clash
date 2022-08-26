#include "Enemy.h"

Enemy::Enemy(Vector2 pos,Texture2D idle_texture, Texture2D run_texture) 
{
    screenPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;
}
