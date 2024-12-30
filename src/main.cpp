#include <iostream>

#include "PlayerCamera.h"
#include "Player.h"
#include "Setup.h"

#define MAX_FRAME_SPEED     15
#define MIN_FRAME_SPEED      1
int main()
{
    // Must be a better way to do this static? singleton?.
    Setup setup;
    setup.InitGame();

    Player player;
    player.pos = (Vector2) {setup.GetScreenWidth() / 2, setup.GetScreenHeight() / 2};
    player.speed = 350;

    PlayerCamera camera(player, setup.GetScreenWidth(), setup.GetScreenWidth());

    Image playerImage = LoadImage(RESOURCES_PATH"c_sprite.png");
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    Vector2 position = {setup.GetScreenWidth() / 2, setup.GetScreenHeight() / 2};
    Rectangle frameRec = {0, 0, (float)playerTexture.width / 2, (float)playerTexture.height};

    int currentFrame = 0;

    int framesCounter = 0;
    int framesSpeed = 4;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();
        framesCounter++;

        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 1) currentFrame = 0;

            frameRec.x = (float)currentFrame*(float)playerTexture.width/2;
        }

        // Control frames speed

        if (IsKeyPressed(KEY_RIGHT)) framesSpeed++;
        else if (IsKeyPressed(KEY_LEFT)) framesSpeed--;

        if (framesSpeed > MAX_FRAME_SPEED) framesSpeed = MAX_FRAME_SPEED;
        else if (framesSpeed < MIN_FRAME_SPEED) framesSpeed = MIN_FRAME_SPEED;

        player.UpdatePlayer(deltaTime);
        camera.UpdateCamera(player, deltaTime, setup.GetScreenWidth(), setup.GetScreenWidth());

        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera.GetCamera());

        // Draws an outline of the Frames and count
//        DrawTexture(playerTexture, 15, 40, WHITE);
//        DrawRectangleLines(15, 40, playerTexture.width, playerTexture.height, LIME);
//        DrawRectangleLines(15 + (int)frameRec.x, 40 + (int)frameRec.y, (int)frameRec.width, (int)frameRec.height, RED);

//        DrawText("FRAME SPEED: ", 165, 210, 10, DARKGRAY);
//        DrawText(TextFormat("%02i FPS", framesSpeed), 575, 210, 10, DARKGRAY);
//        DrawText("PRESS RIGHT/LEFT KEYS to CHANGE SPEED!", 290, 240, 10, DARKGRAY);

//        for (int i = 0; i < MAX_FRAME_SPEED; i++)
//        {
//            if (i < framesSpeed) DrawRectangle(250 + 21*i, 205, 20, 20, RED);
//            DrawRectangleLines(250 + 21*i, 205, 20, 20, MAROON);
//        }

//        DrawText("(c) playerTexture sprite by Eiden Marsal", setup.GetScreenWidth() - 200, setup.GetScreenHeight() - 20, 10, GRAY);

//        DrawRectangle(150,150,100,50,BLACK);
//        player.DrawPlayer();

        // Draw current Frame of the Texture
        DrawTextureRec(playerTexture, frameRec, position, WHITE);

        EndMode2D();

        EndDrawing();
    }

    UnloadTexture(playerTexture);

    CloseWindow();
    return 0;
}