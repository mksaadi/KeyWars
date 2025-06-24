#include "game.hpp"
#include <string>
#include "bullet.hpp"
#include <iostream> 
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
    for ( int i = 0; i < ( int )wordships.size(); i++ )
    {
        wordships[i].Draw(i == target_idx);
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
    HandleTyping();
    DeleteInactiveBullets();
    DeleteInactiveWordShips();
    CheckCollisions();
}

void Game::CheckCollisions()
{
    if ( target_idx == -1 )
    {
        return;
    }
    // bullets vs wordships
    for ( auto& bullet : playership.bullets )
    {
        if ( CheckCollisionRecs(bullet.GetRect(), wordships[target_idx].GetRect()) )
        {
            bullet.active = false;
        }
    }
    // wordship vs playership

    for ( auto& wordship : wordships )
    {
        if ( CheckCollisionRecs(wordship.GetRect(), playership.GetRect()) )
        {
            playership.alive = false;
            lives--;
            if ( lives == 0 )
            {
                
            }
        }
    }
}

void Game::HandleTyping()
{
    char typed = playership.Fire();
    if ( typed == '\0' )return;
    if ( wordships.empty() )
    {
        std::cout << "Level Completed\n";
        return;
    }
    if ( target_idx == -1 && !wordships[target_idx].alive )
    {
        target_idx = -1;
    }
    if ( target_idx == -1 )
    {
        target_idx = GetTargetWordIdx(typed);
        if ( target_idx != -1 )
        {
            if ( wordships[target_idx].word[0] == typed )
            {
                // matched. So fire a bullet towards the wordship
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };

                float wordWidth = MeasureTextEx(font, wordships[target_idx].word.c_str(), 30, 2).x;

                Vector2 wordCenter = { wordships[target_idx].position.x + wordWidth / 2, wordships[target_idx].position.y + 30 };
                playership.bullets.push_back(Bullet(shipCenter, wordCenter, 10.0f));


                wordships[target_idx].word.erase(wordships[target_idx].word.begin());
                if ( wordships[target_idx].word .size() == 0 )
                {
                    wordships[target_idx].alive = false;
                    target_idx = -1;
                }
            }
        }
    }
    else
    {
        if ( wordships[target_idx].word[0] == typed )
        {
            wordships[target_idx].word.erase(wordships[target_idx].word.begin());

            // matched. So fire a bullet towards the wordship
            Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };

            float wordWidth = MeasureTextEx(font, wordships[target_idx].word.c_str(), 30, 2).x;
            Vector2 wordCenter = { wordships[target_idx].position.x + wordWidth / 2, wordships[target_idx].position.y + 30 };
            playership.bullets.push_back(Bullet(shipCenter, wordCenter, 20.0f));

            if ( wordships[target_idx].word .size() == 0 )
            {
                wordships[target_idx].alive = false;
                target_idx = -1;
            }
        }
    }
}

int Game::GetTargetWordIdx(char typed)
{
    for ( int i = 0; i < ( int )wordships.size(); i++ )
    {
        if ( wordships[i].word[0] == typed )
        {
            return i;
        }
    }
    return -1;
}


void Game::DeleteInactiveBullets()
{

    auto it = playership.bullets.begin();
    while ( it != playership.bullets.end() )
    {
        if ( !it->active )
        {
            it = playership.bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::DeleteInactiveWordShips()
{
    auto it = wordships.begin();
    while ( it != wordships.end() )
    {
        if ( !it->alive )
        {
            it = wordships.erase(it);
        }
        else ++it;
    }
}

void Game::HandleInput()
{
    playership.Move();
}

void Game::InitGame()
{
    score = 0;
    highScore = 0;
    isRunning = true;
    lives = 3;
    level = 1;
    target_idx = -1;
    wordships = CreateWordships();
}


std::vector<WordShip> Game::CreateWordships()
{
    std::vector<WordShip> words;
    int numberOfShips = level * 10;
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
        float wordWidth = MeasureTextEx(font, word.c_str(), 30, 2).x;
        float posX = GetRandomValue(0, GetScreenWidth() - ( int )wordWidth);
        float posY = GetRandomValue(0, ( GetScreenHeight() / 2 ) - 200);
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
