#pragma once

#include "raylib.h"
#include "iostream"

class Setup {

public:
    void InitGame();
    float GetScreenWidth();
    float GetScreenHeight();

private:
    int screenWidth = 1200;
    int screenHeight = 900;
    char* screenTitle = "Raylib Test";
};
