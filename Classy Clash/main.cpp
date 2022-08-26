#include "Character.h"
#include "Enemy.h"
#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{2560};
    const int windowHeight{1440};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale{5.f};
    
    Character knight{windowWidth,windowHeight};

    Enemy goblin{
        Vector2{800.f, 800.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        //Draw Map
        DrawTextureEx(map,knight.GetWorldPos(),0.0f,mapScale,WHITE);

        knight.tick(GetFrameTime());
        goblin.tick(GetFrameTime());
        
        EndDrawing();
    }
    CloseWindow();
}
