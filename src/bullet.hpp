#pragma once

#include "raylib.h"
#include "wordship.hpp"


class Bullet
{
    public:
    Bullet(Vector2 startPos, WordShip* target, float speed);
    void Draw();
    void Update();
    Rectangle GetRect();
    bool active;
    WordShip* target;
    private:
    Vector2 position;
    Vector2 velocity;
    float speed;
};