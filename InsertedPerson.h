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
    InsertedPerson(); // constructor
    ~InsertedPerson(); // destructor
    // Create a new InsertedPerson object. Takes
        // pointer to a person
        // pointer to the affected database
        // pointer to the other database
        // pointer to list of faculty ids
    InsertedPerson(Person *myP, BST<Person*>* aT, BST<Person*>* oT, DoublyLinkedList<int>* IDs);
    // Create a new InsertedPerson object. Takes
        // pointer to a person
        // pointer to the affected database
        // pointer to the other database
    InsertedPerson(Person *myP, BST<Person*>* aT, BST<Person*> *oT);
    // Gather faculty ids
    void recFacultyID(TreeNode<Person*>* node);
    void undoOperation(); // Delete the person
    void redoOperation(); // stick the person back in

    Person *affectedPerson;
    BST<Person*>* affectedTree; // Tree that contains the person
    BST<Person*>* otherTree; // The other tree
    DoublyLinkedList<int>* facultyIDs;
};
