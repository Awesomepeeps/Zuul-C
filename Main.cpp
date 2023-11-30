#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"

using namespace std;

void printLocation(Room* currentRoom);
Room* processCommand(char* command, Room* currentRoom);

main (void) {
    cout << "Trial 1" << endl;
    vector<Room> rooms;
    Room* currentRoom;

    char nameTemp[] = "Kitchen";
    
    char  placeTemp[] = "This is where cooking is done";

    rooms.push_back(Room("Kitchen", "This is where cooking is done", Item("Key", "A big golden key")));

    currentRoom = &rooms[0];

    cout << "Welcome to Zuul!" << endl; 
    printLocation(currentRoom);

    while (true) {
        cout << "Enter a command (type 'quit' to exit or 'help' to get a list of commands): ";
        char* command = new char(50);
        cin >> command;

        if (strcmp(command, "quit") == 0) {
            cout << "Thanks for playing!" << endl;
            break;
        } else if (strcmp(command, "look") == 0) {
            printLocation(currentRoom);
        } else {
            currentRoom = processCommand(command, currentRoom);
        }
    }
}

void printLocation(Room* currentRoom) {
    cout << "You are in the " << currentRoom->getName() << "\n" << currentRoom->getDescription() << "." << endl;
    currentRoom->listItems();
    cout << "Exits: ";
    if (currentRoom->getExit("north") != nullptr) {
        cout << "Room to the north is: " << (currentRoom->getExit("north"))->getName() << endl;
    }
    else if (currentRoom->getExit("south") != nullptr) {
        cout << "Room to the south is: " << (currentRoom->getExit("south"))->getName()<< endl;
    }
    else if (currentRoom->getExit("east") != nullptr) {
        cout << "Room to the east is: " << (currentRoom->getExit("east"))->getName() << endl;
    }
    else if (currentRoom->getExit("west") != nullptr) {
        cout << "Room to the west is: " << (currentRoom->getExit("west"))->getName() << endl;
    }
    cout << endl;
}

Room* processCommand(char* command, Room* currentRoom) {
    if (strcmp(command, "north") == 0) {
        Room* nextRoom = currentRoom->getExit("north");
        if (nextRoom != nullptr) {
            return nextRoom;
            cout << "You move north." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the north." << endl;
        }
    }
    else if (strcmp(command, "south") == 0) {
        Room* nextRoom = currentRoom->getExit("south");
        if (nextRoom != nullptr) {
            return nextRoom;
            cout << "You move south." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the south." << endl;
        }
    }
    else if (strcmp(command, "east") == 0) {
        Room* nextRoom = currentRoom->getExit("east");
        if (nextRoom != nullptr) {
            return nextRoom;
            cout << "You move east." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the east." << endl;
        }
    }
    else if (strcmp(command, "west") == 0) {
        Room* nextRoom = currentRoom->getExit("west");
        if (nextRoom != nullptr) {
            return nextRoom;
            cout << "You move west." << endl;
            printLocation(currentRoom);
        } else {
            cout << "There is no exit to the west." << endl;
        }
    }
    else if (strcmp(command, "pick") == 0) {

    }
    else if (strcmp(command, "drop") == 0) {

    }
    else if (strcmp(command, "inventory") == 0) {

    }
    else if (strcmp(command, "help") == 0) {
        cout << "Your commands are: look, north, south, east, west, pick, drop, inventory, quit" << endl;
    }
    return currentRoom;
}