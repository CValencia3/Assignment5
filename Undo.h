#pragma once

#include <iostream>
#include "GenStack.h"
#include "Manips.h"

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
private:
    GenStack<Manips*>* undoStack;
};
