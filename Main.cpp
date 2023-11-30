#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

void printLocation(void);

main (void) {
    cout << "Trial 1" << endl;
    vector<Room> rooms;
    Room* currentRoom;

    //rooms.push_back(Room("Kitchen", Item("Key", "A big golden key")));

    currentRoom = &rooms[0];

    cout << "Welcome to Zuul!" << endl; 
    //printLocation(currentRoom);

    while (true) {
        cout << "Enter a command (type 'quit' to exit): ";
        char* command = new char(50);
        cin >> command;

        if (command == "quit") {
            cout << "Thanks for playing!" << endl;
            break;
        } else if (command == "look") {
            //printLocation();
        } else {
            //need a command processer here, smt like
            //processCommand(command);
        }
    }
}