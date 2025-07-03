#pragma once

#include "raylib.h"
#include "wordship.hpp"


class Bullet
{
    public:
    Bullet(Vector2 startPos, WordShip* target, float speed, bool isPowerBullet);
    void Draw();
    void Update();
    Rectangle GetRect();
    bool active;
    bool isPowerBullet;
    WordShip* target;
    Vector2 position;
    Vector2 velocity;
    private:
    float speed;
};