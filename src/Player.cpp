#include "Player.h"

void Player::UpdatePlayer(float delta)
{
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
    {
        this->pos.y -= this->speed * delta;
    }
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
    {
        this->pos.y += this->speed * delta;
    }
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        this->pos.x -= this->speed * delta;
    }
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        this->pos.x += this->speed * delta;
    }
}

void Player::DrawPlayer()
{
    Rectangle playerRect = {this->pos.x - 30, this->pos.y - 30, 30.0f, 30.0f};
    DrawRectangleRec(playerRect, this->color);
}