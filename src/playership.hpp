#pragma once
#include<vector>
#include<string>
#include "raylib.h" 
#include "bullet.hpp"


class PlayerShip
{
    public:
    PlayerShip();
    ~PlayerShip();
    void Draw();
    void Move();
    char Fire();
    Rectangle GetRect();
    std::vector<Bullet>bullets;

    private:
    Texture2D image;
    Vector2 position;
    std::string target_word;
    int speed;
    bool alive;
    double lastFireTime;
    Sound LaserSound;
};

