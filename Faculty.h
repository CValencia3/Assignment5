#pragma once
#include "Person.h"
#include "genDLL.h"

using namespace std;

class Faculty:public Person
{
public:
    Faculty();
    Faculty(int id, string name, string level, string department);
    ~Faculty();

    string department;
    DoublyLinkedList<int> advisees;

    void AddAvisee(int id);
    void print();

};
