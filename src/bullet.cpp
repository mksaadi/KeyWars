#include "bullet.hpp"

Bullet::Bullet(Vector2 position, int speed)
{
    this->position = position;
    this->speed = speed;
    active = true;
}

void Bullet::Update()
{
    if ( !active )return;
    position.y += speed;
    if ( position.y > GetScreenHeight() - 100 || position.y - 25 < 0 )
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