#include "playership.hpp"
#include <vector>
#include<string>



PlayerShip::PlayerShip()
{
    image = LoadTexture("assets/spaceship_1.png");
    speed = 3;
    alive = true;
    position.x = GetScreenWidth() / 2;
    position.y = GetScreenHeight() - 100;
    lastFireTime = 0.0;
    target_word = "";
}

PlayerShip::~PlayerShip()
{
    UnloadTexture(image);
}

void PlayerShip::Draw()
{
    if ( alive )
    {
        DrawTextureV(image, position, WHITE);
    }

}

void PlayerShip::Move()
{
    if ( IsKeyDown(KEY_UP) )
    {
        if ( position.y - speed >= 0 )
        {
            position.y -= speed;
        }
    }
    if ( IsKeyDown(KEY_DOWN) )
    {
        if ( position.y + speed + image.height <= GetScreenHeight() )
        {
            position.y += speed;
        }
    }
    if ( IsKeyDown(KEY_LEFT) )
    {
        if ( position.x - speed >= 0 )
        {
            position.x -= speed;
        }
    }
    if ( IsKeyDown(KEY_RIGHT) )
    {
        if ( position.x + speed + image.width <= GetScreenWidth() )
        {
            position.x += speed;
        }
    }
}

char  PlayerShip::Fire()
{
    int key = GetCharPressed();
    char cur_char = ( char )key;
    if ( key > 0 && key < 128 )
    {
        return cur_char;
    }
    return '\0';

}

Rectangle PlayerShip::GetRect()
{
    if ( alive )
    {
        Rectangle rect = Rectangle { position.x,position.y,image.width,image.height };
    }
    else
    {
        return { position.x,position.y,0,0 };
    }
}