#include "Character.h"
#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{2560};
    const int windowHeight{1440};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale{5.f};
    
    Character newKnight{windowWidth,windowHeight};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        //Draw Map
        DrawTextureEx(map,newKnight.GetWorldPos(),0.0f,mapScale,WHITE);

        newKnight.tick(GetFrameTime());

        EndDrawing();
    }
    CloseWindow();
}
