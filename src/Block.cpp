#include "Block.h"

Block::Block(/* args */)
{
}

Block::~Block()
{
}

void Block::draw(SDL_Renderer *rend)
{
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, &rect);
}

int Block::getValue()
{
    return value;
}

void Block::setValue(int v)
{
    value = v;
}

int Block::getNbVoisins()
{
    return nbVoisins;
}

void Block::setNbVoisins(int nb)
{
    nbVoisins = nb;
}