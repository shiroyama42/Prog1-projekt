#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <cstdlib>

using namespace std;

struct items{
    std::string name;
    int power;
};

vector<items> roll_items(){

    vector<items> item_pool{{"Butter Knife", 5},
                            {"Stabby Stabby Knife", 4},
                            {"Noob Hammer", 4},
                            {"Zenith", 3},
                            {"Tinfoil Hat", 3},
                            {"Fairy Princess Tiara", 3},
                            {"Spear of Longinus", 3},
                            {"Laser Sword", 2},
                            {"Mongolian Bow", 2},
                            {"Magic wand", 2},
                            {"Diamond Sword", 2},
                            {"Archmage Wand", 1},
                            {"Shuriken", 1},
                            {"Broken Bottle", 1},
                            {"Wand of Wizarding", 1}};

    return item_pool;
}

vector<items> roll_monsters(){
    vector<items> monster_pool{{"Ramiel", 15},
                               {"Big Smoke", 10},
                               {"Ding Ding", 8},
                               {"Eren Yeager", 7},
                               {"Goku", 5},
                               {"Ban Hammer", 5},
                               {"Anya", 8},
                               {"Muscle Man", 3},
                               {"Springy Beke", 2},
                               {"Rock Solid", 3},
                               {"Asian dude with a big mustache", 2},
                               {"Zodd", 2},
                               {"C Tubro", 1},
                               {"Sinji", 0}};


    return monster_pool;
}

