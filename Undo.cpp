#include "GenStack.h"
#include "Undo.h"
#include "InsertedPerson.h"
#include "DeletedPerson.h"
#include <typeinfo>


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
    //delete undoStack;
}

void Undo::push(Manips* manipulation)
{
    undoStack->push(manipulation);
}

Manips* Undo::pop()
{
    return undoStack->pop();
}

bool Undo::isEmpty()
{
    return undoStack->isEmpty();
}
