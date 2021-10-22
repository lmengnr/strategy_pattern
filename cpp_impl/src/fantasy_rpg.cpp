#include "cCharacters.h"


int main()
{
    King theKing(new Sword);

    Knight knight1(new Club);

    theKing.performAttack();

    knight1.performAttack();
}