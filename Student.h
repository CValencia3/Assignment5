#pragma once
#include "Person.h"

using namespace std;

class Student: public Person
{
public:
    Student();
    Student(int id, string name, string level, string major, int advisor, double gpa);
    ~Student();

    string major;
    int advisorID;
    double GPA;

    void Print();

};
