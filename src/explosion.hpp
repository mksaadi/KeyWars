#pragma once
#include "raylib.h" 


class Explosion
{
    public:
    Explosion(Texture2D* texture, Vector2 pos, int frameCols = 5, int frameRows = 5, int frameSpeed = 1);
    void Update();
    void Draw();

    bool isFinished();


    private:
    Texture2D* texture;
    Rectangle frameRec;
    Vector2 position;
    int frameCols, frameRows;
    int currentFrame, currentRow;
    int frameCounter, frameSpeed;
    bool finished;
    
};