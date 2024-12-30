#include <iostream>

#include "PlayerCamera.h"
#include "Player.h"
#include "Setup.h"



int main(void)
{
    Setup setup;
    Player player;
    player.pos = (Vector2) {setup.GetScreenWidth() / 2, setup.GetScreenHeight() / 2};
    player.speed = 350;

    PlayerCamera camera(player, setup.GetScreenWidth(), setup.GetScreenWidth());


    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        player.UpdatePlayer(deltaTime);
        camera.UpdateCamera(player, deltaTime, setup.GetScreenWidth(), setup.GetScreenWidth());

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera.GetCamera());

        DrawRectangle(150,150,100,50,BLACK);

        player.DrawPlayer();

        EndMode2D();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}