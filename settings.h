//
// Created by pablo on 2/2/2025.
//

#ifndef SETTINGS_H
#define SETTINGS_H

//===============================STRUCTURES======================================
struct weapons{
    int id;
    int dropchance;//from 1(0.01%) to 10000(100%)
    int rarity; //0 for common, 1 for uncommon, 2 for rare, 3 for epic, 4 for legendary
    int type; //0 for shotgun, 1 for AR, 2 for SMG, 3 for sniper, 4 for pistol, 5 for explosive
    char name[30];
};

extern struct weapons weapons[];

struct consumables {
    int id;
    float dropchance;
    int quantity; //how much will it drop in
    int rarity;
    char name[30];
};

extern struct consumables consumables[];

struct mats {
    int id;
    int dropchance;
    char name[30];
};

extern struct mats mats[];

struct chest {  //struct allows to determine if this will be a common or rare chest,
                //and what loot it will contain
    int loot;  //every loot item will have an ID.
                //Chest contains a weapon, ammo for that weapon, a consumable and mats. Can also
                //contain gold
    int rarity;//0 for common, 1 for rare
};


//===============================FUNCTIONS=====================================

//display & dictionary functions

/**
 * @brief Displays the chest menu
 */
void displayChestMenu();

/**
 * @brief Displays the hardfill menu
 *
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 * @param filenameW filename for weapons
 * @param filenameC filename for consumables
 */
void displayHardfillMenu(const int weaponsNB, const int consumablesNB, const char *filenameW, const char *filenameC);

/**
 * @brief Displays the items
 *
 * @param WorC 0 for weapon, 1 for consumable
 * @param size number of items
 */
void displayItems(const int WorC, const int size);

/**
 * @brief Displays the main menu
 */
void displayMainMenu();

/**
 * @brief Displays the settings menu
 */
void displaySettingsMenu();

/**
 * @brief Associates each rarity number with its name
 *
 * @param rarity the rarity number
 * @return the rarity name
 */
const char* rarityDic(const int rarity);

/**
 * @brief Associates each weapon type number with its name
 *
 * @param type the type number
 * @return the type name
 */
const char* typeDic(const int type);


//output functions


/**
 * @brief Creates a consumable
 *
 * @param currsize number of consumables
 * @param currID ID the consumable will have
 * @param dropchance drop chance
 * @param number how much the consumable will drop in
 * @param rarity rarity
 * @param name name
 * @return closest available ID
 */
int consumableCreation(const int currsize, int currID, const float dropchance, const int number, const int rarity, char name[]);

/**
 * @brief Creates a consumable with user input
 *
 * @param currsize number of consumables
 * @param currID ID the consumable will have
 * @return closest available ID
 *
 * @note This function is foolproof
 */
int consumableCreationFoolproof(int currsize, int currID);

/**
 * @brief Deletes an item
 *
 * @param type the type of item (0 for weapon, 1 for consumable)
 * @param size the number of items
 *
 * @return number of items deleted
 */
int deleteItem(const int type, int size);

/**
 * @brief Finds the index of the item with the provided ID
 *
 * @param WorC 0 for weapon, 1 for consumable
 * @param id the ID to find
 * @param size the number of items
 *
 * @return the index of the item
 */
int findIndexWithID(const int WorC, const int id, const int size);

int findIndexWithName(const int WorC, const char name[], const int size); //NOT DONE YET

/**
 * @brief Finds the value in the itemDrops array
 *
 * @param T array of item drops
 * @param itemsNB number of items
 * @param val random value
 *
 * @return the index of the item
 *
 * @note This is a binary search
 */
int findValue(const int *T, const int itemsNB, const int val);

/**
 * @brief Fills the consumables array thanks to a provided file
 *
 * @param filename the file to read
 * @param currID closest ID available
 * @param size number of consumables before hardfill
 *
 * @return closest available ID
 */
int hardFillConsumables(const char *filename, int currID, int size);

/**
 * @brief Fills the weapons array thanks to a provided file
 *
 * @param filename the file to read
 * @param currID closest ID available
 * @param size number of weapons before hardfill
 *
 * @return closest available ID
 */
int hardFillWeapons(const char *filename, int currID, int size);

/**
 * @brief Opens chests until a certain condition is met
 *
 * @param WorC W for weapon, C for consumable
 * @param index index of the item
 * @param weaponsIndex to store the index of the weapon obtained
 * @param consumablesIndex to store the index of the consumable obtained
 * @param matsIndex to store the index of the mats obtained
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 * @param weaponDrops array of weapon drop chances
 * @param consumableDrops array of consumable drop chances
 *
 * @note The 3 pointers values will be modified
 */
int openChestUntil(const int WorC, const int *index, int *weaponsIndex, int *consumablesIndex, int *matsIndex, const int weaponsNB, const
                   int consumablesNB, const int *weaponDrops, const int *consumableDrops);

/**
 * @brief Creates a weapon
 *
 * @param currsize number of weapons
 * @param currID ID the weapon will have
 * @param dropchance drop chance
 * @param name name
 * @param rarity rarity
 * @param type weapon type
 * @return closest available ID
 */
int weaponCreation(const int currsize, int currID, char name[], const int type, const int rarity, const float dropchance);

/**
 * @brief Creates a weapon with user input
 *
 * @param currsize number of weapons
 * @param currID ID the weapon will have
 * @return closest available ID
 *
 * @note This function is foolproof
 */
int weaponCreationFoolproof(int currsize, int currID);


//void functions


/**
 * @brief Converts the chest content to a CSV file
 *
 * @param weaponCount array of weapon count
 * @param weaponsNB number of weapons
 * @param consumableCount array of consumable count
 * @param consumablesNB number of consumables
 * @param matCount array of mat count
 */
void chestToCSV(const int *weaponCount, const int weaponsNB, const int *consumableCount, const int consumablesNB, const int *matCount);

/**
 * @brief Clears the input buffer
 */
void clearInputBuffer();

/**
 * @brief Opens a chest
 *
 * @param rarity rarity of the chest
 * @param weaponsIndex to store the index of the weapon obtained
 * @param consumablesIndex to store the index of the consumable obtained
 * @param matsIndex to store the index of the mats obtained
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 * @param weaponDrops
 * @param consumableDrops
 *
 * @note The 3 pointers values will be modified
 */
void openChest(const int rarity, int *weaponsIndex, int *consumablesIndex, int *matsIndex, const int weaponsNB, const int
               consumablesNB, const int *weaponDrops, const int *consumableDrops);

/**
 * @brief Compute a list of drop chance for each item
 *
 * @param weaponDrops array of weapon drop chances
 * @param consumableDrops array of consumable drop chances
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 */
void computeDropChances(int *weaponDrops, int *consumableDrops, const int weaponsNB, const int consumablesNB);

/**
 * @brief Opens 1000 chests and keeps track of stats
 *
 * @param X number of chests to open
 * @param weaponsCount to store the index of the weapon obtained
 * @param consumablesCount to store the index of the consumable obtained
 * @param matsCount to store the index of the mats obtained
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 * @param weaponDrops array of weapon drop chances
 * @param consumableDrops array of consumable drop chances
 *
 * @note The 3 pointers values will be modified
 */
void openXChests(const int X, unsigned int *weaponsCount, unsigned int *consumablesCount, unsigned int *matsCount, const int weaponsNB, const int
                 consumablesNB, const int *weaponDrops, const int *consumableDrops);


#endif //SETTINGS_H
