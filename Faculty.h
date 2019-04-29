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
    Faculty();
    Faculty(int id, string name, string level, string department);
    ~Faculty();
    void save(ofstream &myStream);

    string department;
    DoublyLinkedList<int> advisees;

    void AddAdvisee(int id);
    void AddAdvisee(Student *s);
    void print();
    void printAdvisees(BST<Person*> *studentTree);
    void removeAdvisee(int key);

};
