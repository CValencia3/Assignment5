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
    delete undoStack;
}

void Undo::push(Manips* manipulation)
{
    InsertedPerson* myP = dynamic_cast<InsertedPerson*> (manipulation);

    cout << "directy inside: " << myP << endl; // Already broken here
    cout << "directy inside: " << myP->affectedPerson->id << endl; // Already broken here
    undoStack->push(myP);
}

Manips* Undo::pop()
{


    cout << "blank" << endl;

    Manips* temp = undoStack->pop(); // Gives the wrong person

    InsertedPerson* newTemp = dynamic_cast<InsertedPerson*> (temp); // Why the fuck doesn't this work
    cout << "blank" << endl;


    // cout << newTemp << endl;
    cout << "blank" << endl;

    cout << temp << endl;

    cout << "k" << endl;
    return temp;
}

bool Undo::isEmpty()
{
    return undoStack->isEmpty();
}
