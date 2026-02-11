#include <iostream>
#include <raylib.h>
#include "src/game.hpp"

int main()
{
    const Color BACKGROUND_COLOR = {20, 160, 133, 255};
    const int SCREEN_WIDHT = 330;
    const int SCREEN_HEIGHT = 600;
    const int CELL_SIZE = 30;

    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, "TETRIS");
    SetTargetFPS(60);

    Game game(SCREEN_HEIGHT / CELL_SIZE, SCREEN_WIDHT / CELL_SIZE, CELL_SIZE);

    while (!WindowShouldClose())
    {
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}