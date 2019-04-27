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
    void pop();
private:
    GenStack<Manips*>* redoStack;
};
