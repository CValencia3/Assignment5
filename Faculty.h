#pragma once
#include "Person.h"
#include "genDLL.h"
#include <iostream>
#include <string>
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

    void AddAvisee(int id);
    void print();

};
