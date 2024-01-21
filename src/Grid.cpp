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
            int randomValue = rand() % 5; // Génère un nombre aléatoire entre 0 et 4
            if (randomValue == 0)
            {
                block.setValue(1); // Définit la valeur du block à 1 si le nombre aléatoire est 0
            }
            else
            {
                block.setValue(0); // Définit la valeur du block à 0 si le nombre aléatoire est différent de 0
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
                cout << i << " " << j << endl;
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
    // On parcourt la grille
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            // On compte le nombre de voisins
            int nbVoisins = 0;

            // On parcourt les voisins
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    // On vérifie que le voisin n'est pas en dehors de la grille
                    if (i + k >= 0 && i + k < width && j + l >= 0 && j + l < height)
                    {

                        // On vérifie que le voisin n'est pas le block lui-même
                        if (!(k == 0 && l == 0))
                        {

                            // On vérifie que le voisin est vivant
                            if (blocks[i + k][j + l].getValue() == 1)
                            {
                                nbVoisins++;
                            }
                        }
                    }
                }
            }

            // On définit le nombre de voisins du block
            blocks[i][j].setNbVoisins(nbVoisins);
        }
    }

    // On parcourt la grille
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            // On vérifie si le block est vivant
            if (blocks[i][j].getValue() == 1)
            {

                // On vérifie si le block a moins de 2 voisins ou plus de 3 voisins
                if (blocks[i][j].getNbVoisins() < 2 || blocks[i][j].getNbVoisins() > 3)
                {
                    blocks[i][j].setValue(0); // Le block meurt
                }
            }
            else
            {

                // On vérifie si le block a exactement 3 voisins
                if (blocks[i][j].getNbVoisins() == 3)
                {
                    blocks[i][j].setValue(1); // Le block naît
                }
            }
        }
    }

    // On réinitialise le nombre de voisins de chaque block
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            blocks[i][j].setNbVoisins(0);
        }
    }
}