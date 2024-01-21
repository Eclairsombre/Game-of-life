#ifndef BLOCK
#define BLOCK

#include <SDL2/SDL.h>

#include <vector>

class Block
{
private:
    SDL_Rect rect;
    int value;

    int nbVoisins;

public:
    Block(/* args */);
    ~Block();

    void draw(SDL_Renderer *rend);
    int getValue();
    void setValue(int v);
    int getNbVoisins();
    void setNbVoisins(int nb);
};

#endif