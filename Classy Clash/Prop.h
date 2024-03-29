﻿#pragma once
#include <raylib.h>

class Prop
{
public:
    Prop(Vector2 pos,Texture2D tex, float scale);
    void Render(Vector2 knightPos);
private:
    Texture2D texture{};
    Vector2 worldPos{};
    float scale{5.f};
};
