//
// Created by pablo on 2/2/2025.
//

#include "settings.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WEAPONS 100
#define MAX_CONSUMABLES 100
#define MAX_MATS 3

struct weapons weapons[MAX_WEAPONS];
struct consumables consumables[MAX_CONSUMABLES];
struct mats mats[MAX_MATS];

//===============================Functions=====================================
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Discard remaining characters
}
void displayMainMenu() {
    printf("====================================\n");
    printf("       FORTNITE CHEST RANDOMIZER   \n");
    printf("====================================\n");
    printf("  [E] Open Chests\n");
    printf("  [S] Settings\n");
    printf("  [F] Exit\n");
    printf("====================================\n");
}

void displaySettingsMenu() {
    printf("====================================\n");
    printf("          SETTINGS MENU             \n");
    printf("====================================\n");
    printf("  [W] Add a weapon\n");
    printf("  [C] Add a Consumable\n");
    printf("  [S] See added weapons\n");
    printf("  [M] See added consumables\n");
    printf("  [R] Remove an item\n");
    printf("  [F] Return to Main Menu\n");
    printf("====================================\n");
}

void displayChestMenu(){
    printf("====================================\n");
    printf("           CHEST  MENU              \n");
    printf("====================================\n");
    printf("  [E] Open 1 chest\n");
    printf("  [R] Open 1000 chests\n");
    printf("  [A] Open chests UNTIL\n");
    printf("  [F] Return to Main Menu\n");
}

const char* rarityDic(int rarity) {
    switch (rarity) {
        case 0:
            return "Common";
        case 1:
            return "Uncommon";
        case 2:
            return "Rare";
        case 3:
            return "Epic";
        case 4:
            return "Legendary";
        default:
            return "invalid";
    }
}

const char* typeDic(int type) {
    switch (type) {
        case 0:
            return "Shotgun";
        case 1:
            return "AR";
        case 2:
            return "SMG";
        case 3:
            return "Sniper";
        case 4:
            return "Pistol";
        case 5:
            return "Explosive";
        default:
            return "invalid";
    }
}

int weaponCreation(int currsize,int currID, char name[], int type,  int rarity, float dropchance) {
    weapons[currsize].id = currID;
    int dropchanceINT = dropchance * 100;
    weapons[currsize].dropchance = dropchanceINT;
    strcpy(weapons[currsize].name, name);
    weapons[currsize].rarity = rarity;
    weapons[currsize].type = type;
    printf("The following weapon of ID %d has been created:\n"
            "Name: %s\n"
           "Drop chance: %.2f%%\n"
           "Rarity: %s\n"
           "Type: %s\n\n", weapons[currsize].id, weapons[currsize].name, dropchance,
           rarityDic(weapons[currsize].rarity), typeDic(weapons[currsize].type));
    return ++currID;
}

