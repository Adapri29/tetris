#include <iostream>
#include <raylib.h>
#include "src/game.hpp"
#include "src/colors.hpp"

int main()
{
    const int SCREEN_WIDHT = 500;
    const int SCREEN_HEIGHT = 620;
    const int CELL_SIZE = 20;

    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, "TETRIS");
    SetTargetFPS(60);

    Font font = LoadFontEx("assets/fonts/monogram.ttf", 64, 0, 0);

    Game game(600 / CELL_SIZE, 300 / CELL_SIZE, CELL_SIZE);

    while (!WindowShouldClose())
    {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(lightGrey);
        DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {365, 175}, 38, 2, WHITE);
        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, darkGrey);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, darkGrey);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}