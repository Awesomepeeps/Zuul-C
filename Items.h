#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
public:
    Item(const char* name, const char* description);
    const char* getName();
    const char* getDescription();

private:
    const char* name;
    const char* description;
};

#endif // ITEM_H