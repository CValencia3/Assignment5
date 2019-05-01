#pragma once

#include <string>
#include <typeinfo>

#include "Manips.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class removeAdvisor: public Manips
{
public:
    removeAdvisor();
    removeAdvisor(Person *aFac, int studentID, BST<Person*>* fT, BST<Person*> *sT, DoublyLinkedList<int>* IDs);
    void undoOperation(); // Change Advisor
    void redoOperation(); // Change back

// private:
    Faculty* actualFaculty;
    BST<Person*>* studentTree; // Tree that contains the person
    BST<Person*>* facultyTree; // Tree that contains the person
    int studentID;
    DoublyLinkedList<int>* facultyIDs;
};
