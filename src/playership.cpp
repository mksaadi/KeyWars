#include "playership.hpp"
#include <string>
#include <vector>




PlayerShip::PlayerShip()
{
    image_idx = 0;
    images = loadImages();
    image = images[0];
    LaserSound = LoadSound("Sounds/laser.ogg");
    speed = 3;
    alive = true;
    position.x = GetScreenWidth() / 2;
    position.y = GetScreenHeight() - 100;
    lastFireTime = 0.0;
    target_word = "";
}

std::vector<Texture2D> PlayerShip::loadImages()
{
    std::vector<Texture2D>imgs;
    for ( int i = 1; i <= 4; i++ )
    {
        std::string path = "assets/f" + std::to_string(i) + ".png";
        Texture2D image1 = LoadTexture(path.c_str());
        imgs.push_back(image1);
    }

    return imgs;
}

PlayerShip::~PlayerShip()
{

    for ( int i = 0; i < 4; i++ )
    {
        UnloadTexture(images[i]);
    }
    UnloadSound(LaserSound);
}

void PlayerShip::Draw(int idx)
{
    if ( alive )
    {
        DrawTextureV(images[idx], { position.x,position.y }, WHITE);
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

