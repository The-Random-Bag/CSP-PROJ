#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
int rounds;
int blanks;
int fulls;
int waves = 1;
std::vector <int> slingshot = {};
std::vector <std::string> items = {"Water Bottle", "0", "Hand Saw", "0", "Shiny Handcuffs", "0", "Juice Box", "0", "Magnifying Glass", "0"};
std::vector <std::string> dealerItems = {"Water Bottle", "0", "Hand Saw", "0", "Shiny Handcuffs", "0", "Juice Box", "0", "Magnifying Glass", "0"};//Beer 0 Val 1
auto rng = std::default_random_engine {};
void funks() {
    if (rounds == 1) {
        blanks = 3;
        fulls = 3;
    }
    else if (rounds == 2) {
        blanks = 2;
        fulls = 4;
    }
    else if (rounds == 3) {
        blanks = 6;
        fulls = 2;
    }
    else if (rounds == 4) {
        blanks = 1;
        fulls = 3;
    }        
    else if (rounds == 5) {
        blanks = 3;
        fulls = 4;
    }
    else if (rounds == 6) {
        blanks = 1;
        fulls = 3;
    }
    else if (rounds == 7) {
        blanks = 1;
        fulls = 2;
    }
    else if (rounds == 8) {
        blanks = 3;
        fulls = 2;
    }
    else if (rounds == 0) {
        blanks = 4;
        fulls = 4;
    }
}
int translateID(int input, std::vector <std::string>& sirlonse, int type) {
    int adder;
    if (input == 0) {
        //BEER ID: 0 VL: 1
        //TURN VL INTO AN INTEGER AND BACK INTO A STRING FOR REINPUT
        int value = std::stoi(sirlonse[1]);
        value++;
        std::string thing = std::to_string(value);
        sirlonse[1] = thing;
        if (type == 0) {
            std::cout<<"YOU GOT A "<<sirlonse[0]<<"!\n";
        }
        if (type == 1) {
            std::cout<<"THE DEALER RECEIVES A "<<sirlonse[0]<<"!\n";
        }
    }
    if (input == 1) {
        //SAW ID: 2 VL: 3
        //TURN VL INTO AN INTEGER AND BACK INTO A STRING FOR REINPUT
        int value = std::stoi(sirlonse[3]);
        value++;
        std::string thing = std::to_string(value);
        sirlonse[3] = thing;
        if (type == 0) {
            std::cout<<"YOU GOT A "<<sirlonse[2]<<"!\n";
        }
        if (type == 1) {
            std::cout<<"THE DEALER RECEIVES A "<<sirlonse[2]<<"!\n";
        }
    }
    if (input == 2) {
        //HANDCUFFS ID: 4 VL: 5
        //TURN VL INTO AN INTEGER AND BACK INTO A STRING FOR REINPUT
        int value = std::stoi(sirlonse[5]);
        value++;
        std::string thing = std::to_string(value);
        sirlonse[5] = thing;
        if (type == 0) {
            std::cout<<"YOU GOT A "<<sirlonse[4]<<"!\n";
        }
        if (type == 1) {
            std::cout<<"THE DEALER RECEIVES A "<<sirlonse[4]<<"!\n";
        }
    }
    if (input == 3) {
        //CIGARETTES ID: 6 VL: 7
        //TURN VL INTO AN INTEGER AND BACK INTO A STRING FOR REINPUT
        int value = std::stoi(sirlonse[7]);
        value++;
        std::string thing = std::to_string(value);
        sirlonse[7] = thing;
        if (type == 0) {
            std::cout<<"YOU GOT A "<<sirlonse[6]<<"!\n";
        }
        if (type == 1) {
            std::cout<<"THE DEALER RECEIVES A "<<sirlonse[6]<<"!\n";
        }
    }
    if (input == 4) {
        //MAGNIFYING ID: 8 VL: 9
        //TURN VL INTO AN INTEGER AND BACK INTO A STRING FOR REINPUT
        int value = std::stoi(sirlonse[9]);
        value++;
        std::string thing = std::to_string(value);
        sirlonse[9] = thing;
        if (type == 0) {
            std::cout<<"YOU GOT A "<<sirlonse[8]<<"!\n";
        }
        if (type == 1) {
            std::cout<<"THE DEALER RECEIVES A "<<sirlonse[8]<<"!\n";
        }
    }
    return 1;
}
int subtractor(int i) {
    int val = std::stoi(dealerItems[i]);
    val--;
    std::string returner = std::to_string(val);
    dealerItems[i] = returner;
    return 1;
    
}
void addVals() {
    slingshot.clear();
    unsigned seed = time(0);
    srand(seed);
    for (int i =0; i< blanks; ++i) {
        slingshot.push_back(1); // 1 = blanks
    }
    for (int i =0;i<fulls;++i) {
        slingshot.push_back(2); // 2 = fulls
    }
    //std::cout<<"IT IS WAVE "<<waves<<".\n";
    std::cout<<"THERE ARE "<<blanks<<" BLANK(s) AND "<<fulls<<" LIVE ROUNDS.\n";
    if (waves > 1) {
        std::cout<<"YOU'VE GOT NEW ITEMS!\n";
        std::cout<<"ITEM KEY: Water Bottle = wb, Hand Saw = hs, Shiny Handcuffs = sh, Juice Box = jb, Magnifying Glass = mg\n";
        if (waves == 2) {
            for (int i = 0; i<2; i++) {
                int itemRandPlayer = rand() % 4;
                int itemRandDealer = rand() % 4;
                translateID(itemRandPlayer, items, 0);
                translateID(itemRandDealer, dealerItems, 1);
            }
        } else if (waves > 2) {
            for (int i = 0; i<4; i++) {
                int itemRandPlayer = rand() % 4;
                int itemRandDealer = rand() % 4;
                translateID(itemRandPlayer, items, 0);
                translateID(itemRandDealer, dealerItems, 1);
            }
        }
    }
    shuffle(slingshot.begin() ,slingshot.end(), rng);
}

