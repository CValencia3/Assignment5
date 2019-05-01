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
    addAdvisor();
    addAdvisor(Person *aSt, int facultyID, BST<Person*>* sT, BST<Person*> *fT, DoublyLinkedList<int>* IDs);
    void undoOperation(); // Change Advisor
    void redoOperation(); // Change back

// private:
    Student* actualStudent;
    BST<Person*>* studentTree; // Tree that contains the person
    BST<Person*>* facultyTree; // Tree that contains the person
    int facultyID;
    int originalFaculty;
    DoublyLinkedList<int>* facultyIDs;
};
