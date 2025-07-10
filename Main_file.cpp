#include <cstdlib>
#include <iostream>
#include <string>

// Weapon Type Enumeration
enum WeaponType{
    Sword = 1,
    Dagger,
    Staff,
    Trident,
    Long_Sword,
    Bow,
    Axe,
    Spear,
};

// Element Type Enumeration
enum ElementType{
    None = 0,
    Pyro,
    Hydro,
    Cyro,
    Dendro,
    Electro,
    Anemo,
    Geo,
    Lux,
    Umbra,
};

// Level Type Enumeration
enum LevelTyoe{
    None_Lvl = 0,
    Low_Lvl = 30,
    Mid_Lvl = 60,
    High_Lvl = 90,
};

// Rarity Type Enumeration
enum RarityType{
    Human = 1,
    Immortal,
    Saint,
    God,
    Divine,
    Supreme,
};

// Weapon class definition
class Weapon{
private:
    WeaponType wType;
    ElementType eType;
    LevelTyoe lType;
    RarityType rType;
    std::string wName;
    int wDmg;

public:
    // Default constructor
    Weapon(){
        wType = Dagger;
        eType = Umbra;
        lType = Mid_Lvl;
        rType = Divine;
        wName = " Daggers of Abyss ";
        wDmg = 800;
    }

    // Parameterized constructor
    Weapon(WeaponType TypeW, ElementType TypeE, LevelTyoe TypeL, RarityType TypeR, std::string TypeN, int TypeD){
        wType = TypeW;
        eType = TypeE;
        lType = TypeL;
        rType = TypeR;
        wName = TypeN;
        wDmg = TypeD;
    }

    // Getters
    auto getName() const { return wName; } // Used for searching  by Name
    auto getDmg() const { return wDmg; } // Used for sorting byDmg
    auto getRarity() const { return rType; } // Used for sorting by Rarity
    LevelTyoe &getLvl() { return lType; } // Reference to level (for upgrading)
    auto getSortLvl() const { return lType; } // Used for sorting by level

    // Static helper functions to convert enums to strings
    static std::string getWeaponInfo(WeaponType w){
        switch (w) {
            case Sword: return "Sword";
            case Dagger: return "Dagger";
            case Staff: return "Staff";
            case Trident: return "Trident";
            case Long_Sword: return "Long_Sword";
            case Bow: return "Bow";
            case Axe: return "Axe";
            case Spear: return "Spear";
            default: return "Unkown";
        }
    }

    static std::string getElementInfo(ElementType e){
        switch(e){
            case None: return "None";
            case Pyro: return "Pyro";
            case Hydro: return "Hydro";
            case Cyro: return "Cyro";
            case Dendro: return "Dendro";
            case Electro: return "Electro";
            case Anemo: return "Anemo";
            case Geo: return "Geo";
            case Lux: return "Lux";
            case Umbra: return "Umbra";
            default: return "Unkown";
        }
    }

    static std::string getRarityInfo(RarityType r){
        switch(r){
            case Human: return "Human";
            case Immortal: return "Immortal";
            case Saint: return "Saint";
            case God: return "God";
            case Divine: return "Divine";
            case Supreme: return "Supreme";
            default: return "Unkown";
        }
    }

    static std::string getLevelInfo(LevelTyoe l){
        switch(l){
            case None_Lvl: return "None_Lvl";
            case Low_Lvl: return "Low_Lvl";
            case Mid_Lvl: return "Mid_Lvl";
            case High_Lvl: return "High_Lvl";
            default: return "Unknown";
        }
    }

    // Method to upgrade level
    void Upgrade_Lvel(LevelTyoe &uLvl){
        switch (uLvl) {
            case None_Lvl: uLvl = Low_Lvl; wDmg += rand()%150+1; break;
            case Low_Lvl: uLvl = Mid_Lvl; wDmg += rand()%250+1; break;
            case Mid_Lvl: uLvl = High_Lvl; wDmg += rand()%359+1; break;
            case High_Lvl: std::cout << "You've reached the maximum Level "; break;
            default: std::cout << " Unkown "; break;
        }
    }

    // Displays full stats of the weapon
    void Display_Stats(){
        std::cout << " Name of ya Weapon : " << wName
                  << " | Ya Weapon's Type : " << getWeaponInfo(wType)
                  << " | Ya Weapon's Element : " << getElementInfo(eType)
                  << " | Ya Weapon's Rarity : " << getRarityInfo(rType)
                  << " | Ya Weapon's Level : " << getLevelInfo(lType)
                  << " | Ya Weapon's Dmg output : " << wDmg << " \n ";

        }
    // ASCII art for exit
    void byeAscci() {
        std::cout << "(\\_/) \n";
        std::cout << "(｡•́︿•̀｡) \n";
        std::cout << " > ^ <  \n";
        std::cout << " /    \\  \n";
        std::cout << "/(\")(\") \n";
        std::cout << "||=======|| \n";
        std::cout << "||ByeBye || \n";
        std::cout << "||=======|| \n";
    }

