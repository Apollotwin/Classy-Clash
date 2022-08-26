#include "Character.h"
#include "Enemy.h"
#include "Prop.h"
#include "raylib.h"
#include "raymath.h"

int main()
{
    const int windowWidth{2560};
    const int windowHeight{1440};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale{5.f};
    const float mapWidth = static_cast<float>(map.width) * mapScale;
    const float mapHeight = static_cast<float>(map.height)  * mapScale;
    
    
    Character knight{windowWidth,windowHeight};

    Prop props[2]
    {
        Prop{Vector2{800.f,800.f}, LoadTexture("Map/Rock.png"), 5.f},
        Prop{Vector2{600.f,600.f}, LoadTexture("Map/Log.png"), 5.f}
    };

    //Prop rock{Vector2{0.f,0.f}, LoadTexture("Map/Rock.png"), 5.f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        //Draw Map
        DrawTextureEx(map,Vector2Scale(knight.GetWorldPos(),-1.f),0.0f,mapScale,WHITE);

        for (auto prop : props)
        {
            prop.Render(knight.GetWorldPos());
        }
        
        knight.tick(GetFrameTime());

        //Check map bounds
        if( knight.GetWorldPos().x < 0.f ||
            knight.GetWorldPos().y < 0.f ||
            knight.GetWorldPos().x + windowWidth > mapWidth ||
            knight.GetWorldPos().y + windowHeight > mapHeight )
        {
            knight.UndoMovement();
        }
        
        EndDrawing();
    }
    CloseWindow();
}
