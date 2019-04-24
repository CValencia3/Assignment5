#pragma once
#include "Person.h"
#include <iostream>
#include <string>


using namespace std;

class Student: public Person
{
public:
    Student();
    Student(int id, string name, string level, string major, int advisor, double gpa);
    ~Student();
    // void save(ofstream &myStream);

    string major;
    int advisorID;
    double GPA;

    void print();

};
