#pragma once

#include <string>

#include "Person.h"
#include "BST.h"
#include "genDLL.h"
#include "Faculty.h"
#include "Student.h"

class Manips
{
public:
    Manips();
    Manips(Person *myP, Person *oP, BST<Person*> *aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs, int t); // t = type
                                                                                                         // 1 = insert
                                                                                                         // 2 = delete
                                                                                                         // 3 = remove advisor
                                                                                                         // 4 = add advisor

    Manips(Person *myP, BST<Person*> *aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs, int t);

    void undoOperation();
    void redoOperation();

    Person *affectedPerson;
    Person *otherPerson;
    BST<Person*>* affectedTree; // Tree that contains the person
    BST<Person*>* otherTree; // The other tree
    DoublyLinkedList<int>* facultyIDs;
    bool isStudent;
    int type;
private:
};
