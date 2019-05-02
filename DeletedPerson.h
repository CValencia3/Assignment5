#pragma once

#include <string>
#include <typeinfo>

#include "Manips.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class DeletedPerson: public Manips
{
public:
    DeletedPerson(); // constructor
    ~DeletedPerson(); // destructor
    // Create a new deletedPerson object. Takes
        // pointer to a person
        // pointer to the affected database
        // pointer to the other database
        // pointer to list of faculty ids
    DeletedPerson(Person *myP, BST<Person*>* aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs);
    // Create a new deletedPerson object. Takes
        // pointer to a person
        // pointer to the affected database
        // pointer to the other database
    DeletedPerson(Person *myP, BST<Person*>* aT, BST<Person*> *oT);
    // Creates facultyIDs by itself
    void recFacultyID(TreeNode<Person*>* node);
    void undoOperation(); // Delete
    void redoOperation();

    Person *affectedPerson;
    BST<Person*>* affectedTree; // Tree that contains the person
    BST<Person*>* otherTree; // The other tree
    DoublyLinkedList<int>* facultyIDs;
};
