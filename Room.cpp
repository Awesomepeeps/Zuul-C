#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room(char* &name, char* description, Item& item) : name(name), description(description), roomItem(item) {
    for (int i = 0; i < 4; ++i) {
        exits[i] = nullptr;
    }
}

void Room::setExit(char* &direction, Room* neighbor) {
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

char* Room::getDescription() {
    return description;
}

Room* Room::getExit(char* &direction) {
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

char* Room::getName() {
    return name;
}

void Room::listItems() {
    cout << "Items in the room: " << roomItem.getName() << " - " << roomItem.getDescription() << endl;
}