void levels(){
    int i = 1;
    vector<items> inventory;
    vector<items> item_pool = roll_items();
    vector<items> monster_pool = roll_monsters();
    srand(time(NULL));
    bool death = false;
    int power_sum;
    while(i <= size(monster_pool) && !death){

        if (system("CLS")) system("clear");
        power_sum = 0;
        cout << "Room " << i << endl;
        cout << "Inventory: ";
        for(int j = 0; j < inventory.size(); j++){
            cout << inventory[j].name << ", ";
            power_sum += inventory[j].power;
        }
        cout << endl;
        cout << "Power: " << power_sum << endl << endl;

        if(i % 3 == 0){
            for(int j = 0; j < size(monster_pool); j++){
                monster_pool[j].power *= 1.2;
            }
        }

        if(i == 1){
            cout << "You search this room and find no monsters and you find a(n) ";
            int random_num = rand() % size(item_pool);
            cout << item_pool[random_num].name << " with a power of " << item_pool[random_num].power << "!" << endl;
            inventory.push_back(item_pool[random_num]);
            item_pool.erase(item_pool.begin() + random_num);
            cout << endl << "You decide to go deeper into the dungeon!" << endl;
            int rand_int = rand() % 3 + 1;
            switch(rand_int){
                case 1:
                    cout << "Now you enter the only door leading out of this room!" << endl;
                    break;
                case 2:
                    cout << "You must now decide which door to open next!" << endl
                         << "1. Left" << endl
                         << "2. Right" << endl;
                    break;
                case 3:
                    cout << "You must now decide which door to open next!" << endl
                         << "1. Left" << endl
                         << "2. Middle" << endl
                         << "3. Right" << endl;
            }
            cin.ignore();
            cin.get();
        }
        else{
            cout << "You search this room and find a monster" << endl;
            int random_num = rand() % size(monster_pool);
            cout << "The monster is " << monster_pool[random_num].name << " with the power level of " << monster_pool[random_num].power << "!" << endl;
            char fight_run;
            cout << endl;
            cout << "You have two options: " << endl
                 << "1. Fight " << monster_pool[random_num].name << "!" << endl
                 << "2. Nigerundayoooooo (run)!" << endl;
            cin >> fight_run;
            int dice;
            switch(fight_run){
                case '1':
                    cout << "You decided to fight " << monster_pool[random_num].name << "!" << endl;
                    if(power_sum < monster_pool[random_num].power){
                        cout << "Your power is lower, your only option is to run into the next room!" << endl;
                        cout << "You must roll the dice!" << endl
                             << "To escape you must roll 4, 5 or 6, in any other case you die!" << endl << endl;
                        cin.ignore();
                        cin.get();
                        dice = rand() % 6 + 1;
                        cout << "You have rolled " << dice << "!" << endl << endl;
                        if(dice == 4 || dice == 5 || dice == 6){
                            cout << "Nice, you have escaped into an other room, however you couldn't bring the item from the previous room!" << endl;
                            monster_pool.erase(monster_pool.begin() + random_num);
                            cin.get();
                        }
                        else{
                            cout << "Unfortunately your escape was unsuccessfull, " << monster_pool[random_num].name << " killed you!" << endl;
                            death = true;
                        }
                    }
                    else if(power_sum > monster_pool[random_num].power){
                        cout << endl << "Your power is higher..." << endl << endl
                             << "An epic clash started between Lajos and " << monster_pool[random_num].name << " has started..." << endl
                             << "The victor is Lajos!" << endl
                             << "Congratulations!" << endl;
                        monster_pool.erase(monster_pool.begin() + random_num);
                        random_num = rand() % size(item_pool);
                        if(i == size(monster_pool)){
                            cout << endl << "You cleared all the rooms!" << endl;
                        }
                        else{
                            cout << "You search the room and find a(n) " << item_pool[random_num].name << " with a power of " << item_pool[random_num].power << "!" << endl;
                            inventory.push_back(item_pool[random_num]);
                            item_pool.erase(item_pool.begin() + random_num);
                            cout << endl << "You decide to go deeper into the dungeon!" << endl;
                            int rand_int = rand() % 3 + 1;
                            switch(rand_int){
                                case 1:
                                    cout << "Now you enter the only door leading out of this room!" << endl;
                                    break;
                                case 2:
                                    cout << "You must now decide which door to open next!" << endl
                                         << "1. Left" << endl
                                         << "2. Right" << endl;
                                    break;
                                case 3:
                                    cout << "You must now decide which door to open next!" << endl
                                         << "1. Left" << endl
                                         << "2. Middle" << endl
                                         << "3. Right" << endl;
                            }
                        }
                        cin.ignore();
                        cin.get();
                    }
                    else{
                        cout << "Your powers are the same, you must roll the dice!" << endl
                             << "If you roll 4, 5 or 6 you win the fight" << endl
                             << "If you don't your only option is to run, so you must roll the dice again!" << endl;
                        dice = rand() % 6 + 1;
                        cout << "Ready? Let's start!" << endl << endl;
                        cin.ignore();
                        cin.get();
                        cout << "You have rolled " << dice << "!" << endl;
                        if(dice == 4 || dice == 5 || dice == 6){
                            cout << "After a long and tiring fight you end up victorious!" << endl
                                 << "Congratulations!" << endl;
                            random_num = rand() % size(item_pool);
                            if(i == size(monster_pool)){
                                cout << endl << "You have escaped all the rooms!" << endl;
                            }
                            else{
                                cout << "You search the room and find a(n) " << item_pool[random_num].name << " with a power of " << item_pool[random_num].power << "!" << endl;
                                inventory.push_back(item_pool[random_num]);
                                item_pool.erase(item_pool.begin() + random_num);
                                cout << endl << "You decide to go deeper into the dungeon!" << endl;
                                int rand_int = rand() % 3 + 1;
                                switch(rand_int){
                                    case 1:
                                        cout << "Now you enter the only door leading out of this room!" << endl;
                                        break;
                                    case 2:
                                        cout << "You must now decide which door to open next!" << endl
                                             << "1. Left" << endl
                                             << "2. Right" << endl;
                                        break;
                                    case 3:
                                        cout << "You must now decide which door to open next!" << endl
                                             << "1. Left" << endl
                                             << "2. Middle" << endl
                                             << "3. Right" << endl;
                                }
                                cin.ignore();
                                cin.get();
                            }
                        }
                        else{
                            cout << "Quickly, roll again so maybe you can still survive the encounter!" << endl
                                 << "To successfully escape you must roll 4, 5, or 6, in any other case you die!" << endl << endl;
                            cin.ignore();
                            cin.get();
                            dice = rand() % 6 + 1;
                            cout << "You have rolled " << dice << "!" << endl;
                            if(dice == 4 || dice == 5 || dice == 6){
                                cout << "Nice, you have escaped into an other room, however you couldn't bring the item from the previous room!" << endl;
                                monster_pool.erase(monster_pool.begin() + random_num);
                                cin.get();
                            }
                            else{
                                cout << "Unfortunately your escape was unsuccessfull, " << monster_pool[random_num].name << " killed you!" << endl;
                                death = true;
                            }
                        }
                    }
                    break;
                case '2':
                    cout << endl << "You have decided to run!" << endl;
                    cout << "You must roll the dice in other to escape!" << endl;
                    cout << "You must roll 4, 5 or 6, in any other case your escape is unsuccessfull!" << endl
                         << "In this case you can still try to fight " << monster_pool[random_num].name << "!" << endl << endl;
                    cin.get();
                    dice = rand() % 6 + 1;
                    cout << "Ready? Let's start!" << endl << endl;
                    cin.get();
                    cout << "You have rolled " << dice << "!" << endl;
                    if(dice == 4 || dice == 5 || dice == 6){
                        cout << "You have successfully escaped into an other room, however you couldn't bring the item from the previous room!" << endl;
                        monster_pool.erase(monster_pool.begin() + random_num);
                        cin.get();
                    }
                    else{
                        cout << "Unfortunately your escape was unsuccessfull, you must fight!" << endl;
                        if(power_sum < monster_pool[random_num].power){
                            cout << "Your power is lower, " << monster_pool[random_num].name << "'s strenght is too much for you to handle!" << endl;
                            death = true;
                        }
                        else if(power_sum > monster_pool[random_num].power){
                            cout << endl << "Your power is higher..." << endl << endl
                                 << "An epic clash started between Lajos and " << monster_pool[random_num].name << " has started..." << endl
                                 << "The victor is Lajos!" << endl
                                 << "Congratulations!" << endl;
                            monster_pool.erase(monster_pool.begin() + random_num);
                            random_num = rand() % size(item_pool);
                            if(i == size(monster_pool)){
                                cout << endl << "You cleared all the rooms!" << endl;
                            }
                            else{
                                cout << "You search the room and find a(n) " << item_pool[random_num].name << " with a power of " << item_pool[random_num].power << "!" << endl;
                                inventory.push_back(item_pool[random_num]);
                                item_pool.erase(item_pool.begin() + random_num);
                                cout << endl << "You decide to go deeper into the dungeon!" << endl;
                                int rand_int = rand() % 3 + 1;
                                switch(rand_int){
                                    case 1:
                                        cout << "Now you enter the only door leading out of this room!" << endl;
                                        break;
                                    case 2:
                                        cout << "You must now decide which door to open next!" << endl
                                             << "1. Left" << endl
                                             << "2. Right" << endl;
                                        break;
                                    case 3:
                                        cout << "You must now decide which door to open next!" << endl
                                             << "1. Left" << endl
                                             << "2. Middle" << endl
                                             << "3. Right" << endl;
                                }
                            }
                            cin.ignore();
                            cin.get();
                        }
                        else{
                            cout << "Your powers are the same, you must roll the dice!" << endl
                                 << "If you roll 4, 5 or 6 you win the fight" << endl;
                            cin.get();
                            dice = rand() % 6 + 1;
                            cout << "You have rolled " << dice << "!" << endl;
                            if(dice == 4 || dice == 5 || dice == 6){
                                cout << "After a long and tiring fight you end up victorious!" << endl
                                     << "Congratulations!" << endl;
                                monster_pool.erase(monster_pool.begin() + random_num);
                                random_num = rand() % size(item_pool);
                                if(i == size(monster_pool)){
                                    cout << endl << "You cleared all the rooms!" << endl;
                                }
                                else{
                                    cout << "You search the room and find a(n) " << item_pool[random_num].name << " with a power of " << item_pool[random_num].power << "!" << endl;
                                    inventory.push_back(item_pool[random_num]);
                                    item_pool.erase(item_pool.begin() + random_num);
                                    cout << endl << "You decide to go deeper into the dungeon!" << endl;
                                    int rand_int = rand() % 3 + 1;
                                    switch(rand_int){
                                        case 1:
                                            cout << "Now you enter the only door leading out of this room!" << endl;
                                            break;
                                        case 2:
                                            cout << "You must now decide which door to open next!" << endl
                                                 << "1. Left" << endl
                                                 << "2. Right" << endl;
                                            break;
                                        case 3:
                                            cout << "You must now decide which door to open next!" << endl
                                                 << "1. Left" << endl
                                                 << "2. Middle" << endl
                                                 << "3. Right" << endl;
                                    }
                                }
                                cin.get();
                            }
                            else{
                                cout << "After a long and tiring fight " << monster_pool[random_num].name <<  " ends up victorious!" << endl;
                                death = true;
                            }
                        }
                    }
                    break;
                default:
                    cout << "Your decisidion took too long... " << monster_pool[random_num].name << " has killed you!" << endl;
                    death = true;
            }
        }
        i++;
    }
    if(death){
        cout << endl << "YOU DIED" << endl
             << "GAME OVER!" << endl;
        cin.get();
    }
    else{
        cout << endl << "Congratulations! You have successfully escaped the dark dungeon, you have won!" << endl;
        cin.get();
    }
    cin.get();
};

