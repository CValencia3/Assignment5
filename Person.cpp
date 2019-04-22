#include "Person.h"

using namespace std;

Person::Person()
{

}
Person::Person(int id, string nm, string lvl)
    : id(id),
      name(nm),
      level(lvl){}
Person::~Person()
{}

void Person::Print()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
}
