#include "Student.h"

using namespace std;

Student::Student()
{
    Person();
    major = "Cosmic Indifference";
    advisorID = id + 1;
    GPA = 6.66;
    isStudent = true;
}

Student::Student(int id, string nm, string lvl, string mjr, int adv, double gpa)
    : Person(id,nm,lvl),
      major{mjr},
      advisorID(adv),
      GPA(gpa)
      { isStudent = true;}

Student::~Student()
{

}

void Student::print()
{
    Person::print();
    cout << "\tMajor: " << major << endl;
    cout << "\tAdvisor: " << advisorID << endl;
    cout << "\tGPA: " << GPA << endl;
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
