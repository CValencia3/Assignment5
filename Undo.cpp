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
    // InsertedPerson* myP = dynamic_cast<InsertedPerson*> (manipulation);
    //
    // cout << "directy inside: " << myP << endl; // Already broken here
    // cout << "directy inside: " << myP->affectedPerson->id << endl; // Already broken here
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
