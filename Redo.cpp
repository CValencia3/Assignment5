#include "GenStack.h"
#include "Redo.h"
#include "InsertedPerson.h"
#include "DeletedPerson.h"
#include <typeinfo>

using namespace std;

// This is just a wrapper class for a genstack in order to make it easier to use
// it as an undo stack

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

}

void Redo::push(Manips* manipulation)
{
    redoStack->push(manipulation);
}

Manips* Redo::pop()
{
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
