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
    UnloadTexture(explosionTexture);
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
    for ( auto& explosion : explosions )
    {
        explosion.Draw();
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
    for ( auto& explosion : explosions )
    {
        explosion.Update();
    }
    HandleTyping();
    DeleteInactiveBullets();
    DeleteInactiveWordShips();
    DeleteFinishedExplosions();
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
        }
    }
    // wordship vs wordship
    for ( int i = 0; i < wordships.size(); i++ )
    {
        for ( int j = i + 1; j < wordships.size(); j++ )
        {
            if ( CheckCollisionRecs(wordships[i].GetRect(), wordships[j].GetRect()) )
            {
                swap(wordships[i].velocity.x, wordships[j].velocity.x);
                swap(wordships[i].velocity.y, wordships[j].velocity.y);
                wordships[i].position.x += wordships[i].velocity.x * 5;
                wordships[j].position.x += wordships[j].velocity.x * 5;
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
                PlaySound(playership.LaserSound);
                Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
                playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 20.0f));

                wordships[target_idx].word.erase(wordships[target_idx].word.begin());
                if ( wordships[target_idx].word .size() == 0 )
                {
                    // trigger explosion
                    Vector2 explosionPos = wordships[target_idx].GetCenter();
                    explosions.emplace_back(&explosionTexture, explosionPos);
                    PlaySound(explosionSound);
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
            PlaySound(playership.LaserSound);
            wordships[target_idx].word.erase(wordships[target_idx].word.begin());

            // matched. So fire a bullet towards the wordship

            Vector2 shipCenter = { playership.position.x + playership.image.width / 2,playership.position.y };
            playership.bullets.push_back(Bullet(shipCenter, &wordships[target_idx], 20.0f));

            if ( wordships[target_idx].word .size() == 0 )
            {
                Vector2 explosionPos = wordships[target_idx].GetCenter();
                explosions.emplace_back(&explosionTexture, explosionPos);
                PlaySound(explosionSound);
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
        if ( wordships[i].word.empty() || !wordships[i].alive )continue;
        Rectangle rect = wordships[i].GetRect();
        if ( rect.y + rect.height < 0 )continue;

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
        bool targeted = false;
        for ( auto& bullet : playership.bullets )
        {
            if ( bullet.active && bullet.target == &( *it ) )
            {
                targeted = true;
                break;
            }
        }

        if ( !it->alive && !targeted )
        {
            it = wordships.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::DeleteFinishedExplosions()
{
    auto it = explosions.begin();
    while ( it != explosions.end() )
    {
        if ( it->isFinished() )
        {
            it = explosions.erase(it);
        }
        else
        {
            ++it;
        }
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
    explosionTexture = LoadTexture("assets/explosion.png");
    explosionSound = LoadSound("Sounds/explosion.ogg");
}


std::vector<WordShip> Game::CreateWordships()
{
    std::vector<WordShip> words;
    int numberOfShips = level * 10;
    for ( int i = 0; i < numberOfShips; i++ )
    {
        int idx = GetRandomValue(0, smallerwords.size() - 1);
        string word = smallerwords[idx];
        Vector2 pos = getPosition(word, words);
        words.push_back(WordShip(font, pos, word));
    }
    return words;
}

Vector2 Game::getPosition(string word, vector<WordShip>& existingWords)
{
    int attempts = 100;
    while ( attempts-- )
    {
        bool ok = true;
        float wordWidth = MeasureTextEx(font, word.c_str(), 30, 2).x;
        float posX = GetRandomValue(0, GetScreenWidth() - ( int )wordWidth);
        float posY = GetRandomValue(0, ( GetScreenHeight() / 2 ) - 500);
        float width = MeasureTextEx(font, word.c_str(), 50, 2).x;
        float height = 30.0;
        Rectangle cur_word_rect = Rectangle { posX,posY,width + 10,height + 10 };
        for ( auto& wordship : existingWords )
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
