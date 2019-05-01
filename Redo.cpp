#include "GenStack.h"
#include "Redo.h"
#include "InsertedPerson.h"
#include "DeletedPerson.h"
#include <typeinfo>

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
    // delete redoStack;
}

void Redo::push(Manips* manipulation)
{
    redoStack->push(manipulation);
}

Manips* Redo::pop()
{
    // Manips* temp = redoStack->pop();
    // temp->redoOperation();
    return redoStack->pop();
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
