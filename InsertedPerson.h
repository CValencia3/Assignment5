#pragma once

#include <string>

#include "Manips.h"
#include "BST.h"
#include "Person.h"

class InsertedPerson: public Manips
{
public:
    InsertedPerson();
    InsertedPerson(Person *myP, BST<Person*>* aT);
    void undoOperation(); // Delete
    void redoOperation();

private:
    Person *affectedPerson;
    BST<Person*>* affectedTree;
};

InsertedPerson::InsertedPerson()
{

}

InsertedPerson::InsertedPerson(Person *myP, BST<Person*>* aT)
    :affectedPerson(myP), affectedTree(aT)
{

}

void InsertedPerson::undoOperation() // Oposite of action done
{
    affectedTree->deleteR(affectedPerson->id);
}

void InsertedPerson::redoOperation() // Action done
{
    //affectedPerson.print();
    affectedTree->insert(affectedPerson->id, affectedPerson);
}
