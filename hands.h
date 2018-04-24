#ifndef HANDS_H
#define HANDS_H

#include "sets.h"

typedef struct sHand {
    Tile **tiles;
} Hand;

Hand *drawHands(Tile *s, int n, size_t *p);
void sortHand(Tile** t);
void printHand(Hand h);

#endif // HANDS_H
