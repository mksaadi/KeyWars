#pragma once
#include"raylib.h"  
#include"playership.hpp"
#include"wordship.hpp"  
#include <vector>
#include <string>
using namespace std;

class Game
{
    public:
    Game(Font f);
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    void InitGame();
    vector<WordShip>CreateWordships();
    Vector2 getPosition(string word);
    bool isRunning;
    int score;
    int highScore;
    int lives;
    int level;
    Music music;
    Font font;

    private:
    vector<WordShip>wordships;
    PlayerShip playership;
    WordShip wordship;
};