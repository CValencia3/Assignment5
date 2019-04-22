#pragma once
#include <iostream>

using namespace std;

class Person
{
public:
    Person();
    Person(int id, string name, string level);
    ~Person();

    int id;
    string name;
    string level;

    void Print();
};
