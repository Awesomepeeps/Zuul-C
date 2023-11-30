#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
public:
    Item(char* &name, char* &description);
    char* getName();
    char* getDescription();

private:
    char* name;
    char* description;
};

#endif // ITEM_H