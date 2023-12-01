#include <iostream>
#include "Items.h"

using namespace std;

//sets variables that were passed in at creation
Item::Item(const char* nametmp, const char* descriptiontmp) : name(nametmp), description(descriptiontmp) {}

//gets name of the item
const char* Item::getName() {
    return name;
}

//gets description of the item
const char* Item::getDescription() {
    return description;
}