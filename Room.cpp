#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room(const char* nametmp, const char* descriptiontmp, Item itemtmp) : name(nametmp), description(descriptiontmp), roomItem(itemtmp) {
    for (int i = 0; i < 4; ++i) {
        exits[i] = nullptr;
    }
}

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

const char* Room::getDescription() {
    return description;
}

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

const char* Room::getName() {
    return name;
}

void Room::listItems() {
    cout << "Items in the room: " << roomItem.getName() << " - " << roomItem.getDescription() << endl;
}