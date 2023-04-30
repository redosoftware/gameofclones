#include <stdio.h>
#include "theoregontrail.h"

int resourceAmounts[6] = {700, 0, 0, 0, 0, 0};
char resourceNames[6][20] = {"Cripto Units", "Dark Matter", "Food", "Energy Cartridges", "Spare Parts", "Medical Supplies"};

bool tripEnded;

int getNumberInput()
{
    char input[10];
    fgets(input, sizeof(input), stdin);

    int number = {};

    if (sscanf_s(input, "%d", &number) != 1)
    {
        number = -1;
    }

    return number;
}

bool hasEnoughCash(int price)
{
    return resourceAmounts[CRIPTO_UNITS] >= price;
}

int getResourceAmountByPrice(int price)
{
    // TODO: do proper calculations.
    return price;
}

void showGameIntro()
{
    printf("Game Intro!\n");
}

void initialResourcesPurchase()
{
    printf("You have %d %s to spare.\n", resourceAmounts[CRIPTO_UNITS], resourceNames[CRIPTO_UNITS]);
    
    int currentResource = DARK_MATTER;
    int cryptoToSpend = 0;

    while (currentResource < MAX_RESOURCE_INDEX)
    {
        printf("How much do you want to spend in %s?\n", resourceNames[currentResource]);

        cryptoToSpend = getNumberInput();

        if (cryptoToSpend < 0)
        {
            printf("Wrong input, try again.\n");
        }
        else if (hasEnoughCash(cryptoToSpend))
        {
            resourceAmounts[CRIPTO_UNITS] -= cryptoToSpend;
            resourceAmounts[currentResource] += getResourceAmountByPrice(cryptoToSpend);

            currentResource++;
        }
        else
        {
            printf("No enough %s, try again.\n", resourceNames[CRIPTO_UNITS]);
        }
    }
}

void printResourcesInfo()
{
    for (int i = 0; i < MAX_RESOURCE_INDEX; i++)
    {
        printf("%s: %d\t", resourceNames[i], resourceAmounts[i]);
    }

    printf("\n");
}

void runGame()
{
    showGameIntro();
    
    initialResourcesPurchase();

    printResourcesInfo();

    // while (!tripEnded)
    // {

    // }
}