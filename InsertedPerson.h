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
    InsertedPerson(Person *myP, BST<Person*>* aT, BST<Person*>* oT);
    void undoOperation(); // Delete
    void redoOperation();

private:
    Person *affectedPerson;
    BST<Person*>* affectedTree; // Treee that contains the person
    BST<Person*>* otherTree; // The other tree
};

InsertedPerson::InsertedPerson()
{

}

InsertedPerson::InsertedPerson(Person *myP, BST<Person*> *aT, BST<Person*> *oT)
    :affectedPerson(myP), affectedTree(aT), otherTree(oT)
{

}

void InsertedPerson::undoOperation() // Oposite of action done
{
    int k = 0;

    try
    {
        cout << k++ << endl;
        Student* tempStud = dynamic_cast<Student*> (affectedPerson);

        cout << k++ << endl;

        Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));

        cout << k++ << endl;

        cout << tempFac << endl;

        // tempFac->print();

        tempFac->removeAdvisee(tempStud->id);

        cout << k++ << endl;
    }
    catch(const bad_cast)
    {
        cout << "Undoing Faculty" << endl;
    }
    affectedTree->deleteR(affectedPerson->id);
    cout << k++ << endl;
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
