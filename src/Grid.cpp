#include "Grid.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Grid::Grid(int w, int h)
{
    width = w;
    height = h;

    for (int i = 0; i < width; i++)
    {
        vector<Block> temp;
        for (int j = 0; j < height; j++)
        {
            Block block;
            int randomValue = rand() % 5;
            if (randomValue == 0)
            {
                block.setValue(1);
            }
            else
            {
                block.setValue(0);
            }
            temp.push_back(block);
        }
        blocks.push_back(temp);
    }
}

Grid::~Grid()
{
}

void Grid::draw(SDL_Renderer *rend)
{
    int rectSize = 50;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            SDL_Rect rect;
            rect.x = i * rectSize;
            rect.y = j * rectSize;
            rect.w = rectSize;
            rect.h = rectSize;

            if (blocks[i][j].getValue() == 1)
            {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
                SDL_RenderFillRect(rend, &rect);
            }
        }
    }
}

int Grid::getWidth()
{
    return width;
}

int Grid::getHeight()
{
    return height;
}

void Grid::GameOfLife()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            int nbVoisins = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k >= 0 && i + k < width && j + l >= 0 && j + l < height)
                    {

                        if (!(k == 0 && l == 0))
                        {

                            if (blocks[i + k][j + l].getValue() == 1)
                            {
                                nbVoisins++;
                            }
                        }
                    }
                }
            }

            blocks[i][j].setNbVoisins(nbVoisins);
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            if (blocks[i][j].getValue() == 1)
            {

                if (blocks[i][j].getNbVoisins() < 2 || blocks[i][j].getNbVoisins() > 3)
                {
                    blocks[i][j].setValue(0);
                }
            }
            else
            {

                if (blocks[i][j].getNbVoisins() == 3)
                {
                    blocks[i][j].setValue(1);
                }
            }
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            blocks[i][j].setNbVoisins(0);
        }
    }
}