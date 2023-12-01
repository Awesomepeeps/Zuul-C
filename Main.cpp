#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"

using namespace std;

void printLocation(Room* currentRoom);
Room* processCommand(char* command, Room* currentRoom, vector<Item> &inventory, bool winCondition);

main (void) {
    //variables that store all of the rooms, items, current locations, and a win condition
    vector<Room> rooms;
    vector<Item> inventory;
    Room* currentRoom;
    bool winCondition = false;

    //creating rooms
    rooms.push_back(Room("Parking Garage", "This is where all of the cars are")); //0
    rooms.push_back(Room("Entrance", "Entrance to the shopping mall")); //1
    rooms.push_back(Room("Macy", "This is a super popular shop")); //2
    rooms.push_back(Room("JC Penny", "It is super crowed here, best not spend too long here")); //3
    rooms.push_back(Room("Kohl's", "There is almost no one around")); //4
    rooms.push_back(Room("Escalator/", "This escalator only goes up")); //5
    rooms.push_back(Room("Escalator|", "This escalator only goes down")); //6
    rooms.push_back(Room("Gucci", "You really want to get clothes from here, but you dont have the money")); //7
    rooms.push_back(Room("Elevator", "Coneccted to all floors and the only way to get to the food court")); //8
    rooms.push_back(Room("Louis Vuitton", "Super expensive shop, but you don't want to shop here")); //9
    rooms.push_back(Room("ToysRus", "Best shop for toys and other essentials for kids")); //10
    rooms.push_back(Room("Cinnabon", "The best restaurant in the whole wide world")); //11
    rooms.push_back(Room("Taco Bell", "Used to be good, now its over prices")); //12
    rooms.push_back(Room("Subway", "Best healthy junk food")); //13
    rooms.push_back(Room("Restroom", "Wash your hands before you leave please")); //14

    //adding item to inventory
    inventory.push_back(Item("key", "A key to turn on your car"));

    //setting items in rooms
    rooms[0].setItem(Item("Car", "This is how you leave the shopping mall"));
    rooms[2].setItem(Item("Shopping Bag", "This is where you can put all the stuff you want to buy"));
    rooms[7].setItem(Item("Clothes", "The clothes you want are here, but how will you afford them?"));
    rooms[14].setItem(Item("Credit Card", "I wonder who left this here..."));
    rooms[11].setItem(Item("Snack", "A snack from the very best restaurant in the world, who can say no!"));

    //setting exits to rooms
    rooms[0].setExit("south", &rooms[1]);
    rooms[1].setExit("north", &rooms[0]);
    rooms[1].setExit("south", &rooms[8]);
    rooms[1].setExit("east", &rooms[4]);
    rooms[1].setExit("west", &rooms[2]);
    rooms[2].setExit("east", &rooms[1]);
    rooms[2].setExit("west", &rooms[3]);
    rooms[3].setExit("east", &rooms[2]);
    rooms[3].setExit("south", &rooms[5]);
    rooms[4].setExit("east", &rooms[10]);
    rooms[4].setExit("west", &rooms[1]);
    rooms[5].setExit("north", &rooms[3]);
    rooms[5].setExit("south", &rooms[7]);
    rooms[6].setExit("north", &rooms[10]);
    rooms[6].setExit("south", &rooms[9]);
    rooms[7].setExit("north", &rooms[5]);
    rooms[7].setExit("east", &rooms[8]);
    rooms[8].setExit("north", &rooms[1]);
    rooms[8].setExit("east", &rooms[9]);
    rooms[8].setExit("south", &rooms[12]);
    rooms[8].setExit("west", &rooms[7]);
    rooms[9].setExit("north", &rooms[6]);
    rooms[9].setExit("west", &rooms[8]);
    rooms[10].setExit("south", &rooms[6]);
    rooms[10].setExit("west", &rooms[4]);
    rooms[11].setExit("east", &rooms[12]);
    rooms[12].setExit("north", &rooms[8]);
    rooms[12].setExit("east", &rooms[13]);
    rooms[12].setExit("south", &rooms[14]);
    rooms[12].setExit("west", &rooms[11]);
    rooms[13].setExit("west", &rooms[12]);
    rooms[14].setExit("north", &rooms[12]);

    //setting current room
    currentRoom = &rooms[0];

    cout << "Welcome to Zuul!" << endl; 
    cout << "You are in the shopping mall of your dreams! What will you do here?" << endl; 

    //loop until win or user quits
    while (true) {
        printLocation(currentRoom);
        cout << "Enter a command (type 'quit' to exit or 'help' to get a list of commands): ";
        //a variable to store input from the user
        char* command = new char(50);
        cin >> command;

        if (strcmp(command, "quit") == 0) { //if user wants to quit
            cout << "Thanks for playing! Next time, bring more money!" << endl;
            break;
        } else if (strcmp(command, "look") == 0) { //if user wants to know current location
            printLocation(currentRoom);
        } else { //everything else is in the prosess commads function
            currentRoom = processCommand(command, currentRoom, inventory, winCondition);
        }

        if (winCondition == true) { // if the condition is true end game
            cout << "Congradulations! You have beat the game!" << endl;
            cout << "Using someone else's credit card, you bough the clothes you wanted." << endl;
            cout << "At least you bought your own snack... and didn't missplace your keys." << endl;
            cout << "Shame on you. Who knows what you do at home. Maybe you write programs that don't compile." << endl;
            break;
        }
    }
    return 0;
}

