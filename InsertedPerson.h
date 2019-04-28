#pragma once

#include <string>
#include <typeinfo>

#include "Manips.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

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

InsertedPerson::InsertedPerson(Person *myP, BST<Person*> *aT)
    :affectedPerson(myP), affectedTree(aT)
{

}

void InsertedPerson::undoOperation() // Oposite of action done
{
    try
    {
        dynamic_cast<Student&> (*affectedPerson);
        cout << "Undoing Student" << endl;
    }
    catch(const bad_cast)
    {
        cout << "Undoing Faculty" << endl;
    }
    affectedTree->deleteR(affectedPerson->id);
}

void InsertedPerson::redoOperation() // Action done
{
    try
    {
        dynamic_cast<Student&> (*affectedPerson);
        cout << "Redoing Student" << endl;
    }
    catch(const bad_cast)
    {
        cout << "Redoing Faculty" << endl;
    }

    // Faculty& dynamic_cast<Faculty&> (*affectedPerson);

    affectedTree->insert(affectedPerson->id, affectedPerson);
}
