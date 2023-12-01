#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

//sets variables that were passed in at creation
Room::Room(const char* nametmp, const char* descriptiontmp) : name(nametmp), description(descriptiontmp) {
    //sets all exits to null
    for (int i = 0; i < 4; ++i) {
        exits[i] = nullptr;
    }
}

//function to set the exits of a room
void Room::setExit(const char* direction, Room* neighbor) {
    if (strcmp(direction, "north") == 0) {
        exits[0] = neighbor;
    }
    else if (strcmp(direction, "south") == 0) {
        exits[1] = neighbor;
    }
    else if (strcmp(direction, "east") == 0) {
        exits[2] = neighbor;
    }
    else if (strcmp(direction, "west") == 0) {
        exits[3] = neighbor;
    }
}

//gets description of the room
const char* Room::getDescription() {
    return description;
}

//gets the exit of the room
Room* Room::getExit(const char* direction) {
    if (strcmp(direction, "north") == 0) {
        return exits[0];
    }
    else if (strcmp(direction, "south") == 0) {
        return exits[1];
    }
    else if (strcmp(direction, "east") == 0) {
        return exits[2];
    }
    else if (strcmp(direction, "west") == 0) {
        return exits[3];
    }
    return nullptr;
}

//gets the name of the room
const char* Room::getName() {
    return name;
}

//lists all items in the room
void Room::listItems() {
    cout << "Items in the room: " << endl;
    for (Item x : roomItems) {
        cout << x.getName() << ": " << x.getDescription() << endl;
    }
}

//adds an item to the room
void Room::setItem(Item newItem) {
    roomItems.push_back(newItem);
}

//removes a item from the room and returns it
Item Room::getItem(const char* itemName) {
    int index = 0;
    for (Item x : roomItems) {
        if (strcmp(x.getName(), itemName) == 0) {
            roomItems.erase(roomItems.begin()+index);
            return x;
        }
        index++;
    }
    return Item("", "");
}