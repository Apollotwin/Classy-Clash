#include "raylib.h"
#include "raymath.h"



int main()
{
    const int windowWidth{GetScreenWidth()};
    const int windowHeight{GetScreenHeight()};
    InitWindow(windowWidth, windowHeight,"Classy Clash");

    const Texture2D map = LoadTexture("Map/Classy_Clash_map.png");
    const float mapScale{3.5f};
    Vector2 mapPos{0.0f,0.0f};

    //Movement
    float moveSpeed{10.0f};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GRAY);

        //Draw Map
        DrawTextureEx(map,mapPos,0.0f,mapScale,WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0f;
        if(IsKeyDown(KEY_D)) direction.x += 1.0f;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0f;
        if(IsKeyDown(KEY_S)) direction.y += 1.0f;

        if(Vector2Length(direction) != 0.0f)
        {
            //Set mapPos = mapPos - direction
            mapPos = Vector2Subtract(mapPos,Vector2Scale( Vector2Normalize(direction), moveSpeed));
        }

        EndDrawing();
    }
    CloseWindow();
}
