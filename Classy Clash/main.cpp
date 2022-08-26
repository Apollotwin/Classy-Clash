#include "raylib.h"
#include "raymath.h"



int main()
{
    const int windowWidth{GetScreenWidth()};
    const int windowHeight{GetScreenHeight()};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale{3.5f};
    Vector2 mapPos{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        DrawTextureEx(map,mapPos,0.f,mapScale,WHITE);

        EndDrawing();
    }
    CloseWindow();
}
