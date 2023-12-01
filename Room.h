#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include "Items.h"

using namespace std;

class Room {
public:
    Room(const char* name, const char* description);
    void setExit(const char* direction, Room* neighbor);
    const char* getDescription();
    Room* getExit(const char* direction);
    const char* getName();
    void listItems();
    void setItem(Item newItem);
    Item getItem(const char* itemName);

private:
    const char* description;
    const char* name;
    Room* exits[4];
    vector<Item> roomItems;
};

#endif // ROOM_H    