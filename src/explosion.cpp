#include "explosion.hpp"

Explosion::Explosion(Texture2D* tex, Vector2 pos, int cols, int rows, int speed) :
    texture(tex), position(pos), frameCols(cols), frameRows(rows), frameSpeed(speed)
{
    currentFrame = 0;
    currentRow = 0;
    frameCounter = 0;
    finished = false;
    frameRec.width = texture->width / frameCols;
    frameRec.height = texture->height / frameRows;
    frameRec.x = 0;
    frameRec.y = 0;

    position.x -= frameRec.width / 2;
    position.y -= frameRec.height / 2;
}

void Explosion::Update()
{
    if ( finished )
    {
        return;
    }
    frameCounter ++;
    if ( frameCounter >= frameSpeed )
    {
        currentFrame++;
        frameCounter = 0;
        if ( currentFrame >= frameCols )
        {
            currentFrame = 0;
            currentRow++;
            if ( currentRow >= frameRows )
            {
                finished = true;
            }
        }
    }
    frameRec.x = frameRec.width * currentFrame;
    frameRec.y = frameRec.height * currentRow;
}

void Explosion::Draw()
{
    if ( !finished )
    {
        DrawTextureRec(*texture, frameRec, position, WHITE);
    }
}
bool Explosion::isFinished()
{
    return finished;
}