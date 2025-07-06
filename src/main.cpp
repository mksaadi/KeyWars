#include <bits/stdc++.h>
#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
using namespace std;

#include "game.hpp"

int main()
{
    InitWindow(1920, 1080, "KeyWars");
    SetTargetFPS(60);
    InitAudioDevice();
    srand(time(NULL));


    Texture2D background = LoadTexture("assets/default.jpg");
    float bgY = 0;
    auto UpdateBackground = [&] () {
        bgY += 0.5f;
        if ( bgY >= background.height )
            bgY = 0;
        };
    auto DrawBackground = [&] () {
        DrawTextureEx(background, { 0, bgY }, 0.0f, 1.0f, WHITE);
        DrawTextureEx(background, { 0, bgY - ( float )background.height }, 0.0f, 1.0f, WHITE);
        };
    Font font = LoadFont("fonts/FunnelDisplay-VariableFont_wght.ttf");


    Game game(font);

    while ( !WindowShouldClose() && !game.shouldClose )
    {
        BeginDrawing();
        UpdateBackground();
        DrawBackground();
        game.HandleInput();
        game.Update();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    UnloadFont(font);
    UnloadTexture(background);
    return 0;
}