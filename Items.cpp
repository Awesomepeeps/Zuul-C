#include <iostream>
#include "Items.h"

using namespace std;

Item::Item(char* &name, char* &description) : name(name), description(description) {}

char* Item::getName() {
    return name;
}

char* Item::getDescription() {
    return description;
}