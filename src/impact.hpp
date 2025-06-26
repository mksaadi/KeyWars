#pragma once

#include "raylib.h" 

class Impact
{
    public:
    Impact(Texture2D* texture, Vector2 position);
    void Update();
    void Draw();
    bool isFinished() const;

    private:
    Texture2D* texture;
    Vector2 position;
    Rectangle frameRec;
    int currentFrame;
    int maxFrames;
    int framesCounter;
    bool active;
    float scale;
};