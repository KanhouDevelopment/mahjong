#include "sets.h"
#include "hands.h"

/* Trying to write "Pointer *pointer" instead of "Pointer* pointer". xD */

int main(void)
{
    /* Generate current set */
    Tile *set = generateSet();
    size_t setPos = 0;

    /* Create players */
    size_t numberOfPlayers = 4;
    Hand *player = drawHands(set, numberOfPlayers, &setPos);

    for (size_t i = 0; i < numberOfPlayers; i++)
    {
        sortHand(player[i].tiles);
        printHand(player[i]);
    }

    return 0;
}
