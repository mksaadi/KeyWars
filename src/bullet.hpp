#pragma once

#include "raylib.h"

class Bullet
{
    public:
    Bullet(Vector2 position, int speed);
    void Draw();
    void Update();
    bool active;
    Rectangle GetRect();
    private:
    Vector2 position;
    float speed;
};