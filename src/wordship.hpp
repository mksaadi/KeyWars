#pragma once
#include <string>
#include <vector>
#include "raylib.h" 

class WordShip
{
    public:
    WordShip();
    WordShip(Font f, Vector2 position, Texture2D image, std::string word, int level, bool isBoss, bool isMinionShip, Vector2 playership_position);

    ~WordShip();
    void Draw(bool isTarget);
    void Move();
    Rectangle GetRect();
    Vector2 GetCenter();
    std::string word;
    std::vector <Color> colors;
    Color color;
    Texture2D image;
    Vector2 position;
    Vector2 velocity;
    float speed;
    bool alive;
    bool isBoss;
    bool isMinionShip;
    int cur_target;
    int typedCount;
    char target_char;
    float horizontalSpeed;
    int horizontalDirection;
    float amplitude;
    float frequency;
    float startTime;
    Vector2 basePosition;
    Vector2 playership_position;

    private:
    Font font;

};