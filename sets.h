#ifndef SETS_H
#define SETS_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct sTile
{
    int suite;
    /*
        1: Dots/Stones
        2: Bamboo
        3: Characters
        4: Winds
        5: Dragons
    */

    int number;
    /*
        If suite is 1, 2 or 3; then 1 - 9.
        If wind:
            1: East
            2: South
            3: West
            4: North
        If dragons:
            1: Red
            2: Green
            3: White
    */
} Tile;

Tile* generateSet(void);
void printTile(Tile t);

#endif // SETS_H
