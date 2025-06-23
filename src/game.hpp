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
    void HandleTyping();
    vector<WordShip>CreateWordships();
    Vector2 getPosition(string word);
    bool isRunning;
    int score;
    int highScore;
    int lives;
    int level;
    int target_idx;
    Music music;
    Font font;

    private:
    void DeleteInactiveBullets();
    void DeleteInactiveWordShips();
    int GetTargetWordIdx(char c);
    vector<WordShip>wordships;
    PlayerShip playership;
    WordShip wordship;
};