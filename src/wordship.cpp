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

WordShip::WordShip(Font f, Vector2 position, std::string word)
{
    this->position = position;
    this->word = word;
    alive = true;
    speed = 0.5;
    cur_target = 0;
    font = f;
    horizontalSpeed = GetRandomValue(1, 2);
    horizontalDirection = GetRandomValue(0, 1) ? 1 : -1;
    basePosition = position;
    amplitude = GetRandomValue(10, 30);
    frequency = GetRandomValue(1, 3);
    startTime = GetTime();

}


WordShip::~WordShip()
{

}

void WordShip::Draw(bool isTarget)
{
    if ( !alive )return;
    float fontSize = 30;
    float spacing = 2;
    Vector2 textSize = MeasureTextEx(font, word.c_str(), fontSize, spacing);

    if ( isTarget )
    {
        DrawRectangleV(position, { textSize.x,textSize.y }, Fade(YELLOW, 0.3f));
        DrawTextEx(font, word.c_str(), position, fontSize, spacing, YELLOW);
    }
    else
    {
        DrawTextEx(font, word.c_str(), position, fontSize, spacing, WHITE);
    }

}

void WordShip::Move()
{
    position.y += speed;
    if ( position.y > GetScreenHeight() )
    {
        alive = false;
    }
    float width = MeasureTextEx(font, word.c_str(), 50, 2).x;
    position.x += horizontalSpeed * horizontalDirection;
    if ( position.x <= 0 || position.x + width >= GetScreenWidth() )
    {
        horizontalDirection *= -1;
    }
    float t = GetTime() - startTime;
    position.x = basePosition.x + sin(t * frequency) * amplitude;

}
Rectangle WordShip::GetRect()
{
    float width = MeasureTextEx(font, word.c_str(), 50, 2).x;
    return { position.x,position.y,width + 10,50 };
}