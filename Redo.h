#pragma once

#include <iostream>
#include "GenStack.h"
#include "Manips.h"

using namespace std;

class Redo : GenStack <Manips*>
{
public:
    Redo();
    Redo(int size);
    ~Redo();
    void push(Manips* manipulation);
    Manips* pop();
    bool isEmpty();
    void clear();
private:
    GenStack<Manips*>* redoStack;
};