int weaponCreationFoolproof(int currsize, int currID) {
    int type, rarity;
    float dropchance;
    char name[30], rarityUser[30], typeUser[30];
    int validentry = 0;
    while (validentry == 0) {
        printf("Enter the name of the weapon: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (strlen(name) < 28 && atoi(name)==0) {
            printf("Is the name %s for the weapon correct ? Y/N.\n", name);
            char input4;
            scanf(" %c", &input4);
            while (getchar() != '\n');
            if (input4 == 'Y' || input4 == 'y') {
                validentry = 1;
            } else {
                printf("Please try again.\n");
            }
        }else if (atoi(name)!=0) {
            printf("Name cannot be numbers only. Please try again.\n");
        }else {
            printf("Name is too long. Please try again.\n");
            clearInputBuffer();
        }
    }
    validentry = 0;
    while (validentry == 0) {
        validentry=1;
        printf("Enter the type of the weapon: \n"
               "1 - shotgun, 2 - AR, 3 - SMG, 4 - sniper, 5 - pistol, 6 - explosive\n"
               "(Enter a name or number)\n");
        fgets(typeUser, sizeof(typeUser), stdin);
        typeUser[strcspn(typeUser, "\n")] = '\0';
        if (strcmp(typeUser, "1") == 0 || strcasecmp(typeUser, "shotgun") == 0) {
            type = 0;
        } else if (strcmp(typeUser, "2") == 0 || strcasecmp(typeUser, "AR") == 0) {
            type = 1;
        } else if (strcmp(typeUser, "3") == 0 || strcasecmp(typeUser, "SMG") == 0) {
            type = 2;
        } else if (strcmp(typeUser, "4") == 0 || strcasecmp(typeUser, "sniper") == 0) {
            type = 3;
        } else if (strcmp(typeUser, "5") == 0 || strcasecmp(typeUser, "pistol") == 0) {
            type = 4;
        } else if (strcmp(typeUser, "6") == 0 || strcasecmp(typeUser, "explosive") == 0) {
            type = 5;
        } else {
            printf("Invalid input. Please try again.\n\n");
            validentry = 0;
        }
    }
    validentry = 0;
    while (validentry == 0) {
        printf("Enter the rarity of the weapon: \n"
           "1 - COMMON, 2 - UNCOMMON, 3 - RARE, 4 - EPIC, 5 - LEGENDARY\n"
           "(Enter a name or a number)\n");
        validentry = 1;
        fgets(rarityUser, sizeof(rarityUser), stdin);
        rarityUser[strcspn(rarityUser, "\n")] = '\0';
        if (strcmp(rarityUser, "1") == 0 || strcasecmp(rarityUser, "common") == 0) {
            rarity = 0;
        } else if (strcmp(rarityUser, "2") == 0 || strcasecmp(rarityUser, "uncommon") == 0) {
            rarity = 1;
        } else if (strcmp(rarityUser, "3") == 0 || strcasecmp(rarityUser, "rare") == 0) {
            rarity = 2;
        } else if (strcmp(rarityUser, "4") == 0 || strcasecmp(rarityUser, "epic") == 0) {
            rarity = 3;
        } else if (strcmp(rarityUser, "5") == 0 || strcasecmp(rarityUser, "legendary") == 0) {
            rarity = 4;
        } else {
            printf("Invalid input. Please try again.\n\n");
            validentry = 0;
        }
    }
    validentry = 0;
    while (validentry==0) {
        printf("Enter the drop chance of the weapon: \n"
               "(from 0.01%% to 100%%)\n");
        scanf("%f", &dropchance);
        while (getchar() != '\n');
        if (dropchance < 0.01 || dropchance > 100) {
            printf("Invalid input. Please try again.\n");
        } else {
            printf("Chosen a drop chance of %.2f%%, correct ? Y/N.\n", dropchance);
            char input3;
            scanf("%c", &input3);
            while (getchar() != '\n');
            if (input3 == 'Y' || input3 == 'y') {
                validentry = 1;
            } else {
                printf("Please try again.\n\n");
            }
        }
    }
    return weaponCreation(currsize, currID, name, type, rarity, dropchance);
}

int consumableCreation(int currsize, int currID, int dropchance, int number, int rarity, char name[]) {
    consumables[currsize].id = currID;
    int dropchanceINT = dropchance * 100;
    consumables[currsize].dropchance = dropchanceINT;
    strcpy(consumables[currsize].name, name);
    consumables[currsize].rarity = rarity;
    consumables[currsize].quantity = number;
    printf("The following consumable of ID %d has been created:\n"
           "Name: %s\n"
           "Drop chance: %.2f%%\n"
           "Rarity: %s\n"
           "Quantity: %d\n", consumables[currsize].id, consumables[currsize].name, consumables[currsize].dropchance,
           rarityDic(consumables[currsize].rarity), consumables[currsize].quantity);
    return ++currID;
}

