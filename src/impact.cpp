#include "impact.hpp"

Impact::Impact(Texture2D* texture, Vector2 position)
{
    this->texture = texture;
    this->position = position;
    this->maxFrames = 7;
    this->currentFrame = 0;
    this->framesCounter = 0;
    this->scale = 0.7f;
    this->active = true;

    frameRec.width = ( float )( texture->width / maxFrames ); // = 32
    frameRec.height = ( float )( texture->height );           // = 32
    frameRec.x = 0;
    frameRec.y = 0;
}


void Impact::Update()
{
    if ( !active ) return;

    framesCounter++;
    if ( framesCounter > 4 )  // adjust for desired speed
    {
        currentFrame++;
        if ( currentFrame >= maxFrames )
        {
            active = false;
            return;
        }
        framesCounter = 0;
    }

    frameRec.x = frameRec.width * currentFrame;
}

void Impact::Draw()
{
    if ( !active ) return;

    DrawTexturePro(*texture,
                   frameRec,
                   { position.x, position.y, frameRec.width * scale, frameRec.height * scale },
                   { ( frameRec.width * scale ) / 2, ( frameRec.height * scale ) / 2 },
                   0.0f,
                   WHITE);
}


bool Impact::isFinished() const
{
    return !active;
}