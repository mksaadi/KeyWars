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
    void ShowSettings(int x, int y);
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
        PAUSED,
        SETTINGS
    };
    GameState gameState;
    float levelStartTime;
    float levelDelay;
    float lastDeathTime;

    bool assestsLoaded;
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
    int idleTime;
    int lastPauseTime;
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
    int gameOverMenuItems;
    Music music;
    float musicVolume;
    Font font;
    Texture2D explosionTexture;
    Texture2D impactTexture;
    Texture2D powerUpTexture;
    Texture2D bulletTexture;
    Texture2D rocketTexture;
    Texture2D wordTexture;
    std::vector<Explosion>explosions;
    std::vector<Impact>impacts;

    private:
    void CheckCollisions();
    void CheckCollisionsBulletVsWordships();
    void CheckCollisionsWordshipsVsWordships();
    void CheckCollisionsWordshipVsPlayership();
    void DeleteInactiveBullets();
    void DeleteInactivePowerdUpBullets();
    void DeleteFinishedExplosions();
    void DeleteInactiveImpacts();
    void DeleteInactiveWordShips();
    void UpdateAllSoundVolumes();
    int GetTargetWordIdx(char c);
    bool isValid(int idx);

    bool isWordOutofScreen(int idx);
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
    Sound playerDeathSound;
    Sound powerUpFireSound;
    Sound nevigationSound;
    Sound selectSound;
    float soundVolume;

};