void beggining(){
    using namespace std;
    string character;
    cout << "Welcome to the GAME!" << endl
         << "Please enter your character's name:" << endl;
    cin >> character;
    character = "Lajos";
    cout << endl;
    cout << "Are you sure you want to name your character Lajos? (y/n)" << endl;
    string asd;
    cin >> asd;
    cout << "All right your name is now Lajos!" << endl;
    cout << endl << endl;
    cout << "Rules: " << endl
         << "- You can only defeat monsters who are on the same or lower power than you" << endl
         << "- During each monster interaction you can either decide to fight it or run from it" << endl
         << "- If you fight, you can only defeat it if your power is higher" << endl
         << "- If your power is equal, you can roll the dice: if it is 4 or above you win and get an item,\n"
               "  in any other case you lose and you die" << endl
         << "- You can run into an other room, but it only suceeds if you roll 4 or more with the dice, if not, you must fight it" << endl
         << "- Enjoy the game!" << endl << endl
         << "- No balance patches!" << endl;
    cin.get();
    cout << endl << "Ready to start? (y/n)" << endl;
    cin >> asd;
    switch(asd[0]){
        case 'y':
        case 'Y':
            if (system("CLS")) system("clear");
            cout << "You suddenly woke up and found yourself in a dungeon..." << endl
                 << "There is only a single, wooden door leading out of this dark and cold room, however you can not see what is behind it..." << endl
                 << "You walk in..." << endl;
            cin.get();
            break;

        case 'n':
        case 'N':
            cout << endl << "ENTER YES!" << endl;
            cin >> asd;
            switch(asd[0]){
                case 'y':
                    if (system("CLS")) system("clear");
                    cout << "You suddenly woke up and found yourself in a dungeon..." << endl
                         << "There is only a single, wooden door leading out of this dark and cold room,\n however you can not see what is behind it..." << endl
                         << "You walk in..." << endl;
                    cin.get();
                    break;

                default:
                    cout << "Misinput..." << endl;
                    cin.ignore();
                    cin.get();
                    exit(0);
            }
            break;

        default:
            cout << "MISINPUT! IT WAS A MISINPUT" << endl;
            cin.ignore();
            cin.get();
            exit(0);
    }
}

int main() {
    srand(time(NULL));
    beggining();
    cin.get();
    levels();
    return 0;
}