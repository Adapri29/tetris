#include "game.hpp"


Game::Game(int nRows, int nColumns, int cellSize): grid(nRows, nColumns, cellSize), currentBlock(cellSize), nextBlock(cellSize){

    this -> cellSize = cellSize;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
};

void Game::Reset(){
    gameOver = false;
    score = 0;
    grid.Inicialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

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
    if(gameOver) return;

    currentBlock.Move({0, -1});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({0, 1});
    }
}

void Game::MoveBlockRight(){
    if(gameOver) return;

    currentBlock.Move({0, 1});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({0, -1});
    }
}

void Game::MoveBlockDown(){
    if(gameOver) return;

    currentBlock.Move({1, 0});
    if(IsBlockOutside() || !BlockFits()){
        currentBlock.Move({-1, 0});
        LockBlock();
    }
}

void Game::RotateBlock(){
    if(gameOver) return;
    currentBlock.Rotate();
    if(!BlockFits()){
        currentBlock.UndoRotate();
    }
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
       if (!grid.IsCellOutside(item.row, item.column)) {
            // Si está dentro y la celda no está vacía, hay colisión real
            if (!grid.IsCellEmpty(item.row, item.column)) {
                return false;
            }
        } else {
            if (item.row >= 0 || item.column < 0 || item.column >= 10) { // asumiendo 10 columnas
                 // Si necesitas ser muy preciso, mejor usa IsCellOutside pero 
                 // ignora el error si row < 0
                 if(item.row >= 0) return false; 
            }
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
    if(!BlockFits()){
        gameOver=true;
    }
    nextBlock = GetRandomBlock();
    int linesCleared = grid.ClearFullRows();
    UpdateScore(linesCleared);
}

void Game::UpdateScore(int linesCleared){
    switch (linesCleared)
    {
    case 1:
        score+=100;
        break;
    
    case 2:
        score+=300;
        break;
    
    case 3:
        score+=500;
        break;

    default:
        break;
    }
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
    if(EventTriggered(0.2)){
        MoveBlockDown();
    }
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
}