int consumableCreationFoolproof(int currsize, int currID) {
    int rarity, number;
    float dropchance;
    char name[30], rarityUser[30];
    int validentry = 0;
    while (validentry == 0) {
        printf("Enter the name of the consumable: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';
        if (strlen(name) < 28 && atoi(name)==0) {
            printf("Is the name %s for the consumable correct ? Y/N.\n", name);
            char input4;
            scanf(" %c", &input4);
            while (getchar() != '\n');
            if (input4 == 'Y' || input4 == 'y') {
                validentry = 1;
            } else {
                printf("Please try again.\n");
            }
        }else if (atoi(name)!=0) {
            printf("Name cannot be numbers only. Please try again.\n");
            clearInputBuffer();
        }else {
            printf("Name is too long. Please try again.\n");
            clearInputBuffer();
        }
    }
    validentry = 0;
    while (validentry == 0) {
        printf("Enter the rarity of the consumable: \n"
               "1 - COMMON, 2 - UNCOMMON, 3 - RARE, 4 - EPIC, 5 - LEGENDARY\n"
               "(Enter a name or a number)\n");
        validentry = 1;
        fgets(rarityUser, sizeof(rarityUser), stdin);
        rarityUser[strcspn(rarityUser, "\n")] = '\0';
        if (strcmp(rarityUser, "1") == 0 || strcasecmp(rarityUser, "common") == 0) {
            rarity = 0;
        } else if (strcmp(rarityUser, "2") == 0 || strcasecmp(rarityUser, "uncommon") == 0) {
            rarity = 1;
        } else if (strcmp(rarityUser, "3") == 0 || strcasecmp(rarityUser, "rare") == 0) {
            rarity = 2;
        } else if (strcmp(rarityUser, "4") == 0 || strcasecmp(rarityUser, "epic") == 0) {
            rarity = 3;
        } else if (strcmp(rarityUser, "5") == 0 || strcasecmp(rarityUser, "legendary") == 0) {
            rarity = 4;
        } else {
            printf("Invalid input. Please try again.\n\n");
            validentry = 0;
        }
    }
    validentry = 0;
    while (validentry == 0){
        printf("Quantity the consumable will drop in: ");
        scanf("%d", &number);
        while (getchar() != '\n');
        if (number < 1 || number > 100) {
            printf("Out of bounds. Please try again.\n");
        } else {
            printf("Chosen a quantity of %d, correct ? Y/N.\n", number);
            char input3;
            scanf("%c", &input3);
            while (getchar() != '\n');
            if (input3 == 'Y' || input3 == 'y') {
                validentry = 1;
            } else {
                printf("Please try again.\n\n");
            }
        }
    }
    validentry = 0;
    while (validentry==0) {
        printf("Enter the drop chance of the consumable: \n"
               "(from 0.01%% to 100%%)\n");
        scanf("%f", &dropchance);
        while (getchar() != '\n');
        if (dropchance < 0.01 || dropchance > 100) {
            printf("Invalid input. Please try again.\n");
        } else {
            printf("Chosen a drop chance of %.2f%%, correct ? Y/N.\n", dropchance);
            char input3;
            scanf("%c", &input3);
            while (getchar() != '\n');
            if (input3 == 'Y' || input3 == 'y') {
                validentry = 1;
            } else {
                printf("Please try again.\n\n");
            }
        }
    }
    return consumableCreation(currsize, currID, dropchance, number, rarity, name);
}

void displayWeapons(int size) {
    if (size == 0) {
        printf("No weapons have been added yet.\n\n");
    } else {
        printf("\n===================================\n");
        printf("           WEAPONS   LIST          \n");
        printf("===================================\n");
        int totalDropChance = 0;
        for (int i = 0; i < size; i++) {
            totalDropChance += weapons[i].dropchance;
            float dropchanceUser = weapons[i].dropchance/100.0;
            printf("Weapon %d:\n"
                   "\tName: %s\n"
                   "\tDrop chance: %.2f%%\n"
                   "\tRarity: %s\n"
                   "\tType: %s\n"
                   "\tID: %d\n", i+1, weapons[i].name, dropchanceUser,
                   rarityDic(weapons[i].rarity), typeDic(weapons[i].type), weapons[i].id);
        }
        printf("\n===================================\n");
        printf("You currently have %d weapons.\n\n", size);
        if (totalDropChance != 10000) {
            printf("Note : Total drop chance is %.2f%%.\nThe drop chances will be used as coefficients to ensure a fair lootpool.\n\n", (float)totalDropChance/100);
        } else {
            printf("Note : Total drop chance is 100%%, Perfect !\n\n");
        }
    }
}

void displayConsumables(int size) {
    if (size == 0) {
        printf("No consumables have been added yet.\n\n");
    } else {
        printf("\n===================================\n");
        printf("         CONSUMABLES LIST          \n");
        printf("===================================\n");
        int totalDropChance = 0;
        for (int i = 0; i < size; i++) {
            totalDropChance += consumables[i].dropchance;
            float dropchanceUser = consumables[i].dropchance/100.0;
            printf("Consumable %d:\n"
                   "\tName: %s\n"
                   "\tDrop chance: %.2f%%\n"
                   "\tRarity: %s\n"
                   "\tQuantity: %d\n"
                   "\tID: %d\n", i+1, consumables[i].name, dropchanceUser,
                   rarityDic(consumables[i].rarity), consumables[i].quantity, consumables[i].id);
        }
        printf("\n===================================\n");
        printf("You currently have %d consumables.\n\n", size);
        if (totalDropChance != 10000) {
            printf("Note : Total drop chance is %.2f%%.\nThe drop chances will be used as coefficients to ensure a fair lootpool.\n\n", (float)totalDropChance/100);
        } else {
            printf("Note : Total drop chance is 100%%, Perfect !\n\n");
        }
    }
}

int deleteItem(int type, int size) {
    const char *typeUser;
    int exit = 0;
    if (type == 0) {
        typeUser = "Weapon";
    } else{
        typeUser = "Consumable";
    }
    while (exit == 0 && size > 0) {
        printf("\n===================================\n");
        printf("           DELETE  MENU            \n");
        printf("===================================\n");
        for (int i = 0; i < size; i++) {
            if (type == 0) {
                printf("Weapon %d:\n"
                       "\tName: %s\n"
                       "\tID: %d\n", i+1, weapons[i].name, weapons[i].id);
            } else {
                printf("Consumable %d:\n"
                       "\tName: %s\n"
                       "\tID: %d\n", i+1, consumables[i].name, consumables[i].id);
            }
        }
        printf("===================================\n");
        printf("Enter the ID/name of the %s you want to delete.\n"
               "Enter 0 to return to the settings menu.\n", typeUser);
        char input[30];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcasecmp(input, "0") == 0) {
            exit = 1;
        } else {
            int found = 0;
            int i = 0;
            if (type == 0) {
                while (i < size && found == 0) {
                    if (strcmp(input, weapons[i].name) == 0 || atoi(input) == weapons[i].id) {
                        found = 1;
                        printf("Are you sure you want to delete the following weapon ? Y/N\n"
                               "Name: %s\n"
                               "ID: %d\n", weapons[i].name, weapons[i].id);
                        char input2;
                        scanf(" %c", &input2);
                        while (getchar() != '\n');
                        if (input2 == 'Y' || input2 == 'y') {
                            for (int j = i; j < size-1; j++) {
                                weapons[j] = weapons[j+1];
                            }
                            size--;
                            printf("Weapon deleted.\n");
                        } else {
                            printf("Deletion cancelled.\n");
                        }
                    }
                    i++;
                }
            } else {
                while (i < size && found == 0) {
                    if (strcmp(input, consumables[i].name) == 0 || atoi(input) == consumables[i].id) {
                        found = 1;
                        printf("Are you sure you want to delete the following consumable ? Y/N\n"
                               "Name: %s\n"
                               "ID: %d\n", consumables[i].name, consumables[i].id);
                        char input2;
                        scanf(" %c", &input2);
                        while (getchar() != '\n');
                        if (input2 == 'Y' || input2 == 'y') {
                            for (int j = i; j < size-1; j++) {
                                consumables[j] = consumables[j+1];
                            }
                            size--;
                            printf("Consumable deleted.\n");
                        } else {
                            printf("Deletion cancelled.\n");
                        }
                    }
                    i++;
                }
            }
            if (found == 0) {
                printf(" The %s %s was not found. Please try again.\n", typeUser, input);
            }
        }
    }
    if (size == 0) {
        printf("\nNo %s have been added yet.\n\n", typeUser);
    }
    return size;
}

