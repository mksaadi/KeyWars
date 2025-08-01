#include "bullet.hpp"
#include "raymath.h"

Bullet::Bullet(Texture2D bulletTexture, Vector2 startPos, WordShip* target, float speed, bool isPowerBullet)
{
    this->bulletTexture = bulletTexture;
    this->position = startPos;
    this->speed = speed;
    this->target = target;
    this-> active = true;
    this->isPowerBullet = isPowerBullet;
    if ( target )
    {
        Vector2 direction = Vector2Subtract(target->GetCenter(), position);
        if ( Vector2Length(direction) > 0.001f )
        {
            velocity = Vector2Scale(Vector2Normalize(direction), speed);
        }
        else
        {
            velocity = { 0,-speed };
        }
    }
    else
    {
        active = false;
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
    if ( Vector2Length(direction) > 0.001f )
    {
        velocity = Vector2Scale(Vector2Normalize(direction), speed);
    }
    else
    {
        velocity = { 0,-speed };
    }
    position = Vector2Add(position, velocity);
}
void Bullet::Draw()
{

    float angle = atan2f(velocity.y, velocity.x) * RAD2DEG + 90.0f;
    float scale = ( isPowerBullet ? 3.0f : 1.0f );
    Vector2 origin = { ( float )bulletTexture.width / 2,( float )bulletTexture.height / 2 };
    DrawTextureEx(bulletTexture, { position.x - origin.x, position.y - origin.y }, angle, scale, WHITE);

}

Rectangle Bullet::GetRect()
{
    float scale = ( isPowerBullet ? 3.0f : 1.0f );
    if ( active )
    {
        return { position.x - ( ( bulletTexture.width * scale ) / 2 ), ( position.y - ( ( bulletTexture.height * scale ) / 2 ) ),
            bulletTexture.width * scale, bulletTexture.height * scale };
    }
    else
    {
        return { position.x, position.y, 0.0f, 0.0f };
    }
}