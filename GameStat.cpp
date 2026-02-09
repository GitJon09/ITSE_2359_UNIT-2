/****************************************************
*Author: Jonathan Ortiz
*Date: 1-28-2026
*Description: project focusing on menu-driven design for user input.
***************************************************** 
*/
#include <iostream>
using namespace std;

#include <string>
#include <fstream>
#include <string>
#include <limits>

int main() { //main menu loop
    string cName; //character name
    string characters[] = {};
    int cClass; //character class (1.fighter/2.psychic/3.weapons spec/4.beast)
    int lvl = 1; //character level starts back to 1
    int strength = 10; //character base stat
    int intel = 10; //character base stat
    int agility = 10; //character base stat
    int constitution = 10; //character base stat
    int hp = constitution * 10; //health points
    int ep = intel * 10; //energy points
    int atk = 10; //attack power 
    int def = (constitution + agility)/2; //defense power
    const int MAX_LVL = 10; //max character level
    string classNames[] = {"Fighter", "Psychic", "Weapon Specialist", "Beast"};
    int choice; //main menu choice(1-5)
    
    do {//runs menu until user chooses to exit 
    cout << "\n==GAMESTAT GAME MANAGER==" << endl;
    cout << "1. Create New Character" << endl;
    cout << "2. View Character Stats" << endl;
    cout << "3. Calculate Combat Ratings" << endl;
    cout << "4. Level Up Character" << endl;
    cout << "5. Exit " << endl;
    cout << "Enter your choice from 1-5: " << endl;
    cin >> choice;
        if (cin.fail()) { //input validation for non-integer input
            cin.clear(); //clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard invalid input
            cerr << "Invalid input. Please enter a number from 1-5." << endl;
            continue;
        }
    
    switch (choice) {
        /************************
        * 1. CREATE NEW CHARACTER*
        *************************/
        case 1: //nested switch case
        // ********declared variables in order to refresh character stats***********
            lvl = 1; //character level starts back to 1
            strength = 10; 
            intel = 10; 
            agility = 10; 
            constitution = 10; 
            hp = constitution * 10; 
            ep = intel * 10; 
            atk = 10; 
            def = (constitution + agility)/2; //defense power 
        // ***************User prompted to create character************************
            cout << "\n==CREATE NEW CHARACTER==" << endl;
            cout << "Enter character name: " << endl;
            cin.ignore();
            getline(cin, cName);
            cout << "\nWelcome, " << cName << endl;
            do {
            cout << "\nChoose your class (1-4):" << endl;
            cout << "1. Fighter" << endl;
            cout << "2. Psycic" << endl;
            cout << "3. Weapon Specialist" << endl;
            cout << "4. Beast" << endl;
            cin >> cClass;
            switch (cClass) {
                case 1: //fighter class output and stat adjustments
                    cout << "\nYour have created " << cName << " the Fighter!" << endl;
                    strength *= 1.4;
                    intel *= 1.3;
                    agility *= 1.3;
                    constitution *= 1.4;
                        break;
                case 2: //psychic class output and stat adjustments
                    cout << "\nYour have created " << cName << " the Psychic!" << endl;
                    strength *= 1.3;
                    intel *= 1.5;
                    agility *= 1.4;
                    constitution *= 1.2;
                        break;
                case 3: //weapon specialist class output and stat adjustments
                    cout << "\nYour have created " << cName << " the Weapon Specialist!" << endl;
                    strength *= 1.3;
                    intel *= 1.4;
                    agility *= 1.5;
                    constitution *= 1.2;
                        break;
                case 4: //beast class output and stat adjustments
                     cout << "\nYour have created " << cName << " the Beast!" << endl;
                     strength *= 1.5;
                     intel *= 1.2;
                     agility *= 1.2;
                     constitution *= 1.5;
                        break;
                default:
                cout << "\nInvalid entry. Try again." << endl;
            }
            } while (cClass <= 0 || cClass > 4);
            break;
            /**************
            * 2. VIEW STATS* 
            ***************/
        case 2: // Viewing character stats for created character
            cout << "\n==CHARACTER STATS==" << endl;
            cout << "\n" << cName << " the " << classNames[cClass - 1] << ":" << endl;
            cout << "Level: " << lvl << endl;
            cout << "\nStrength: " << strength << endl;
            cout << "Intellect: " << intel << endl;
            cout << "Agility: " << agility << endl;
            cout << "Constitution: " << constitution << endl;
            cout << "\nCombat Stats:" << endl;
            cout << "HP: " << hp << endl;
            cout << "EP: " << ep << endl;
            cout << "ATK: " << atk << endl;
            cout << "DEF: " << def << endl;
            break;
            /****************************
            * 3. CALCULATE COMBAT RATINGS*
            *****************************/
        case 3: // Calculating combat ratings using for loops
            cout << "\n>Calculated combat ratings for " << cName << " the " << classNames[cClass - 1] << endl;
            if (cClass == 1) { //fighter combat ratings
                hp = (constitution * 10) + (lvl * 5);
                ep = (intel * 10) + (lvl * 3);
                atk = (strength * 1.5) + 10;
                def = (constitution + agility) / 2;
                cout << "\nHP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;

            } else if (cClass == 2) { //psychic combat ratings
                hp = (constitution * 10) + (lvl * 5);
                ep = (intel * 10) + (lvl * 3) + 30;
                atk = intel * 1.5;
                def = (constitution + agility) / 2;
                cout << "\nHP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;

            } else if (cClass == 3) { //weapon specialist combat ratings
                hp = (constitution * 10) + (lvl * 5);
                ep = (intel * 10) + (lvl * 3);
                atk = agility * 1.5;
                def = ((constitution + agility) / 2) + 10;  
                cout << "\nHP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;

            } else if (cClass == 4) { //beast combat ratings
                hp = (constitution * 10) + (lvl * 5) + 20;
                ep = (intel * 10) + (lvl * 3);
                atk = constitution * 1.5;
                def = (constitution + agility) / 2;
                cout << "\nHP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;
                
        } break;

            /*********************
            *4. LEVEL UP CHARACTER*
            **********************/
        case 4:// Leveling up character using if/else statements
            cout << "Leveling up character..." << endl;
            for (int j = 0; j < 1; j++) { //simulate leveling up once each time option 4 is selected
                //display current stats in current level
                cout << "\n" << cName << "'s current stats at level " << lvl << ":" << endl;
                cout << "Strength: " << strength << endl;
                cout << "Constitution: " << constitution << endl;
                cout << "Agility: " << agility << endl;
                cout << "Intellect: " << intel << endl;
                cout << "\nCombat Stats at level " << lvl << ":" << endl;
                cout << "HP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;
                //base stats inc by 1 each level up
                strength += 1;
                constitution += 1;
                agility += 1;
                intel += 1;

                //display new stats after level up
                cout << "\n" << cName << "'s new stats at level " << lvl + 1 << ":" << endl;
                cout << "Strength: " << strength << endl;
                cout << "Constitution: " << constitution << endl;
                cout << "Agility: " << agility << endl;
                cout << "Intellect: " << intel << endl;
                cout << "\nCombat Stats:" << endl;
                cout << "HP: " << hp << endl;
                cout << "EP: " << ep << endl;
                cout << "ATK: " << atk << endl;
                cout << "DEF: " << def << endl;
                lvl++;
        }
            if (lvl >= MAX_LVL) {
                lvl = 10; //set level to max if exceeded
                cout << "\n" << cName << " has reached the maximum level!" << endl;
            }
            else {
            cout << cName << " is now level " << lvl << "!" << endl;
            }
            break;
            /****************
            * 5. EXIT PROGRAM*
            *****************/
        case 5: // Exit
            cout << "\nSee ya next time." << endl;
            break;
        default:
            cerr << "Invalid choice. Please try again." << endl;
            break;
    } 
    
} while (choice != 5);
return 0;
}
