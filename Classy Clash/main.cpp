#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Enemy.h"
#include "Prop.h"

int main()
{
    const int windowWidth(1440);
    const int windowHeight(1280);
    InitWindow(windowWidth,windowHeight, "Classy Clash!");
    
    //Map
    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale = 2.f;
    const Vector2 mapSize {map.width * mapScale, map.height * mapScale};
    Vector2 mapPos{0.f,windowHeight - mapSize.y};

    //Characters
    Character knight{windowWidth,windowHeight};

    //Enemies
    Enemy goblin{
        Vector2{},
        3.2f,
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png"),
    };

    //Props
    const int amountOfProps{2};

    Prop props[amountOfProps]
    {
        Prop{Vector2{1000.f,800.f},4.f,LoadTexture("Map/Rock.png")},
        Prop{Vector2{1200.f,800.f},4.f,LoadTexture("Map/Log.png")}
    };
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        mapPos = Vector2Scale(knight.GetWorldPos(), -1.f);
        
        //Draw map
        DrawTextureEx(map,mapPos,0.0,mapScale,WHITE);

        //Draw Props
        for (int i = 0; i < amountOfProps; i++)
        {
            props[i].Render(knight.GetWorldPos());
        }

        //Draw Character
        knight.Tick(GetFrameTime());

        //Check map bounds
        if(knight.GetWorldPos().x < 0.f ||
            knight.GetWorldPos().y < 0.f ||
            knight.GetWorldPos().x + windowWidth > mapSize.x ||
            knight.GetWorldPos().y + windowHeight > mapSize.y)
        {
            knight.UndoMovement();
        }

        //Check prop collisions
        for (auto prop : props)
        {
            if(CheckCollisionRecs(prop.GetCollisionRect(knight.GetWorldPos()), knight.GetCollisionRect()))
            {
                knight.UndoMovement();
            }
        }

        goblin.Tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();
}
