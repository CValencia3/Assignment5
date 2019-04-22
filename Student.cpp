#include "Student.h"

using namespace std;

Student::Student()
{
    Person();
}
Student::Student(int id, string nm, string lvl, string mjr, int adv, double gpa)
    : Person(id,nm,lvl),
      major{mjr},
      advisorID(adv),
      GPA(gpa){}
Student::~Student()
{}

void Student::Print()
{
    Person::Print();
    cout << "Major: " << major << endl;
    cout << "Advisor: " << advisorID << endl;
    cout << "GPA: " << GPA << endl;
}
