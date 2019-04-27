#include "GenStack.h"
#include "Redo.h"

using namespace std;

Redo::Redo()
{
    redoStack = new GenStack(5);
}

Redo::Redo(int s)
{
    redoStack = new GenStack(5);
}

Redo::~Redo()
{
    delete redoStack;
}

void Redo::push(Manips* manipulation)
{
    GenStack::push(manipulation);
}

void Redo::pop()
{
    Manips* temp = GenStack::pop();
    temp->redoOperation();
}
