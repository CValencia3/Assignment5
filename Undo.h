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
    void pop();
private:
    GenStack<Manips*>* undoStack;
};
