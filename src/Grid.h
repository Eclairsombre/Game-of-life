#ifndef GRID
#define GRID

#include <SDL2/SDL.h>

#include <vector>
#include "Block.cpp"

class Grid
{
private:
    int width, height;
    vector<vector<Block>> blocks;

public:
    Grid(int w, int h);
    ~Grid();
    void draw(SDL_Renderer *rend);
    int getWidth();
    int getHeight();
    void GameOfLife();
};

#endif