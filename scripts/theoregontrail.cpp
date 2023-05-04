#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "theoregontrail.h"

const int SPEED_FACTOR = 1000;
const int TIME_MIN_FACTOR = 10;
const int TIME_MAX_FACTOR = 100;

int resourceAmounts[6] = {700, 0, 0, 0, 0, 0};
char resourceNames[6][20] = {"Cripto Units", "Dark Matter", "Food", "Energy Cartridges", "Spare Parts", "Medical Supplies"};

unsigned int distanceTraveled = 0;
unsigned int distanceToTitan = 1200000000;

unsigned int stardate = 1368;

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

void printGameIntro()
{
    printf("Game Intro!\n");
}

void printGameEnd()
{
    printf("You reached Titan!\n");
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

void calculateProgress()
{
    // TODO: make this to have sense (or maybe not?)
    int speed = resourceAmounts[DARK_MATTER] * SPEED_FACTOR;
    int time = rand() % (TIME_MAX_FACTOR + 1 - TIME_MIN_FACTOR) + TIME_MIN_FACTOR;

    stardate += time;
    distanceTraveled += speed * time;
}

void printTripInfo()
{
    printf("Stardate %d\n", stardate);

    printf("Distance to Titan: %d kilometers\n", (distanceToTitan - distanceTraveled));

    for (int i = 0; i < MAX_RESOURCE_INDEX; i++)
    {
        printf("%s: %d\t", resourceNames[i], resourceAmounts[i]);
    }

    printf("\n");
}

void runGame()
{
    srand((unsigned int)time(NULL));

    bool tripEnded = false;
    
    printGameIntro();
    initialResourcesPurchase();

    while (!tripEnded)
    {
        calculateProgress();
        printTripInfo();

        tripEnded = distanceTraveled >= distanceToTitan;

        getchar();
    }

    printGameEnd();

    getchar();
}