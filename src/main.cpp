#include <iostream>

#include "PlayerCamera.h"
#include "Player.h"

const int screenWidth = 1200;
const int screenHeight = 900;
const char* screenTitle = "Raylib Test";
const char* text = "First Raylib Window";

int main(void)
{
    InitWindow(screenWidth, screenHeight, screenTitle);

    Player player;
    player.pos = (Vector2) {screenWidth / 2, screenHeight / 2};
    player.speed = 350;

    PlayerCamera camera(player, screenWidth, screenHeight);


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        player.UpdatePlayer(deltaTime);

        camera.UpdateCameraCenter(&player,deltaTime,screenWidth, screenHeight);
        camera.UpdateCameraCenterInsideMap(&player,deltaTime,screenWidth, screenHeight);
        camera.UpdateCameraCenterSmoothFollow(&player,deltaTime,screenWidth, screenHeight);
        camera.UpdateCameraPlayerBoundsPush(&player,deltaTime,screenWidth, screenHeight);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera.GetCamera());

        DrawRectangle(50,50,100,50,BLACK);

        player.DrawPlayer();

        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}