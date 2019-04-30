#include "GenStack.h"
#include "Redo.h"

using namespace std;

Redo::Redo()
{
    redoStack = new GenStack(5);
}

Redo::Redo(int s)
{
    redoStack = new GenStack(s);
}

Redo::~Redo()
{
    delete redoStack;
}

void Redo::push(Manips* manipulation)
{
    GenStack::push(manipulation);
}

Manips* Redo::pop()
{
    Manips* temp = GenStack::pop();
    temp->redoOperation();
}

bool Redo::isEmpty()
{
    return redoStack->isEmpty();
}

void Redo::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}
