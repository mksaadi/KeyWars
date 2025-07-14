#include <bits/stdc++.h>
#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
using namespace std;

#include "game.hpp"


const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;


int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "KeyWars");
    SetTargetFPS(60);
    InitAudioDevice();
    srand(time(NULL));


    Texture2D background = LoadTexture("assets/Starfield_1.png");
    // if ( background.id == 0 ) {
    //     TraceLog(LOG_ERROR, "Failed to load background image!");
    // }

    float bgY = 0.0f;
    auto UpdateBackground = [&] () {
        float scaleX = ( float )WINDOW_WIDTH / background.width;
        float scaleY = ( float )WINDOW_HEIGHT / background.height;
        float scale = std::max(scaleX, scaleY);
        float bgDrawHeight = background.height * scale;
        bgY += 0.5f; // scroll speed
        if ( bgY >= bgDrawHeight )
            bgY = 0;
        };
    auto DrawBackground = [&] () {
        float scaleX = ( float )WINDOW_WIDTH / background.width;
        float scaleY = ( float )WINDOW_HEIGHT / background.height;
        float scale = std::max(scaleX, scaleY);
        float bgDrawHeight = background.height * scale;
        // Draw two copies for seamless vertical scrolling
        DrawTextureEx(background, { 0, bgY }, 0.0f, scale, WHITE);
        DrawTextureEx(background, { 0, bgY - bgDrawHeight }, 0.0f, scale, WHITE);
        };


    Font font = LoadFont("fonts/FunnelDisplay-VariableFont_wght.ttf");


    Game game(font);

    while ( !WindowShouldClose() && !game.shouldClose )
    {
        BeginDrawing();
        if ( !game.isPaused )UpdateBackground();
        DrawBackground();
        game.Draw();
        game.Update();
        game.HandleInput();
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    UnloadFont(font);
    UnloadTexture(background);
    return 0;
}