#include "Person.h"

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
