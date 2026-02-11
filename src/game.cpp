#include "game.hpp"


Game::Game(int nRows, int nColumns, int cellSize): grid(nRows, nColumns, cellSize), currentBlock(cellSize), nextBlock(cellSize){

    this -> cellSize = cellSize;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
};

Block Game::GetRandomBlock(){

    if(blocks.empty()){
        blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

bool Game::EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdatedTime >= interval){
        lastUpdatedTime = currentTime;
        return true;
    }

    return false;
}

std::vector<Block> Game::GetAllBlocks(){
    return {IBlock(cellSize), LBlock(cellSize), OBlock(cellSize), SBlock(cellSize), TBlock(cellSize), ZBlock(cellSize), JBlock(cellSize)};
}


void Game::MoveBlockLeft(){
    currentBlock.Move({0, -1});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({0, 1});
    }
}

void Game::MoveBlockRight(){
    currentBlock.Move({0, 1});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({0, -1});
    }
}

void Game::MoveBlockDown(){
    currentBlock.Move({1, 0});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({-1, 0});
        LockBlock();
    }
}

void Game::RotateBlock(){
    currentBlock.Rotate();
}

bool Game::IsBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        if(grid.IsCellOutside(item.row, item.column)){
            return true;
        }
    }

    return false;
}

bool Game::BlockFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        if(!grid.IsCellEmpty(item.row, item.column)){
            return false;
        }
    }

    return true;
}

void Game::LockBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        grid.SetValue(item.row, item.column, currentBlock.id());
    }

    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
    grid.ClearFullRows();
}



void Game::HandleInput(){

    int keyPressed = GetKeyPressed();

    switch(keyPressed){
        case KEY_SPACE:
             RotateBlock();
             break;

        case KEY_LEFT:
            MoveBlockLeft();
            break;

        case KEY_RIGHT:
            MoveBlockRight();
            break;
    }
}

void Game::Update(){
    if(EventTriggered(0.5)){
        MoveBlockDown();
    }
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}