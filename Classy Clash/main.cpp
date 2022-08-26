#include <xutility>

#include "raylib.h"
#include "raymath.h"



int main()
{
    const int windowWidth{2560};
    const int windowHeight{1440};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float scale{5.f};
    Vector2 mapPos{0.0f,0.0f};

    //Movement
    float moveSpeed{10.0f};

    //Character
    Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    Vector2 knightPos{
         static_cast<float>(windowWidth)/2.0f - scale * (0.5f * static_cast<float>(knight.width)/6.0f),
        static_cast<float>(windowHeight)/2.0f - scale * (0.5f * static_cast<float>(knight.height)),
    };

    //Animation
    float rightLeft{1.f};
    float runningTime{ };
    float frame{};
    const int maxFrames{6};
    const float updateTime{1.f/12.f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        //Draw Map
        DrawTextureEx(map,mapPos,0.0f,scale,WHITE);

        //Update running time
        runningTime += GetFrameTime();
        if(runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if(frame > maxFrames) frame = 0;
        }

        //Draw character
        Rectangle source{frame * static_cast<float>(knight.width)/6.0f,0.f,  rightLeft * static_cast<float>(knight.width)/6.0f, static_cast<float>(knight.height)};
        Rectangle dest{knightPos.x, knightPos.y, scale * static_cast<float>(knight.width)/6.0f, scale * static_cast<float>(knight.height)};
        DrawTexturePro(knight,source,dest, Vector2{}, 0.f, WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0f;
        if(IsKeyDown(KEY_D)) direction.x += 1.0f;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if(IsKeyDown(KEY_S)) direction.y += 1.0f;

        if(Vector2Length(direction) != 0.0f)
        {
            //Set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos,Vector2Scale( Vector2Normalize(direction), moveSpeed));
            direction.x < 0.f ? rightLeft =-1.f : rightLeft = 1.f;
            knight = knight_run;
        }
        else
        {
            knight = knight_idle;
        }

        EndDrawing();
    }
    CloseWindow();
}
