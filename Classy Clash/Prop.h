#pragma once
#include <raylib.h>

class Prop
{
public:
    Prop(Vector2 pos, float scale, Texture2D text);
    void Render(Vector2 knightPos);
    Rectangle GetCollisionRect(Vector2 knightPos);
private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale{};
};
