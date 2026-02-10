#include <iostream>
#include <raylib.h>
#include "src/grid.hpp"
#include "src/blocks/Tblock.hpp"
#include "src/blocks/Lblock.hpp"
#include "src/blocks/Oblock.hpp"
#include "src/blocks/Sblock.hpp"
#include "src/blocks/Zblock.hpp"
#include "src/blocks/Iblock.hpp"
int main()
{
    const Color BACKGROUND_COLOR = {20, 160, 133, 255};
    const int SCREEN_WIDHT = 300;
    const int SCREEN_HEIGHT = 600;
    const int CELL_SIZE = 30;

    InitWindow(SCREEN_WIDHT, SCREEN_HEIGHT, "TETRIS");
    SetTargetFPS(60);

    Grid grid(SCREEN_HEIGHT / CELL_SIZE, SCREEN_WIDHT / CELL_SIZE, CELL_SIZE);

    IBlock block({2, 3}, CELL_SIZE);

    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE))
        {
            block.Rotate();
        }

        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        grid.Draw();
        block.Draw();
        EndDrawing();
    }

    CloseWindow();
}