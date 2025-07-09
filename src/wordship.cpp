#include <bits/stdc++.h>
#include "raylib.h"
#include "raymath.h"
#include "wordship.hpp"
#include <vector>
#include <string>


WordShip::WordShip()
{
    word = "";
    position = { 0, 0 };
    speed = 0.0f;
    alive = false;
    cur_target = 0;
    target_char = '.';
    font = GetFontDefault();
}

WordShip::WordShip(Font f, Vector2 position, Texture2D image, std::string word, int level, bool isBoss, bool isMinionShip, Vector2 playership_position)
{
    Vector2 direction = Vector2Subtract(playership_position, position);
    this->position = position;
    this->image = image;
    this->playership_position = playership_position;
    this->word = word;
    this->isBoss = isBoss;
    this->isMinionShip = isMinionShip;
    this->alive = true;
    this->colors = { WHITE,BLUE,YELLOW,GREEN,MAGENTA };
    this->color = colors[GetRandomValue(0, 4)];
    if ( isMinionShip )
    {
        float baseSpeed = 0.8f;
        float scale = 0.6f;
        this->speed = std::min(8, ( int )( baseSpeed + scale * ( log2(level + 1) ) ));
    }
    else
    {
        this->speed = 0.2;
        this->velocity.x = GetRandomValue(-30, 30) / 100.0f;
        this->velocity.y = std::min(6.0f, float(speed + ( log2(level + 1) * 0.1f )));
    }
    this->typedCount = 0;
    this->cur_target = 0;
    this->font = f;
    this->horizontalSpeed = GetRandomValue(1, 2);
    this->horizontalDirection = GetRandomValue(0, 1) ? 1 : -1;
    this->basePosition = position;
    this->amplitude = GetRandomValue(10, 20);
    this->frequency = GetRandomValue(1, 2);
    this->startTime = GetTime();
}


WordShip::~WordShip()
{

}

void WordShip::Draw(bool isTarget)
{
    if ( !alive )return;
    float fontSize = 30;
    if ( isTarget || isMinionShip )
    {
        fontSize = 40;
    }
    float spacing = 2;
    std::string typedPart = word.substr(0, typedCount);
    std::string untypedPart = word.substr(typedCount);

    Vector2 textSize = MeasureTextEx(font, word.c_str(), fontSize, spacing);
    Vector2 drawPos = position;
    Vector2 imageDrawPos = { position.x + ( textSize.x / 2 ) - image.width,position.y + image.height };
    if ( isTarget )
    {
        DrawRectangleV(position, { textSize.x, textSize.y }, Fade(ORANGE, 0.3f));
    }
    DrawTextEx(font, typedPart.c_str(), drawPos, fontSize, spacing, BLACK);
    // Calculate width of typed part so we can offset untyped part
    float typedWidth = MeasureTextEx(font, typedPart.c_str(), fontSize, spacing).x;
    drawPos.x += typedWidth;

    // Draw untyped part
    DrawTextEx(font, untypedPart.c_str(), drawPos, fontSize, spacing, WHITE);
    if ( isBoss )
    {
        DrawTextureEx(image, imageDrawPos, 0, 2, color);
    }
    else
    {
        DrawTextureV(image, imageDrawPos, color);
    }
}

void WordShip::Move()
{
    if ( isBoss || isMinionShip )
    {
        Vector2 direction = Vector2Subtract(playership_position, position);
        if ( Vector2Length(direction) > 0.1 )
        {
            velocity = Vector2Scale(Vector2Normalize(direction), speed);
            position = Vector2Add(position, velocity);
        }
        return;
    }
    position.x += velocity.x;
    position.y += velocity.y;
    if ( position.y > GetScreenHeight() )
    {
        alive = false;
    }
    float wordWidth = GetRect().width;
    if ( position.x < 0 || position.x + wordWidth > GetScreenWidth() )
    {
        velocity.x *= -1;
        position.x = std::max(0.0f, std::min(position.x, GetScreenWidth() - wordWidth));
    }
}


Rectangle WordShip::GetRect()
{
    float width = MeasureTextEx(font, word.c_str(), 50, 2).x;
    return { position.x,position.y,width + 15,50 };
}

Vector2 WordShip::GetCenter()
{
    return { position.x + image.width / 2, position.y + image.height / 2 };
}
