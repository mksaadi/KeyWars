#pragma once
#include<vector>
#include "raylib.h" 
#include "bullet.hpp"


class PlayerShip
{
    public:
    PlayerShip();
    ~PlayerShip();
    void Draw();
    void Move();
    void Fire();
    Rectangle GetRect();
    char FindNextTarget(char cur_char);

    std::vector<Bullet>bullets;


    private:
    Texture2D image;
    Vector2 position;
    char cur_target;
    int speed;
    bool alive;
    double lastFireTime;
    Sound LaserSound;
};