    // ASCII art for welcome
    void welcomeAscci() {
        std::cout << "(\\_/) \n";
        std::cout << "(@ . ^) \n";
        std::cout << " > ^ <  \n";
        std::cout << " /    \\  \n";
        std::cout << "/(\")(\") \n";
        std::cout << "||=======|| \n";
        std::cout << "||Welcome|| \n";
        std::cout << "||=======|| \n";
    }
};

// Global Inventory Setup
Weapon *Inventory;
int maxInventoryCount;
int currentInventoryCount = 0;

// Add new weapon to inventory
void addStuff(int &addCount, int maxCount){
    std::cout << "/================({|})==================/ \n ";
    int addW, addE, addL, addDz, addR;
    std::string addN;

    if(addCount >= maxCount){
        std::cout << " Inventory's full \n ";
        return;
    }

    std::cout << " Adding Weapons to Inventory \n ";

    std::cout << " What type of weapon do you wanna add? ";
    std::cout << "Sword[1] \nDagger[2] \nStaff[3] \nTrident[4] \nLong_Sword[5] \nBow[6] \nAxe[7] \nSpear[8] \n ";
    std::cin >> addW;

    if(addW < Sword || addW > Spear){
        std::cout << " Weird I've never seen such weapon before.\n ";
        return;
    }

    std::cout << " What's ya Weapon's Name : ";
    std::getline(std::cin >> std::ws, addN);

    std::cout << " What's ya Weapon's Element ? \n ";
    std::cout << "None[0] \nPyro[1] \nHydro[2] \nCyro[3] \nDendro[4] \nElectro[5] \nAnemo[6] \nGeo[7] \nLux[8] \nUmbra[9] \n ";
    std::cin >> addE;

    if(addE < Pyro || addE > Umbra){
        std::cout << " Invalid element selected \n ";
        return;
    }

    std::cout << " What's ya Weapon's Level ? \n ";
    std::cout <<  "Non-Lvl[0] \nLow_Lvl[30] \nMid_Lvl[60] \nHigh_Lvl[90] \n ";
    std::cin >> addL;

    if(addL < Low_Lvl || addL > High_Lvl){
        std::cout << " Invalid level input \n ";
        return;
    }

    std::cout << " What's ya weapon's Rarity ? \n ";
    std::cout << "Human[1] \nImmortal[2] \nSaint[3] \nGod[4] \nDivine[5] \nSupreme[6] \n ";
    std::cin >> addR;

    if(addR < Human || addR > Supreme){
        std::cout << " Invalid rarity \n ";
        return;
    }

    std::cout << " What's ya weapon's output Dmg? \n ";
    std::cin >> addDz;

    // Creating new weapon and adding to inventory
    Inventory[addCount] = Weapon(
        static_cast<WeaponType>(addW),
        static_cast<ElementType>(addE),
        static_cast<LevelTyoe>(addL),
        static_cast<RarityType>(addR),
        addN,
        addDz
    );

    addCount++;
    std::cout << " Weapon Added To Inventory\n";
    std::cout << "/================({|})==================/ \n     ";
}

// Remove weapon by index
void removeStuff(int &removeCount){
    std::cout << "|~@~@~@~@~@~@~@~@~{[<+>]}~@~@~@~@~@~@~@~@~| \n";
    int index;
    std::cout << " Enter index of weapon to remove [1 to " << removeCount << "] : ";
    std::cin >> index;
    index--;

    if(index < 0 || index >= removeCount){
        std::cout << " Invalid Index Input \n ";
        return;
    }

    // Shift remaining weapons back
    for(int r = index; r < removeCount - 1; r++){
        Inventory[r] = Inventory[r + 1];
    }

    removeCount--;
    std::cout << " Weapon Removed \n ";
    std::cout << "|~@~@~@~@~@~@~@~@~{[<+>]}~@~@~@~@~@~@~@~@~| \n";
}

// Search weapon by name (substring)
void searchByName(int &searchCount){
    std::cout << "-_-_-_-_-_-_-_-_-_-_-([/|\\])-_-_-_-_-_-_-_-_-_- \n";
    std::string query;
    bool foundIT = false;

    std::cout << " Enter weapon name to search: ";
    std::getline(std::cin >> std::ws, query);

    for(int q = 0; q < searchCount; q++){
        if(Inventory[q].getName().find(query) != std::string::npos){
            Inventory[q].Display_Stats();
            foundIT = true;
        }
    }

    if(!foundIT){
        std::cout << " No match found for '" << query << "'\n";     std::cout << "-_-_-_-_-_-_-_-_-_-_-([/|\\])-_-_-_-_-_-_-_-_    -_- \n";
    }
}

