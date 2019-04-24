#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Person::Person()
{

}

Person::Person(int id, string nm, string lvl)
    :id(id), name(nm), level(lvl)
{

}

Person::~Person()
{

}

void Person::print()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}

void Person::save(ofstream &myStream)
{
    ofstream tempStream;
    tempStream.open("temp.txt");
    tempStream << "Hello\n";
    tempStream.close();
    myStream << '/t' << name << "/n"
    //          << "/n" << level << "/n";
}

bool Person::operator==(const Person& otherPerson)
{
    return (this->id == otherPerson.id);
}

bool Person::operator<=(const Person& otherPerson)
{
    return (this->id <= otherPerson.id);
}

bool Person::operator>=(const Person& otherPerson)
{
    return (this->id >= otherPerson.id);
}

bool Person::operator!=(const Person& otherPerson)
{
    return (this->id != otherPerson.id);
}

bool Person::operator>(const Person& otherPerson)
{
    return (this->id > otherPerson.id);
}

bool Person::operator<(const Person& otherPerson)
{
    return (this->id < otherPerson.id);
}
