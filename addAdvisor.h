#pragma once

#include <string>
#include <typeinfo>

#include "Manips.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class addAdvisor: public Manips
{
public:
    // Default constructor
    addAdvisor();
    // Overloaded constructor that takes in:
        // pointer to a person
        // id for a faculty
        // pointer to the student database
        // pointer to the faculty database
        // pointer to list of faculty ids
    addAdvisor(Person *aSt, int facultyID, BST<Person*>* sT, BST<Person*> *fT, DoublyLinkedList<int>* IDs);
    // Oposite the action, so set advisor to old
    void undoOperation();
    // Do the action over again, so set advisor to the new one again
    void redoOperation();

    // A pointer to the student being affected
    Student* actualStudent;
    // A pointer to the student tree
    BST<Person*>* studentTree;
    // A pointer to the faculty tree
    BST<Person*>* facultyTree;
    // ID of the faculty being affected
    int facultyID;
    // Id of the original faculty
    int originalFaculty;
    // A pointer to the list of faculty IDs
    DoublyLinkedList<int>* facultyIDs;
};
