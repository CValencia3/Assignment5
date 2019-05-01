#pragma once
#include "Person.h"
#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student: public Person
{
public:
    Student();
    Student(int id, string name, string level, string major, int advisor, double gpa);
    ~Student();
    void save(ofstream &myStream);

    string major;
    int advisorID;
    double GPA;

    void print();
    void printAdvisor(BST<Person*>* facultyTree);
};
