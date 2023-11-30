#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include "Items.h"

using namespace std;

class Room {
public:
    Room(const char* name, const char* description, Item item);
    void setExit(const char* direction, Room* neighbor);
    const char* getDescription();
    Room* getExit(const char* direction);
    const char* getName();
    void listItems();

private:
    const char* description;
    const char* name;
    Room* exits[4];
    Item roomItem;
};

#endif // ROOM_H    