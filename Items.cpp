#include <iostream>
#include "Items.h"

using namespace std;

Item::Item(const char* nametmp, const char* descriptiontmp) : name(nametmp), description(descriptiontmp) {}

const char* Item::getName() {
    return name;
}

const char* Item::getDescription() {
    return description;
}