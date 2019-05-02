#pragma once

#include <iostream>
#include "GenStack.h"
#include "Manips.h"

// This is just a wrapper class for a genstack in order to make it easier to use
// it as an undo stack

using namespace std;

class Undo : GenStack <Manips*>
{
public:
    Undo();
    Undo(int size);
    ~Undo();
    void push(Manips* manipulation);
    Manips* pop();
    bool isEmpty();

    GenStack<Manips*>* undoStack;
};
