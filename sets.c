#include "sets.h"
#define SET_SIZE 136


/* Generate a set of tiles */
Tile* generateSet(void)
{
    Tile *s = malloc(sizeof(Tile) * SET_SIZE);
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

    /* Scramble the set multiple times */
    size_t n;
    srand(time(0));
    for (size_t a = 0; a < 6; a++)
    {
        n = SET_SIZE - 1;
        if (a % 2)
        {
            for (size_t i = 0; i < n - 1; i++)
            {
                int a = rand() % (n - i);
                size_t j = i + a;

                Tile t = s[j];
                s[j] = s[i];
                s[i] = t;
            }
        }
        else
        {
            for (size_t i = n-1; i > 1; i--)
            {
                int a = rand() % (n - i);
                size_t j = i + a;

                Tile t = s[j];
                s[j] = s[i];
                s[i] = t;
            }
        }
    }

    /* return set */
    return s;
}

/* Print a tile */
void printTile(Tile t)
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
    printf("| ");
}
