#include "bullet.hpp"
#include "raymath.h"

Bullet::Bullet(Vector2 startPos, WordShip* target, float speed, bool isPowerBullet)
{
    this->position = startPos;
    this->speed = speed;
    this->target = target;
    this-> active = true;
    this->isPowerBullet = isPowerBullet;
    if ( target )
    {
        Vector2 direction = Vector2Subtract(target->GetCenter(), position);
        velocity = Vector2Scale(Vector2Normalize(direction), speed);
    }

}

void Bullet::Update()
{
    if ( !active || !target || !target->alive )
    {
        active = false;
        return;
    }
    Vector2 direction = Vector2Subtract(target->GetCenter(), position);
    velocity = Vector2Scale(Vector2Normalize(direction), speed);
    position = Vector2Add(position, velocity);
    if ( position.y < 0 || position.y > GetScreenHeight() || position.x < 0 || position.x > GetScreenWidth() ) {
        active = false;
    }
}
void Bullet::Draw()
{
    if ( active ) {
        if ( isPowerBullet )
        {
            DrawCircleV(position, 8, RED);
        }
        else
        {
            DrawCircleV(position, 6, SKYBLUE);
        }
    }
}

Rectangle Bullet::GetRect()
{
    if ( active )
    {
        return { position.x - 6, position.y - 6, 12.0f, 12.0f }; // diameter-based bounding box
    }
    else
    {
        return { position.x, position.y, 0.0f, 0.0f };
    }
}