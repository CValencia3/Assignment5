#include "Faculty.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Faculty::Faculty()
{
    // Person();
}
Faculty::Faculty(int id, string nm, string lvl, string dept)
    : Person(id,nm,lvl),
      department(dept){}
Faculty::~Faculty()
{

}

void Faculty::AddAvisee(int id)
{
    advisees.insertFront(id);
}

void Faculty::print()
{
    Person::print();
    cout << "Department: " << department << endl;
    cout << "Advisees: " << endl;
    advisees.printList();
}

void Faculty::save(ofstream &myStream)
{
    // Person::save(myStream);
    myStream << id << "\n"
             << '\t' << name << "\n"
             << '\t' << level << "\n";

    myStream << '\t' << department << '\n';

    for (int i = 0; i < advisees.getSize(); ++i)
    {
        myStream << '\t' << 'k' << '\n';
    }
}
