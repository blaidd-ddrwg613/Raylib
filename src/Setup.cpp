#include "Setup.h"

void Setup::InitGame()
{
    InitWindow(screenWidth, screenHeight, screenTitle);
}

float Setup::GetScreenWidth()
{
    return screenWidth;
}

float Setup::GetScreenHeight()
{
    return screenHeight;
}
