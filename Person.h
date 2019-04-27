#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Person
{
public:
    Person();
    Person(int id, string name, string level);
    ~Person();
    virtual void save(ofstream &myStream);

    int id;
    string name;
    string level;
    static const string* names;

    virtual void print();

    bool operator==(const Person& otherNum);
    bool operator<=(const Person& otherNum);
    bool operator>=(const Person& otherNum);
    bool operator!=(const Person& otherNum);
    bool operator>(const Person& otherNum);
    bool operator<(const Person& otherNum);

};
