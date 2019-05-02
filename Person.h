#pragma once
#include <iostream>
#include <fstream>
#include "genDLL.h"

using namespace std;

class Person
{
public:
    Person(); // Constructor
    Person(int id, string name, string level); // Constructor
    ~Person();
    // Serialize
    virtual void save(ofstream &myStream);

    int id;
    string name;
    string level;
    static const string* names;
    bool isStudent;

    virtual void print();

    // OVERLOADED OPERATORS //
    // These work fine, but we thought it would be more efficient to handle with an int key
    // instead. However, with very little modification, these operators could be used
    // instead of the normal int operators
    bool operator==(const Person& otherNum);
    bool operator<=(const Person& otherNum);
    bool operator>=(const Person& otherNum);
    bool operator!=(const Person& otherNum);
    bool operator>(const Person& otherNum);
    bool operator<(const Person& otherNum);

};
