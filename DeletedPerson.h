#pragma once

#include <string>

#include "Manips.h"
#include "BST.h"
#include "Person.h"

class DeletedPerson: public Manips
{
public:
    DeletedPerson();
    DeletedPerson(Person myP, BST<Person>* aT);
    void undoOperation(); // Delete
    void redoOperation();

private:
    Person affectedPerson;
    BST<Person>* affectedTree;
};

DeletedPerson::DeletedPerson()
{

}

DeletedPerson::DeletedPerson(Person myP, BST<Person>* aT)
    :affectedPerson(myP), affectedTree(aT)
{

}

void DeletedPerson::undoOperation() // Oposite of action done
{
    affectedTree->insert(affectedPerson.id, affectedPerson);
}

void DeletedPerson::redoOperation() // Action done
{
    affectedTree->deleteR(affectedPerson.id);
}
