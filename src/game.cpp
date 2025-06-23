#include "game.hpp"
#include <string>
#include "bullet.hpp"
using namespace std;

vector<string>smallerwords =
{
    "go","come","back","not","far","away","chose","rise","wise","lazy","loser","win","lose",
    "eat","drink","party","live","life","earn","buy","sell","full","empty","full","laugh","right",
    "wrong","teach","write","read","sleep","reap","sow","left","antiestablishmentarianism"
};

Game::Game(Font f) :font(f)
{
    InitGame();
}

Game::~Game()
{
    UnloadFont(font);
}

void Game::Draw()
{
    playership.Draw();
    for ( auto& word : wordships )
    {
        word.Draw();
    }
    for ( auto& bullet : playership.bullets )
    {
        bullet.Draw();
    }

}

void Game::Update()
{
    for ( auto& word : wordships )
    {
        word.Move();
    }
    for ( auto& bullet : playership.bullets )
    {
        bullet.Update();
    }
}

void Game::HandleInput()
{
    playership.Move();
    playership.Fire();
}

void Game::InitGame()
{
    score = 0;
    highScore = 0;
    isRunning = true;
    lives = 3;
    level = 1;
    wordships = CreateWordships();
}

std::vector<WordShip> Game::CreateWordships()
{
    std::vector<WordShip> words;
    int numberOfShips = level * 5;
    for ( int i = 0; i < numberOfShips; i++ )
    {
        int idx = GetRandomValue(0, smallerwords.size() - 1);
        string word = smallerwords[idx];
        Vector2 pos = getPosition(word);
        words.push_back(WordShip(font, pos, word));
    }
    return words;
}

Vector2 Game::getPosition(string word)
{
    int attempts = 100;
    while ( attempts-- )
    {
        bool ok = true;
        float posX = GetRandomValue(0, GetScreenWidth() / 2);
        float posY = GetRandomValue(0, GetScreenHeight() / 2);
        float width = MeasureTextEx(font, word.c_str(), 50, 2).x;
        float height = 30.0;
        Rectangle cur_word_rect = Rectangle { posX,posY,width + 10,height + 10 };
        for ( auto& wordship : wordships )
        {
            if ( CheckCollisionRecs(cur_word_rect, wordship.GetRect()) )
            {
                ok = false;
                break;
            }
        }
        if ( ok )return { posX,posY };
    }
    return{ 0,0 };
}
