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
    Vector2 position;
    Texture2D image;
    bool alive;
    int speed;
    double lastFireTime;
    std::string target_word;

    Sound LaserSound;
    private:
};

