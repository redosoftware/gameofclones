#ifndef THE_OREGON_TRAIL_H
#define THE_OREGON_TRAIL_H

enum resourceType
{
    CRIPTO_UNITS,
    DARK_MATTER,
    FOOD,
    ENERGY_CARTRIDGES,
    SPARE_PARTS,
    MEDICAL_SUPPLIES,
    MAX_RESOURCE_INDEX
};

int getNumberInput();

bool hasEnoughCash(int price);
int getResourceAmountByPrice(int price);

void printGameIntro();
void printGameEnd();

void initialResourcesPurchase();

void calculateProgress();
void printTripInfo();

void runGame();

#endif