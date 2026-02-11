
#pragma once

#include "grid.hpp"
#include "blocks/blocks.hpp"
#include <vector>
#include <random>

class Game{
    private:
        int cellSize;
        Grid grid;
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock; 

        
        double lastUpdatedTime;
        
        bool EventTriggered(double interval);
        
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void RotateBlock();
        void LockBlock();

        void UpdateScore(int numCompleted);

        bool IsBlockOutside();
        bool BlockFits();
        
        public:
        bool gameOver;
        int score;
        
        Game(int nRows, int nColumns, int cellSize);
        void Reset();
        void HandleInput();
        void Update();
        void Draw();
};