//prints the location of the user
void printLocation(Room* currentRoom) {
    cout << "You are in the " << currentRoom->getName() << "\n" << currentRoom->getDescription() << endl;
    currentRoom->listItems();
    
    //prints out all of the exits in the room
    cout << "Exits: " << endl;
    if (currentRoom->getExit("north") != nullptr) {
        cout << "Room to the north is: " << (currentRoom->getExit("north"))->getName() << endl;
    }
    if (currentRoom->getExit("south") != nullptr) {
        cout << "Room to the south is: " << (currentRoom->getExit("south"))->getName()<< endl;
    }
    if (currentRoom->getExit("east") != nullptr) {
        cout << "Room to the east is: " << (currentRoom->getExit("east"))->getName() << endl;
    }
    if (currentRoom->getExit("west") != nullptr) {
        cout << "Room to the west is: " << (currentRoom->getExit("west"))->getName() << endl;
    }
    cout << endl;
}

//computes the rest of the commands. It returns a room* so if user want to move to a new room and it exists then current room can be updated
Room* processCommand(char* command, Room* currentRoom, vector<Item> &inventory, bool winCondition) {
    if (strcmp(command, "north") == 0) { //if command was north
        Room* nextRoom = currentRoom->getExit("north");
        if (nextRoom != nullptr) { //checks room to the south is not null
            return nextRoom;
            cout << "You move north." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the north." << endl;
        }
    }
    else if (strcmp(command, "south") == 0) { //if command was south
        Room* nextRoom = currentRoom->getExit("south");
        if (nextRoom != nullptr) { //checks room to the south is not null
            return nextRoom;
            cout << "You move south." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the south." << endl;
        }
    }
    else if (strcmp(command, "east") == 0) { //if command was east
        Room* nextRoom = currentRoom->getExit("east");
        if (nextRoom != nullptr) { //checks room to the east is not null
            return nextRoom;
            cout << "You move east." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the east." << endl;
        }
    }
    else if (strcmp(command, "west") == 0) { //if command was west
        Room* nextRoom = currentRoom->getExit("west");
        if (nextRoom != nullptr) { //checks room to the west is not null
            return nextRoom;
            cout << "You move west." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the west." << endl;
         }
    }
    else if (strcmp(command, "pick") == 0) { //if command was pick
        //variable to store which item to be picked
        char* itemPick = new char(20);
        cout << "What is the name of the item that you want to pick?" << endl;
        cin >> itemPick;

        //seperate conditions for clothes and car
        if (strcmp(itemPick, "clothes") == 0) { //for clothes needs shopping bag and credit card
            bool hasBag = false;
            bool hasCard = false;
            for (Item x : inventory) { //goes through inventory
                if (strcmp(x.getName(), "creditCard") == 0) {
                    hasCard = true;
                }
                else if (strcmp(x.getName(), "shoppingBag") == 0) {
                    hasBag = true;
                }
            }
            if (hasCard == true && hasBag == true) {
                inventory.push_back(currentRoom->getItem(itemPick));
            }
            else {
                hasCard = false;
                hasBag = false;
            }
        }
        else if (strcmp(itemPick, "car") == 0) { //needs clothes, snack, and keys for for car and to win
            cout << "car" << endl;
            bool hasSnack = false;
            bool hasClothes = false;
            bool hasKey = false;
            for (Item x : inventory) { //goes through inventory
                if (strcmp(x.getName(), "snack") == 0) {
                    hasSnack = true;
                }
                if (strcmp(x.getName(), "clothes") == 0) {
                    hasClothes = true;
                }
                if (strcmp(x.getName(), "key") == 0) {
                    hasKey == true;
                }
            }
            if (hasClothes == true && hasSnack == true && hasKey == true) {
                winCondition = true;
            }
            else {
                hasKey = false;
                hasClothes = false;
                hasSnack = false;
            }
        }
        else { //if not car or clothes, do a normal pushback
            inventory.push_back(currentRoom->getItem(itemPick));
        }
    }
    else if (strcmp(command, "drop") == 0) { //if command was drop
        char* itemDrop = new char(20);
        cout << "What is the name of the item that you want to pick?" << endl;
        cin >> itemDrop;
        int index = 0;
        for (Item x : inventory) { //goes through inventory looking for item to drop
            if (strcmp(x.getName(), itemDrop) == 0) {
                inventory.erase(inventory.begin()+index); //remove from inventory
                currentRoom->setItem(x); //adds item to current room
            }
            index++;
        }
    }
    else if (strcmp(command, "inventory") == 0) { //if command is inventory
        cout << "Items in your inventory: " << endl;
        for (Item x : inventory) { //goes through and prints everything out
            cout << x.getName() << " - " << x.getDescription() << endl;
        }
    }
    else if (strcmp(command, "help") == 0) { //if command is help prints out all possible commands
        cout << "Your commands are: look, north, south, east, west, pick, drop, inventory, quit" << endl;
    }
    return currentRoom;
}