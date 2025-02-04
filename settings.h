//
// Created by pablo on 2/2/2025.
//

#ifndef SETTINGS_H
#define SETTINGS_H

//===============================Includes======================================
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


//===============================Functions=====================================

/**
 * @brief Clears the input buffer
 */
void clearInputBuffer();

/**
 * @brief Displays the main menu
 */
void displayMainMenu();

/**
 * @brief Displays the settings menu
 */
void displaySettingsMenu();

/**
 * @brief Displays the chest menu
 */
void displayChestMenu();
/**
 * @brief Associates each rarity number with its name
 *
 * @param rarity the rarity number
 * @return the rarity name
 */
const char* rarityDic(int rarity);

/**
 * @brief Associates each weapon type number with its name
 *
 * @param type the type number
 * @return the type name
 */
const char* typeDic(int type);

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
int weaponCreation(int currsize, int currID, char name[], int type, int rarity, float dropchance);

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
int consumableCreation(int currsize, int currID, float dropchance, int number, int rarity, char name[]);

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
 * @brief Displays the weapons
 *
 * @param size the number of weapons
 */
void displayWeapons(int size);

/**
 * @brief Displays the consumables
 *
 * @param size the number of consumables
 */
void displayConsumables(int size);

/**
 * @brief Deletes an item
 *
 * @param type the type of item (0 for weapon, 1 for consumable)
 * @param size the number of items
 *
 * @return number of items deleted
 */
int deleteItem(int type, int size);

/**
 * @brief Opens a chest
 *
 * @param rarity rarity of the chest
 * @param weaponsIndex to store the index of the weapon obtained
 * @param consumablesIndex to store the index of the consumable obtained
 * @param matsIndex to store the index of the mats obtained
 * @param weaponsNB number of weapons
 * @param consumablesNB number of consumables
 *
 * @note The 3 pointers values will be modified
 */
void openChest(int rarity, int *weaponsIndex, int *consumablesIndex, int *matsIndex, int weaponsNB, int consumablesNB);

/**
 * @brief Finds the value in the itemDrops array
 *
 * @param itemDrops array of item drops
 * @param itemsNB number of items
 * @param randomValue random value
 *
 * @return the index of the item
 *
 * @note This is a binary search
 */
int findValue(int *itemDrops, int itemsNB, int randomValue);

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
 * @brief Fills the consumables array thanks to a provided file
 *
 * @param filename the file to read
 * @param currID closest ID available
 * @param size number of consumables before hardfill
 *
 * @return closest available ID
 */
int hardFillConsumables(const char *filename, int currID, int size);
#endif //SETTINGS_H
