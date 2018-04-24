#include "hands.h"
#define HAND_SIZE 13

Hand *drawHands(Tile *s, int n, size_t *sPos)
{
    /* Create hands */
    Hand *p = malloc(sizeof(Hand) * n);
    for (size_t i = 0; i < n; i++)
    {
        p[i].tiles = malloc(sizeof(Tile*) * (HAND_SIZE + 1));
    }

    /* Draw tiles in correct order */
    for (size_t i = 0; i < n; i++)
    {
        /* Draw four tiles */
        for (size_t y = 0; y < 4; y++)
        {
            p[i].tiles[y] = (s + *sPos);
            *sPos = *sPos + 1;
        }
    }

    /* Draw three sets of three tiles */
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t z = 0; z < n; z++)
        {
            for (size_t y = 0; y < 3; y++)
            {
                p[z].tiles[4 + (3 * i + y)] = (s + *sPos);
                *sPos = *sPos + 1;
            }
        }
    }

    return p;
}

void sortHand(Tile** t)
{
    size_t n = HAND_SIZE;
    Tile *temp;

    /* Sort each tile in order */
    while (n > 0)
    {
        for (size_t i = 0; i < n - 1; i++)
        {
            if ((t[i]->suite * 10) + t[i]->number > (t[i + 1]->suite * 10) + t[i + 1]->number)
            {
                temp = t[i + 1];
                t[i + 1] = t[i];
                t[i] = temp;
            }
        }
        n--;
    }
}

void printHand(Hand h)
{
    printf("+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n");
    for (size_t i = 0; i < HAND_SIZE; i++)
    {
        printTile(*(h.tiles[i]));
    }
    printf("\n+--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+ +--+\n\n");
}