int main()
{  
    int playerHP = 4;
    int dealerHP = 4;
    unsigned seed = time(0);
    srand(seed);
    bool dealerTurnSkipped = false;
    bool playerTurnSkipped = false;
    bool playing = true;
    bool vict = false;
    bool dead = false;
    int doubleDamage = 1;
    bool hs_db = false;
    bool pcuffed = false;
    int pcufftime = 0;
    bool dcuffed = false;
    int dcufftime = 0;
    std::string inp;
    rounds = rand() % 8;
    funks();
    int total = blanks + fulls;
    std::cout<<"Hello Player!\n";
    int pick = rand() % total;
    int dealPick = rand() % 2;
    int dealItemPick = rand() % 4;
    addVals();
    bool actionDB = false;
 /*   int remaining = 7-(blanks+fulls);
    for (int i =0; i< remaining;++i) {
        slingshot.push_back(0); // 0 = nulls
    }*/

 
    std::cout<<"(Type s for shoot and d to shoot yourself to skip a turn if it is blank)\n";
while(playing) {
    while (dealerHP > 0 || playerHP > 0) {
    if(playerTurnSkipped == false) {
    std::cout<<"\n\nYOUR TURN :D\n\n";
 while (true) {
                    std::cin >> inp;
                    if (inp == "wb" || inp == "hs" || inp == "sh" || inp == "jb" || inp == "mg" || inp == "s" || inp == "d") {
                        break;  // Valid input, exit loop
                    } else {
                        std::cout << "Invalid input. Please enter a valid command.\n";
                    }
                }
    if (inp == "wb") {
        int val = std::stoi(items[1]);
        if (val > 0) {
            if (slingshot[0] == 1) {
                std::cout<<"YOU RACKED A CRACKED RUBBER BAND.\n";
                blanks--;
            }
            if (slingshot[0] == 2) {
                std::cout<<"YOU RACKED A SOLID RUBBER BAND.\n";
                fulls--;
            }
            slingshot.erase(slingshot.begin() + 0);
            dealerTurnSkipped = true;
            val--;
            std::string returner = std::to_string(val);
            items[1] = returner;
        } else {
            std::cout<<"YOU DO NOT HAVE THIS ITEM.\n";
            dealerTurnSkipped = true;
        }
    }
    if (inp == "hs") {
        int val = std::stoi(items[3]);
        if (val > 0) {
            doubleDamage = 2;
            hs_db = true;
            dealerTurnSkipped = true;
            val--;
            std::string returner = std::to_string(val);
            items[3] = returner;
        }else {
            std::cout<<"YOU DO NOT HAVE THIS ITEM.\n";
            dealerTurnSkipped = true;
        }
    }
    if (inp == "sh") {
        int val = std::stoi(items[5]);
        if (val > 0) {
            dealerTurnSkipped = true;
            pcuffed = true;
            val--;
            std::string returner = std::to_string(val);
            items[5] = returner;
        }else {
            std::cout<<"YOU DO NOT HAVE THIS ITEM.\n";
            dealerTurnSkipped = true;
        }
    }
    if (inp == "jb") {
        int val = std::stoi(items[7]);
        if (val > 0) {
            dealerTurnSkipped = true;
            playerHP++;
            std::cout<<"YOU DRINK OUT OF THE JUICE BOX. \nYOU FEEL REJUVINATED!\n YOUR HEALTH: "<<playerHP<<".\n";
            val--;
            std::string returner = std::to_string(val);
            items[7] = returner;
        }else {
            std::cout<<"YOU DO NOT HAVE THIS ITEM.\n";
            dealerTurnSkipped = true;
        }
    }
    if (inp == "mg") {
        int val = std::stoi(items[9]);
        if (val > 0) {
            dealerTurnSkipped = true;
            if (slingshot[0] == 1) {
                std::cout<<"THE CURRENT RUBBER BAND IS BROKEN\n";
            }
            if (slingshot[0] == 2) {
                std::cout<<"THE CURRENT RUBBER BAND IS FUNCTIONAL.\n";
            }
            val--;
            std::string returner = std::to_string(val);
            items[9] = returner;
        }else {
            std::cout<<"YOU DO NOT HAVE THIS ITEM.\n";
            dealerTurnSkipped = true;
        }
    }
    if (inp == "s" && !actionDB) {
        if (slingshot[0] == 1 && !actionDB) {
            std::cout<<"YOU RAISE THE SLINGSHOT AGAINST THE DEALER AND...\nTHE SLINGSHOT DOES NOT FIRE, BLANK.\n";
            blanks--;
            slingshot.erase(slingshot.begin() + 0);
            hs_db = false;
            actionDB = true;
            doubleDamage = 1;
        } else if (slingshot[0] == 2  && !actionDB) {
            dealerHP= dealerHP-1*doubleDamage;
            std::cout<<"YOU RAISE THE SLINGSHOT AGAINST THE DEALER AND...\nTHE SLINGSHOT FIRES THE BAND WITH POWER, GENTLY FORCING THE DEALER's HEAD DOWN.\n";
            std::cout<<"DEALER's HEALTH: "<<dealerHP<<".\n";
            fulls--;
            slingshot.erase(slingshot.begin() + 0);
            hs_db = false;
            actionDB = true;
            doubleDamage = 1;
        }
    }
        if (inp == "d"  && !actionDB) {
        if (slingshot[0] == 1  && !actionDB) {
            std::cout<<"YOU PUT THE SLINGSHOT NEXT TO YOUR HEAD AND... \nTHE RUBBER BAND SNAPs BEFORE IMPACT, LEAVING YOU UNHARMED.\n";
            dealerTurnSkipped = true;
            blanks--;
            slingshot.erase(slingshot.begin() + 0);
            hs_db = false;
            actionDB = true;
            doubleDamage = 1;
        } else if (slingshot[0] == 2  && !actionDB) {
            playerHP= playerHP-1*doubleDamage;
            std::cout<<"YOU PUT THE SLINGSHOT NEXT TO YOUR HEAD AND... \nTHE SLINGSHOT FIERCELY SHOOTs THE RUBBER BAND, KNOCKING YOU DOWN.\n";
            std::cout<<"YOUR HEALTH: "<<playerHP<<".\n";
            fulls--;
            slingshot.erase(slingshot.begin() + 0);
            hs_db = false;
            actionDB = true;
            doubleDamage = 1;
        }
         
    }
}
if (!hs_db && !playerTurnSkipped) {
    doubleDamage = 1;
}
if (hs_db) {
    hs_db = false;
}
if (pcuffed) {
    pcufftime++;
    dealerTurnSkipped = true;
}
if (pcufftime == 2) {
    pcufftime = 0;
    pcuffed = false;
}
if (dealerHP < 1) {
    std::cout<<"YOU WIN :D\n";
    dealerHP = 4;
    playerHP = 4;
    vict = true;
    break;
}
if (playerHP < 1) {
    std::cout<<"YOU LOSE :d\n";
    vict = false;
    dead = true;
}
if (dead) {
    return 0;
}
    playerTurnSkipped = false;
    actionDB = false;
    total = blanks+fulls;
    if (slingshot.empty()) {
        rounds = rand() % 8;
        funks();
        std::cout<<"NEW RUBBER BANDs!\n";
        addVals();
        total = blanks + fulls;
    }
     if (dealerTurnSkipped == false) {
         std::cout<<"\n\nDEALER's TURN :d\n\n";
        if (dealPick > 1) {
            //check for item vals above 0 and then push them back to a local vector
            int iterator = 1;
            int otherator = 1;
            std::vector <int> storage = {};
            while (iterator < 9) {
                int val = std::stoi(dealerItems[iterator]);
                if (val > 0) {
                    storage.push_back(val); 
                    //KEY: EVEN NUMS (incl 0) ARE VALS 
                    //     ODD NUMS ARE IDS
                    //ODD NUM KEY:
                    // 1 = beer -  2 = hand saw - 3 = handcuff - 4 = cigarettes - 5 = magnifying glass
                    storage.push_back(otherator);
                }
                iterator = iterator + 2; 
                otherator++;
            }
            int sizest = storage.size();
            if (sizest > 0) {
                sizest /= 2; //vals+ids/2 brings total possibilities for items
                dealItemPick = rand() % sizest; 
            //dIP should be the val placements, which are even nums 
            //so dIP should be 0, 2, 4, 6 and 8 
            //to calc this: 0 = 0; 1 = 2; 2 = 4; 3 = 6; 4 = 8;
            dealItemPick = dealItemPick * 2;
            int val = storage[dealItemPick];
            int id = storage[dealItemPick + 1];
                if (id == 1) { 
                if (slingshot[0] == 1) {
                std::cout<<"THE DEALER RACKED A CRACKED RUBBER BAND.\n";
                blanks--;
                }
                if (slingshot[0] == 2) {
                std::cout<<"THE DEALER RACKED A SOLID RUBBER BAND.\n";
                fulls--;
                }
                slingshot.erase(slingshot.begin() + 0);
                playerTurnSkipped = true;
                subtractor(1); //causes a ton of errors without using functions
                } else if (id == 2) {
                    std::cout<<"THE DEALER SAWS OFF THE TIP OF THE SLINGSHOT\n";
                    doubleDamage = 2;
                    hs_db = true;
                    subtractor(3);
                    playerTurnSkipped = true;
                } else if (id == 3) {
                    std::cout<<"THE DEALER CUFFS YOU.\n";
                    dcuffed = true;
                    subtractor(5);
                    playerTurnSkipped = true;
                } else if (id == 4) {
                    dealerHP++;
                    std::cout<<"THE DEALER DRINKS JUICE.\n DEALER HP:" <<dealerHP<< "\n";
                    subtractor(7);
                    playerTurnSkipped = true;
                } else if (id == 5) {
                    std::cout<<"THE DEALER PICKS UP A MAGNIFYING GLASS AND EXAMINES THE RUBBER BANDS...\n";
                    if (slingshot[0] == 1) {
                        //make dealer shoot self next turn
                        dealPick = 1;
                    } else if (slingshot[0] == 2) {
                        dealPick = 0;
                    }
                    subtractor(9);
                    playerTurnSkipped = true;
                } else {
                    std::cout<<"ERROR OCCURED\n";
                }
            
    
            } else {
                dealPick = rand() % 2; //if there are no items, pick a new turn val 
            }





            } 
            if (dealPick == 0) { //shooting player
                if (slingshot[0] == 1 && blanks > 0) {
                    std::cout<<"THE DEALER RAISEs THE SLINGSHOT AGAINST YOU AND...\nTHE SLINGSHOT DOES NOT FIRE, A BLANK.\n";
                    blanks--;
            } else if (slingshot[0] == 2 && fulls > 0) {
            playerHP= playerHP-1*doubleDamage;
            std::cout<<"THE DEALER RAISEs THE SLINGSHOT AGAINST YOU AND...\nTHE SLINGSHOT RIPs OUT THE RUBBER BAND, KNOCKING YOU ACROSS THE ROOM.\n";
            std::cout<<"YOUR HEALTH: "<<playerHP<<".\n";
            fulls--;
            }
         } else if (dealPick == 1) { //shooting self
            if (slingshot[0] == 1 && blanks > 0) {
            std::cout<<"THE DEALER PUT THE SLINGSHOT NEXT TO ITs HEAD AND... \nTHE SLINGSHOT DOES NOT LAUNCH A RUBBER BAND, LEAVING IT UNHARMED.\n";
            playerTurnSkipped = true;
            blanks--;
        } else if (slingshot[0] == 2 && fulls > 0) {
            dealerHP= dealerHP-1*doubleDamage;
            std::cout<<"THE DEALER PUT THE SLINGSHOT NEXT TO ITs HEAD AND... \nTHE SLINGSHOT SNAPS THE BAND WITH GREAT SPEED, STRIKING THE DEALER AND SENDING IT TO THE FLOOR.\n";
            std::cout<<"DEALER's HEALTH: "<<dealerHP<<".\n";
            fulls--;
        }
        }

    if (waves == 1) {
    dealPick = rand() % 2;
    } else if (waves > 1) {
        dealPick = rand() % 5;
    }
     slingshot.erase(slingshot.begin() + 0);
    }
    dealerTurnSkipped = false;
    total = blanks+fulls;
    if (total < 0) {
    total = 0;
    }
    if (slingshot.empty()) {
        rounds = rand() % 8;
        funks();
        std::cout<<"NEW RUBBER BANDs!\n";
        addVals();
        total = blanks + fulls;
    }
if (dealerHP < 1) {
    std::cout<<"YOU WIN :D\n";
    vict = true;
    dealerHP = 4;
    playerHP = 4;
    break;
}
if (playerHP < 1) {
    std::cout<<"YOU LOSE :d\n";
    vict = false;
    dead = true;
    playing = false;
}
if (!hs_db && !dealerTurnSkipped) {
    doubleDamage = 1;
}
if (hs_db) {
    hs_db = false;
}
if (dcuffed) {
    dcufftime++;
    playerTurnSkipped = true;
}
if (dcufftime == 2) {
    dcufftime = 0;
    dcuffed = false;
}
if (dead) {
return 0;
}
}
if (vict && !dead) {
std::cout<<"DEALER: Do you wish to continue?\n (y/n)\n";
waves++;
 while (true) {
                    std::cin >> inp;
                    if (inp == "n" || inp == "y") {
                        break;  // Valid input, exit loop
                    } else {
                        std::cout << "Invalid input. Please enter a valid command.\n";
                    }
                }
if (inp == "y") {
playing = true;
funks();
addVals();
}
if (inp == "n") {
playing = false;
std::cout<< "YOUR REWARD: "<<9000*waves<<". THANK YOU FOR PLAYING.";
}
}
}
end: 
    return 0;
}


