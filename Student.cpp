#include "Student.h"

using namespace std;

Student::Student()
{
    Person();
    major = "Cosmic Indifference";
    advisorID = id + 1;
    GPA = 6.66;
    isStudent = true;
    cout << "this constructor" << endl;
}

Student::Student(int id, string nm, string lvl, string mjr, int adv, double gpa)
    : Person(id,nm,lvl),
      major{mjr},
      advisorID(adv),
      GPA(gpa)
      { isStudent = true; cout << "that constructor: " << nm << id << endl;}

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

void Student::printAdvisor(BST<Person*>* fT)
{
    fT->searchPrint(advisorID);
}

void Student::save(ofstream &myStream)
{
    Person::save(myStream);
    myStream << major << '|'
             << advisorID << '|'
             << GPA << '\n';

}
