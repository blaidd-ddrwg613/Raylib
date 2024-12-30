#pragma once
#include "raylib.h"
#include "raymath.h"

class Player {
public:
    Vector2 pos{};
    float speed{};
    Color color = RED;

    void UpdatePlayer(float delta);
    void DrawPlayer();
};