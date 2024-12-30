#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Player.h"

class PlayerCamera {
public:
    PlayerCamera(Player player, int screenWidth, int screenHeight);
    void UpdateCameraCenter(Player *player,  float delta, int width, int height);
    void UpdateCameraCenterInsideMap(Player *player,  float delta, int width, int height);
    void UpdateCameraCenterSmoothFollow(Player *player,  float delta, int width, int height);
    void UpdateCameraPlayerBoundsPush(Player *player,  float delta, int width, int height);
    float GetZoom();
    void SetZoom(float zoom);
    void AddZoom(float zoom);
    Camera2D GetCamera();
    void UpdateCamera(Player player,float deltaTime, int screenWidth, int screenHeight);
private:
    Camera2D camera;
};