#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;

Student::Student()
{
    // Person();
}

Student::Student(int id, string nm, string lvl, string mjr, int adv, double gpa)
    : Person(id,nm,lvl),
      major{mjr},
      advisorID(adv),
      GPA(gpa)
      {}

Student::~Student()
{

}

void Student::print()
{
    Person::print();
    cout << "Major: " << major << endl;
    cout << "Advisor: " << advisorID << endl;
    cout << "GPA: " << GPA << endl;
}

void Student::save(ofstream &myStream)
{
    Person::save(myStream);
    myStream << '\t' << major << '\n'
             << '\t' << advisorID << '\n'
             << '\t' << GPA << '\n';

}
