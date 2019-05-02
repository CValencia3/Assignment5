#pragma once

#include "Person.h"
#include "genDLL.h"
#include "Student.h"
#include "BST.h"
#include <iostream>
#include <fstream>

using namespace std;

class Faculty:public Person
{
public:
    Faculty(); // constructor
    Faculty(DoublyLinkedList<int>* IDs); // overloaded constructor
    Faculty(int id, string name, string level, string department, DoublyLinkedList<int>* IDs);
    Faculty(int id, string name, string level, string department);
    ~Faculty();
    // Saves the faculty information
    void save(ofstream &myStream);

    string department;
    DoublyLinkedList<int> advisees;

    // gives the option to add either way
    void AddAdvisee(int id);
    void AddAdvisee(Student *s);

    void print();
    void printAdvisees(BST<Person*> *studentTree);
    void removeAdvisee(int key);

};