// Upgrade weapon level
void upgradeStuff(int &upgradeCount){
    std::cout << "\\*_*_*_*_*_*_*_*_*_*_*{</>}*_*_*_*_*_*_*_*_*_* \\ \n";
    int index;
    std::cout << " Select weapon to upgrade [1 to " << upgradeCount << "] : ";
    std::cin >> index;
    index--;

    if(index < 0 || index >= upgradeCount){
        std::cout << " Invalid Index Input \n ";
        return;
    }

    // Actually upgrade level
    Inventory[index].Upgrade_Lvel(Inventory[index].getLvl());
    Inventory[index].Display_Stats();
    std::cout << " Weapon Upgraded \n ";
    std::cout << "\\*_*_*_*_*_*_*_*_*_*_*{</>}*_*_*_*_*_*_*_*_*    _* \\ \n";
}

// Sort weapons by dmg (descending)
void sortByDmg(int &dmgCount){
    std::cout << "<<===== 🗡️Sorting by Dmg 🗡️ =====>> \n";
    for(int j = 0; j < dmgCount - 1; j++){
        for(int k = j + 1; k < dmgCount; k++){
            if(Inventory[j].getDmg() < Inventory[k].getDmg()){
                std::swap(Inventory[j], Inventory[k]);
            }
        }
    }
    std::cout << " Weapons sorted by dmg \n ";
    std::cout << "<<===== 🗡️ DONE 🗡️ =====>> \n";
}

// Sort weapons by rarity (descending)
void sortByRarity(int &rarityCount){
    std::cout << "<<===== 🗡️Sorting by Rarity  🗡️ =====>> \n";
    for(int m = 0; m < rarityCount - 1; m++){
        for(int n = m + 1; n < rarityCount; n++){
            if(Inventory[m].getRarity() < Inventory[n].getRarity()){
                std::swap(Inventory[m], Inventory[n]);
            }
        }
    }
    std::cout << " Weapons sorted by rarity \n ";
    std::cout << "<<===== 🗡️ DONE 🗡️ =====>> \n";
}

// Sort weapons by level (descending)
void getSortByLvl(int &lvlCount){
    std::cout << "<<===== 🗡️Sorting by Level 🗡️ =====>> \n";
    for(int w = 0; w < lvlCount - 1; w++){
        for(int x = w + 1; x < lvlCount; x++){
            if(Inventory[w].getSortLvl() < Inventory[x].getSortLvl()){
                std::swap(Inventory[w], Inventory[x]);
            }
        }
    }
    std::cout << " Weapons sorted by level \n ";
    std::cout << "<<===== 🗡️ DONE 🗡️ =====>> \n";
}

// View all weapons
void viewStuff(int &viewCount){
    std::cout << "/=============(View)==========\\ \n";
    if(viewCount == 0){
        std::cout << " The Inventory is empty \n ";
        return;
    }

    for(int u = 0; u < viewCount; u++){
        std::cout << (u + 1) << ". ";
        Inventory[u].Display_Stats();
    }
    std::cout << "/=============(Done Viewing )==========\\ \n";
}

// Main menu to control all actions
void mainMenu(){
    char op;
    std::cout <<"|============ Main Menu ===========| \n ";

    std::cout << "\nChoose an option:\n";
    std::cout << "Add Weapons[A] \nRemove Weapons[R] \nSearch Weapons by Name[S] \nSort by Dmg[D] \nSort by Rarity[G] \nSort by Level[L] \nUpgrade Weapon[U] \nView Inventory[V] \nQuit[Q] \n> ";
    std::cin >> op;

    switch (op) {
        case 'A': addStuff(currentInventoryCount, maxInventoryCount); break;
        case 'R': removeStuff(currentInventoryCount); break;
        case 'S': searchByName(currentInventoryCount); break;
        case 'D': sortByDmg(currentInventoryCount); break;
        case 'G': sortByRarity(currentInventoryCount); break;
        case 'L': getSortByLvl(currentInventoryCount); break;
        case 'U': upgradeStuff(currentInventoryCount); break;
        case 'V': viewStuff(currentInventoryCount); break;
        case 'Q':
            Inventory->byeAscci();
            std::cout << " Exiting program \n"; delete[] Inventory;
            std::cout << "}======== ACTION COMPLETE ========{ \n ";
            exit(EXIT_SUCCESS); break;
        default: std::cout << " Invalid input, try again \n"; break;
    }
}

// Main function
int main(){

    Inventory->welcomeAscci();

    std::cout << "+------------------------------+\n";
    std::cout << "|   RPG Weapon Inventory 5.0  |\n";
    std::cout << "+------------------------------+\n";
    std::cout << " Enter Max Inventory Size: ";
    std::cin >> maxInventoryCount;

    Inventory = new Weapon[maxInventoryCount];

    while (true) {
        mainMenu();
    }

    return 0;
}