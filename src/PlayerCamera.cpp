#include "PlayerCamera.h"
#include "Player.h"

PlayerCamera::PlayerCamera(Player player, int screenWidth, int screenHeight) {

    camera = { 0 };
    camera.target = player.pos;
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.5f;

}

void PlayerCamera::UpdateCameraCenter(Player *player, float delta, int width, int height)
{
    camera.offset = (Vector2){ width/2.0f, height/2.0f };
    camera.target = player->pos;
}

void PlayerCamera::UpdateCameraCenterInsideMap(Player *player, float delta, int width, int height)
{
    camera.target = player->pos;
    camera.offset = (Vector2){ width/2.0f, height/2.0f };
    float minX = 1000, minY = 1000, maxX = -1000, maxY = -1000;

    Vector2 max = GetWorldToScreen2D((Vector2){ maxX, maxY }, camera);
    Vector2 min = GetWorldToScreen2D((Vector2){ minX, minY }, camera);

    if (max.x < width) camera.offset.x = width - (max.x - width/2);
    if (max.y < height) camera.offset.y = height - (max.y - height/2);
    if (min.x > 0) camera.offset.x = width/2 - min.x;
    if (min.y > 0) camera.offset.y = height/2 - min.y;
}

void PlayerCamera::UpdateCameraCenterSmoothFollow(Player *player, float delta, int width,int height)
{
    static float minSpeed = 30;
    static float minEffectLength = 10;
    static float fractionSpeed = 0.8f;

    camera.offset = (Vector2){ width/2.0f, height/2.0f };
    Vector2 diff = Vector2Subtract(player->pos, camera.target);
    float length = Vector2Length(diff);

    if (length > minEffectLength)
    {
        float speed = fmaxf(fractionSpeed*length, minSpeed);
        camera.target = Vector2Add(camera.target, Vector2Scale(diff, speed*delta/length));
    }
}

void PlayerCamera::UpdateCameraPlayerBoundsPush(Player *player, float delta, int width, int height)
{
    static Vector2 bbox = {0.2f, 0.2f};

    Vector2 bboxWorldMin = GetScreenToWorld2D((Vector2) {(1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height},
                                              camera);
    Vector2 bboxWorldMax = GetScreenToWorld2D((Vector2) {(1 + bbox.x) * 0.5f * width, (1 + bbox.y) * 0.5f * height},
                                              camera);
    camera.offset = (Vector2) {(1 - bbox.x) * 0.5f * width, (1 - bbox.y) * 0.5f * height};

    if (player->pos.x < bboxWorldMin.x) camera.target.x = player->pos.x;
    if (player->pos.y < bboxWorldMin.y) camera.target.y = player->pos.y;
    if (player->pos.x > bboxWorldMax.x) camera.target.x = bboxWorldMin.x + (player->pos.x - bboxWorldMax.x);
    if (player->pos.y > bboxWorldMax.y) camera.target.y = bboxWorldMin.y + (player->pos.y - bboxWorldMax.y);
}

void PlayerCamera::UpdateCamera(Player player, float deltaTime, int screenWidth, int screenHeight)
{
    UpdateCameraCenter(&player,deltaTime,screenWidth, screenHeight);
    UpdateCameraCenterInsideMap(&player,deltaTime,screenWidth, screenHeight);
    UpdateCameraCenterSmoothFollow(&player,deltaTime,screenWidth, screenHeight);
    UpdateCameraPlayerBoundsPush(&player,deltaTime,screenWidth, screenHeight);
}

float PlayerCamera::GetZoom()
{
    return camera.zoom;
}

void PlayerCamera::SetZoom(float zoom)
{
    camera.zoom = zoom;
}

void PlayerCamera::AddZoom(float zoom)
{
    camera.zoom += zoom;
}

Camera2D PlayerCamera::GetCamera()
{
    return camera;
}