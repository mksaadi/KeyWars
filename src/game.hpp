#pragma once
#include"raylib.h"  
#include <vector>
#include <string>
#include"playership.hpp"
#include"wordship.hpp"  
#include "explosion.hpp"
#include "impact.hpp"
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
    enum GameState {
        PLAYING,
        LEVEL_COMPLETED,
        SHOW_NEXT_LEVEL
    };
    GameState gameState;
    float levelStartTime;
    float levelDelay;
   
    bool isRunning;
    int score;
    int highScore;
    int lives;
    int level;
    int target_idx;
    Music music;
    Font font;
    Texture2D explosionTexture;
    Texture2D impactTexture;
    std::vector<Explosion>explosions;
    std::vector<Impact>impacts;

    private:
    void CheckCollisions();
    void DeleteInactiveBullets();
    void DeleteFinishedExplosions();
    void DeleteInactiveWordShips();
    int GetTargetWordIdx(char c);
    vector<WordShip>wordships;
    PlayerShip playership;
    WordShip wordship;
    Sound explosionSound;
    Sound impactSound;
};