#pragma once

#include "raylib.h"

class Bullet
{
    public:
    Bullet(Vector2 position, Vector2 targetPos, float speed);
    void Draw();
    void Update();
    bool active;
    Rectangle GetRect();
    private:
    Vector2 position;
    Vector2 velocity;
    float speed;
};