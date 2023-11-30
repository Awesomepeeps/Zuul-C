#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include "Items.h"

using namespace std;

class Room {
public:
    Room(char* &name, char* description, Item& item);
    void setExit(char* &direction, Room* neighbor);
    char* getDescription();
    Room* getExit(char* &direction);
    char* getName();
    void listItems();

private:
    char* description;
    char* name;
    Room* exits[4];
    Item roomItem;
};

#endif // ROOM_H    