#pragma once

#include "raylib.h"
#include "wordship.hpp"


class Bullet
{
    public:
    Bullet(Texture2D bulletTexture, Vector2 startPos, WordShip* target, float speed, bool isPowerBullet);
    void Draw();
    void Update();
    Rectangle GetRect();
    bool active;
    bool isPowerBullet;
    WordShip* target;
    Vector2 position;
    Vector2 velocity;
    Texture2D bulletTexture;
    private:
    float speed;
};