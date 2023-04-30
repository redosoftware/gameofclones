#ifndef THE_OREGON_TRAIL_H
#define THE_OREGON_TRAIL_H

typedef enum
{
    CRIPTO_UNITS,
    DARK_MATTER,
    FOOD,
    ENERGY_CARTRIDGES,
    SPARE_PARTS,
    MEDICAL_SUPPLIES,
    MAX_RESOURCE_INDEX
} resourceType;

int getNumberInput();

bool hasEnoughCash(int price);
int getResourceAmountByPrice(int price);

void showGameIntro();
void initialResourcesPurchase();
void printResourcesInfo();

void runGame();

#endif