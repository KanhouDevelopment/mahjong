#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SET_SIZE 136

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

/* Generate a set of tiles */
Tile* generateSet(void)
{
    Tile* s = malloc(sizeof(Tile) * SET_SIZE);
    size_t pointer = 0;

    /* Generate simples */
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t y = 0; y < 9; y++)
        {
            for (size_t z = 0; z < 4; z++)
            {
                /* Create tile */
                Tile t;
                t.suite = i + 1;
                t.number = y + 1;

                /* Save tile */
                s[pointer] = t;
                pointer++;
            }
        }
    }

    /* Generate Winds */
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            /* Create tile */
            Tile t;
            t.suite = 4;
            t.number = i + 1;

            /* Save tile */
            s[pointer] = t;
            pointer++;
        }
    }

    /* Generate Dragons */
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t y = 0; y < 4; y++)
        {
            /* Create tile */
            Tile t;
            t.suite = 5;
            t.number = i + 1;

            /* Save tile */
            s[pointer] = t;
            pointer++;
        }
    }

    size_t n = SET_SIZE - 1;

    size_t i;
    for (i = 0; i < n - 1; i++)
    {
        srand(time(0));
        size_t j = i + (rand() % (n - i));

        Tile t = s[j];
        s[j] = s[i];
        s[i] = t;
    }

    return s;
}

/* Print a tile */
void drawTile(Tile t)
{
    printf("|");

    switch (t.suite)
    {
    case 1:
        printf("S%i", t.number);
        break;
    case 2:
        printf("B%i", t.number);
        break;
    case 3:
        printf("C%i", t.number);
        break;
    case 4:
        switch (t.number)
        {
        case 1:
            printf("WE");
            break;
        case 2:
            printf("WS");
            break;
        case 3:
            printf("WW");
            break;
        case 4:
            printf("WN");
            break;
        }
        break;
    case 5:
        switch (t.number)
        {
        case 1:
            printf("DR");
            break;
        case 2:
            printf("DG");
            break;
        case 3:
            printf("DW");
            break;
        break;
        }
    }
    printf("|");
}

int main(void)
{
    Tile* set = generateSet();
    for (size_t i = 0; i < SET_SIZE; i++)
    {
        drawTile(set[i]);
    }

    return 0;
}
