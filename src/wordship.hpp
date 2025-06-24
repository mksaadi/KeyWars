#pragma once
#include <string>
#include "raylib.h" 

class WordShip
{
    public:
    WordShip();
    WordShip(Font f, Vector2 position, std::string word);
    ~WordShip();
    void Draw(bool isTarget);
    void Move();
    Rectangle GetRect();
    Vector2 GetCenter();
    std::string word;
    Vector2 position;
    float speed;
    bool alive;
    int cur_target;
    char target_char;
    float horizontalSpeed;
    int horizontalDirection;
    float amplitude;
    float frequency;
    float startTime;
    Vector2 basePosition;

    private:
    Font font;

};