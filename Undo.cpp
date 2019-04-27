#include "GenStack.h"
#include "Undo.h"

using namespace std;

Undo::Undo()
{
    undoStack = new GenStack(5);
}

Undo::Undo(int s)
{
    undoStack = new GenStack(5);
}

Undo::~Undo()
{
    delete undoStack;
}

void Undo::push(Manips* manipulation)
{
    GenStack::push(manipulation);
}

void Undo::pop()
{
    Manips* temp = GenStack::pop();
    temp->undoOperation();
}
