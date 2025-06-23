#include "bullet.hpp"
#include "raymath.h"

Bullet::Bullet(Vector2 position, Vector2 targetPos, float speed)
{
    this->position = position;
    this->speed = speed;
    active = true;

    Vector2 direction = Vector2Subtract(targetPos, position);
    direction = Vector2Normalize(direction);

    velocity = Vector2Scale(direction, speed);
}

void Bullet::Update()
{
    if ( !active )return;
    position = Vector2Add(position, velocity);

    if ( position.y<0 || position.y >GetScreenHeight() || position.x<0 || position.x > GetScreenWidth() )
    {
        active = false;
    }
}
void Bullet::Draw()
{
    if ( active )
    {
        DrawRectangle(position.x, position.y, 4, 15, BLUE);
    }
}

Rectangle Bullet::GetRect()
{
    if ( active )
    {
        return { position.x, position.y, 4.0, 15.0 };
    }
    else
    {
        return{ position.x, position.y, 0.0, 0.0 };
    }
}