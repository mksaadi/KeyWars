#include <bits/stdc++.h>
#include "wordship.hpp"
#include <vector>
#include <string>
using namespace std;


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

WordShip::WordShip(Font f, Vector2 position, std::string word, int level)
{
    this->position = position;
    this->word = word;
    this->alive = true;
    this->speed = 0.2;
    this->typedCount = 0;
    this->velocity.x = GetRandomValue(-30, 30) / 100.0f;
    this->velocity.y = min(6.0f, float(speed + ( log2(level + 1) * 0.1f )));
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
    float spacing = 2;
    Vector2 drawPos = position;
    std::string typedPart = word.substr(0, typedCount);
    std::string untypedPart = word.substr(typedCount);

    if ( isTarget )
    {
        Vector2 textSize = MeasureTextEx(font, word.c_str(), fontSize, spacing);
        DrawRectangleV(position, { textSize.x, textSize.y }, Fade(ORANGE, 0.3f));
    }
    DrawTextEx(font, typedPart.c_str(), drawPos, fontSize, spacing, BLACK);
    // Calculate width of typed part so we can offset untyped part
    float typedWidth = MeasureTextEx(font, typedPart.c_str(), fontSize, spacing).x;
    drawPos.x += typedWidth;

    // Draw untyped part
    DrawTextEx(font, untypedPart.c_str(), drawPos, fontSize, spacing, WHITE);

}

void WordShip::Move()
{
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
    return { position.x,position.y,width + 10,50 };
}

Vector2 WordShip::GetCenter()
{
    float wordWidth = MeasureTextEx(font, word.c_str(), 30, 2).x;
    return { position.x + wordWidth / 2, position.y + 15 };
}
