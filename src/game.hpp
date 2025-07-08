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
    void Initialize();
    void InitGame();
    void LoadAssets();
    void HandleTyping();
    void ShowResult(int yOffset);
    void ShowWords(string str, int yOffset);
    void ShowPowerUps();
    void ShowProgressbar();
    void ActivatePowerup();
    vector<WordShip>CreateWordships();
    void CreateMiniWordShips(Vector2 position, int level);
    enum GameState
    {
        MAIN_MENU,
        SHOW_NEXT_LEVEL,
        PLAYING,
        LEVEL_COMPLETED,
        GAME_OVER,
        PAUSED
    };
    GameState gameState;
    float levelStartTime;
    float levelDelay;
    float lastDeathTime;


    bool canPowerUp;
    bool hasMissTyped;
    bool shouldClose;
    bool isPaused;
    bool bossCreated;
    bool bossIsDead;
    int powerUps;
    int score;
    int wordTyped;
    int timeSpentTyping;
    int typingStartTime;
    int wpm;
    int totalKeyStrokes;
    int successfulKeyStrokes;
    int numWordsWithoutMiss;
    int accuracy;
    int highScore;
    int lives;
    int level;
    int target_idx;
    int menuSelection;
    int totalMenuItems;
    Music music;
    Font font;
    Texture2D explosionTexture;
    Texture2D impactTexture;
    Texture2D powerUpTexture;
    std::vector<Explosion>explosions;
    std::vector<Impact>impacts;

    private:
    void CheckCollisions();
    void DeleteInactiveBullets();
    void DeleteInactivePowerdUpBullets();
    void DeleteFinishedExplosions();
    void DeleteInactiveImpacts();
    void DeleteInactiveWordShips();
    int GetTargetWordIdx(char c);
    bool isValid(int idx);
    int LoadHighScore();
    void SaveHighScore(int curScore);
    vector<WordShip>wordships;
    PlayerShip playership;
    WordShip wordship;
    Sound explosionSound;
    Sound impactSound;
    Sound errorSound;
    Sound powerUpSound;
    Sound levelCompleteSound;
    Sound gameOverSound;
};