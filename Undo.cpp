#include "GenStack.h"
#include "Undo.h"

using namespace std;

Undo::Undo()
{
    undoStack = new GenStack(5);
}

Undo::Undo(int s)
{
    undoStack = new GenStack(s);
}

Undo::~Undo()
{
    delete undoStack;
}

void Undo::push(Manips* manipulation)
{
    GenStack::push(manipulation);
}

Manips* Undo::pop()
{
    Manips* temp = GenStack::pop();
    temp->undoOperation();
}

bool Undo::isEmpty()
{
    return undoStack->isEmpty();
}
