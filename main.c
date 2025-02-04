//fortnite loot chest randomizer by papaya WIP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "settings.h"

int main(void) {
    srand (time(NULL));
    mats[0].id = 1;
    mats[0].dropchance = 1;
    strcpy(mats[0].name, "Wood");
    mats[1].id = 2;
    mats[1].dropchance = 1;
    strcpy(mats[1].name, "Stone");
    mats[2].id = 3;
    mats[2].dropchance = 1;
    strcpy(mats[2].name, "Metal");
    int currID = 4;
    int weaponsNB = 0;
    int consumablesNB = 0;
    int matsNB = 3;
    int exit = 0;
    int rarity = 0;//while rare chests are not implemented, always 0 so common
    int weaponsIndex = 0;
    int consumablesIndex = 0;
    int matsIndex = 0;
    char input[5];
    while (exit == 0){
        int validentry = 0;
        while (validentry == 0) {
            validentry = 1;
            displayMainMenu();
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            if (strcmp(input, "E") == 0 || strcmp(input, "e") == 0) {
                printf("Opening Chests Menu...\n");
                int exitC = 0;
                if (weaponsNB == 0 || consumablesNB == 0) {
                    printf("You need to add at least one weapon and one consumable to open chests.\n");
                    exitC = 1;
                }
                while (exitC == 0) {
                    displayChestMenu();
                    char input2[5];
                    fgets(input2, sizeof(input2), stdin);
                    input2[strcspn(input2, "\n")] = '\0';
                    if (strcmp(input2, "E") == 0 || strcmp(input2, "e") == 0) {
                        openChest(rarity, &weaponsIndex, &consumablesIndex, &matsIndex, weaponsNB, consumablesNB);
                        printf("You obtained the following items:\n");
                        printf("Weapon: %s %s\n", rarityDic(weapons[weaponsIndex].rarity), weapons[weaponsIndex].name);
                        printf("Consumable: %d %s\n",consumables[consumablesIndex].quantity, consumables[consumablesIndex].name);
                        printf("Material: 30 %s\n", mats[matsIndex].name);
                    }else if (strcmp(input2, "F") == 0 || strcmp(input2, "f") == 0){
                        exitC = 1;
                        printf("Returning to the main menu.\n");
                    }else {
                        printf("Invalid input. Please try again.\n");
                    }
                }
            } else if (strcmp(input, "S") == 0 || strcmp(input, "s") == 0) {
                int exitS = 0;
                printf("Opening Settings...\n\n");
                while (exitS == 0) {
                    displaySettingsMenu();
                    char input2[5];
                    fgets(input2, sizeof(input2), stdin);
                    input2[strcspn(input2, "\n")] = '\0';
                    if (strcmp(input2, "W") == 0 || strcmp(input2, "w") == 0) {
                        printf("Creating a weapon.\n");
                        currID = weaponCreationFoolproof(weaponsNB, currID);
                        weaponsNB++;
                    } else if (strcmp(input2, "C") == 0 || strcmp(input2, "c") == 0) {
                        printf("Creating a consumable.\n");
                        currID = consumableCreationFoolproof(consumablesNB, currID);
                        consumablesNB++;
                    } else if (strcmp(input2, "S") == 0 || strcmp(input2, "s") == 0) {
                        printf("Displaying weapons.\n\n");
                        displayWeapons(weaponsNB);
                    } else if (strcmp(input2, "M") == 0 || strcmp(input2, "m") == 0) {
                        printf("Displaying consumables.\n\n");
                        displayConsumables(consumablesNB);
                    } else if (strcmp(input2, "R") == 0 || strcmp(input2, "r") == 0) {
                        printf("Removing an item.\n");
                        printf("Would you like to delete a weapon or a consumable ? W/C\n");
                        char input3[5];
                        fgets(input3, sizeof(input3), stdin);
                        input3[strcspn(input3, "\n")] = '\0';
                        if (strcmp(input3, "W") == 0 || strcmp(input3, "w") == 0) {
                            printf("Deleting a weapon.\n");
                            weaponsNB = deleteItem(0, weaponsNB);
                        } else if (strcmp(input3, "C") == 0 || strcmp(input3, "c") == 0) {
                            printf("Deleting a consumable.\n");
                            consumablesNB = deleteItem(1, consumablesNB);
                        } else {
                            printf("Invalid input. Please try again.\n");
                            clearInputBuffer();
                        }
                    } else if (strcmp(input2, "F") == 0 || strcmp(input2, "f") == 0) {
                        printf("Returning to the main menu.\n");
                        exitS = 1;
                    } else {
                        printf("Invalid input. Please try again.\n");
                        clearInputBuffer();
                    }
                }
            } else if (strcmp(input, "F") == 0 || strcmp(input, "f") == 0) {
                printf("Exiting...\n");
                exit = 1;
            } else {
                printf("Invalid input. Please try again.\n");
                clearInputBuffer();
                validentry = 0;
            }
        }
    }
    return 0;
}
