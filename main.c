//fortnite loot chest randomizer by papaya WIP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "settings.h"

int main(void) {
    srand (time(NULL));
    char filenameW[254] = "weapons.txt";
    char filenameC[254] = "consumables.txt";
    int temp;
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
    int exit = 0;
    int rarity = 0;//while rare chests are not implemented, always 0 so common
    int weaponsIndex, consumablesIndex, matsIndex;
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
                    } else if (strcmp(input2, "X") == 0 || strcmp(input2, "x") == 0) {
                        printf("How many chests would you like to open ?\n");
                        char input3[64];
                        fgets(input3, sizeof(input3), stdin);
                        input3[strcspn(input3, "\n")] = '\0';
                        if (atoi(input3) <= 1) {
                            if (atoi(input3) == 1) {
                                printf("You can just open a single chest by pressing E(noob) :P\n");
                            }else {
                                printf("Wrong input. Try again and enter a number.\n");
                            }
                        } else {
                            int weaponCount[weaponsNB];
                            int consumableCount[consumablesNB];
                            int matCount[3] = {0};
                            memset(weaponCount, 0, sizeof(weaponCount));
                            memset(consumableCount, 0, sizeof(consumableCount));
                            memset(matCount, 0, sizeof(matCount));
                            const unsigned int X = atoi(input3);
                            printf("Opening %d chests.\n", X);
                            int printitallhere = 0;
                            openXChests(X, weaponCount, consumableCount, matCount, weaponsNB, consumablesNB);
                            if (X>=10) {
                                printf("That's a lot of loot ! Would you like a CSV data file ? Y/N\n");
                                char input4[5];
                                fgets(input4, sizeof(input4), stdin);
                                input4[strcspn(input4, "\n")] = '\0';
                                if (strcmp(input4, "Y") == 0 || strcmp(input4, "y") == 0) {
                                    chestToCSV(weaponCount, weaponsNB, consumableCount, consumablesNB, matCount);
                                    printitallhere = 1;
                                }
                            }
                            if (printitallhere == 0) {
                                for (int i = 0; i < weaponsNB; i++) {
                                    if (weaponCount[i] != 0) {
                                        printf("Weapon: %s %s - %d times\n", rarityDic(weapons[i].rarity), weapons[i].name, weaponCount[i]);
                                    }
                                }
                                for (int i = 0; i < consumablesNB; i++) {
                                    if (consumableCount[i] != 0) {
                                        printf("Consumable: %d %s - %d times\n", consumables[i].quantity, consumables[i].name, consumableCount[i]);
                                    }
                                }
                                for (int i = 0; i < 3; i++) {
                                    if (matCount[i] != 0) {
                                        printf("Material: 30 %s - %d times\n", mats[i].name, matCount[i]);
                                    }
                                }
                            }
                        }
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
                    } else if (strcmp(input2, "H") == 0 || strcmp(input2, "h") == 0) {
                        int exitH = 0;
                        while (exitH == 0) {
                            printf("====================================\n");
                            printf("There are currently %d weapons and %d consumables.\n\n", weaponsNB, consumablesNB);
                            printf("Current weapons file : %s\n", filenameW);
                            printf("Current consumables file : %s\n", filenameC);
                            printf("====================================\n");
                            printf("[H] Hardfill from selected files\n"
                                   "[W] Change weapons filename\n"
                                   "[C] Change consumables filename\n"
                                   "[F] Return to the settings menu\n");
                            printf("====================================\n");
                            char input4[5];
                            fgets(input4, sizeof(input4), stdin);
                            input4[strcspn(input4, "\n")] = '\0';
                            if (strcmp(input4, "W") == 0 || strcmp(input4, "w") == 0) {
                                printf("Put the text file in the same directory.\n"
                               "Syntax is as follows:\n"
                               "\"Name\" Dropchance Rarity Type\n"
                               "\"Scar L\" 0.05 4 1\n"
                               "Rarities : 0 - Common, 1 - Uncommon, 2 - Rare, 3 - Epic, 4 - Legendary\n"
                               "Types : 0 - Shotgun, 1 - AR, 2 - SMG, 3 - Sniper, 4 - Pistol, 5 - Explosive\n");
                                printf("\nWhat is the name of the file ?\n");
                                fgets(filenameW, sizeof(filenameW), stdin);
                                filenameW[strcspn(filenameW, "\n")] = '\0';
                                strcat(filenameW, ".txt");
                            } else if (strcmp(input4, "H") == 0 || strcmp(input4, "h") == 0) {
                                printf("Do you want to hardfill weapons or consumables ? W/C\n");
                                char input5[5];
                                fgets(input5, sizeof(input5), stdin);
                                input5[strcspn(input5, "\n")] = '\0';
                                if (strcmp(input5, "W") == 0 || strcmp(input5, "w") == 0) {
                                    temp = currID;
                                    currID = hardFillWeapons(filenameW, currID, weaponsNB);
                                    weaponsNB += currID - temp;
                                } else if (strcmp(input5, "C") == 0 || strcmp(input5, "c") == 0) {
                                    temp = currID;
                                    currID = hardFillConsumables(filenameC, currID, consumablesNB);
                                    consumablesNB += currID - temp;
                                } else {
                                    printf("Invalid entry, please try again.\n");
                                }
                            } else if (strcmp(input4, "C") == 0 || strcmp(input4, "c") == 0) {
                                printf("Put the text file in the same directory.\n"
                               "Syntax is as follows:\n"
                               "\"Name\" Dropchance Rarity Quantity\n"
                               "\"Medkit\" 10 2 1\n"
                               "Rarities : 0 - Common, 1 - Uncommon, 2 - Rare, 3 - Epic, 4 - Legendary\n");
                                printf("\nWhat is the name of the file ?\n");
                                fgets(filenameC, sizeof(filenameC), stdin);
                                filenameC[strcspn(filenameC, "\n")] = '\0';
                                strcat(filenameC, ".txt");
                            }else if (strcmp(input4, "F") == 0 || strcmp(input4, "f") == 0) {
                                printf("Returning to settings menu.\n");
                                exitH = 1;
                            } else {
                                printf("Invalid entry, please try again.\n");
                            }
                        }
                    } else if (strcmp(input2, "C") == 0 || strcmp(input2, "c") == 0) {
                        printf("Creating a consumable.\n");
                        currID = consumableCreationFoolproof(consumablesNB, currID);
                        consumablesNB++;
                    } else if (strcmp(input2, "S") == 0 || strcmp(input2, "s") == 0) {
                        printf("Displaying items.\n\n");
                        printf("\n===================================\n");
                        printf("             ITEMS LIST            \n");
                        printf("===================================\n");
                        displayWeapons(weaponsNB);
                        displayConsumables(consumablesNB);
                        printf("You currently have %d weapons and %d consumables.\n", weaponsNB, consumablesNB);
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