void openChest(int rarity, int *weaponsIndex, int *consumablesIndex, int *matsIndex, int weaponsNB, int consumablesNB) {
    if (rarity == 0) {
        //chest will drop one weapon, one consumable and one mat
        int weaponDrops[weaponsNB], consumableDrops[consumablesNB];
        weaponDrops[0] = weapons[0].dropchance;
        consumableDrops[0] = consumables[0].dropchance;
        for (int i = 1;i<weaponsNB;i++) {
            weaponDrops[i] = weapons[i-1].dropchance+weapons[i].dropchance;
            consumableDrops[i] = consumableDrops[i-1]+consumables[i].dropchance;
        }
        int weaponDrop, consumableDrop;
        if (weaponDrops[weaponsNB-1] <= 10000 && consumableDrops[consumablesNB-1] <= 10000) {
            weaponDrop = (int)((double)rand() / (RAND_MAX + 1.0) * weaponDrops[weaponsNB - 1]) + 1;
            consumableDrop = (int)((double)rand() / (RAND_MAX + 1.0) * consumableDrops[consumablesNB - 1]) + 1;
        } else {
            double randNumberW = ((rand() << 15) | rand()) / (double)(1 << 30);
            weaponDrop = 1 + (int)(randNumberW * weaponDrops[weaponsNB - 1]);
            double randNumberC = ((rand() << 15) | rand()) / (double)(1 << 30);
            consumableDrop = 1 + (int)(randNumberC * consumableDrops[consumablesNB - 1]);
        }
        *weaponsIndex = findValue(weaponDrops, weaponsNB, weaponDrop);
        *consumablesIndex = findValue(consumableDrops, consumablesNB, consumableDrop);
        *matsIndex = (int)((double)rand() / (RAND_MAX + 1.0) * 3);
    }
    else {
        printf("RARE CHESTS NOT IMPLEMENTED YET\n");
    }
}

int findValue(int *itemDrops, int itemsNB, int randomValue) {
    int left = 0, right = itemsNB - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (randomValue <= itemDrops[mid])
            right = mid;
        else
            left = mid + 1;
    }
    return left;  // The selected weapon index
}
