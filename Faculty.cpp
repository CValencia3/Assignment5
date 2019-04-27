#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
    Person();
    level = "Associate Inky Cloud of Shadows";
    department = "Sentient Darkness";
}
Faculty::Faculty(int id, string nm, string lvl, string dept)
    : Person(id,nm,lvl),
      department(dept){}
Faculty::~Faculty()
{

}

void Faculty::AddAdvisee(int id)
{
    advisees.insertFront(id);
}

void Faculty::AddAdvisee(Student *s)
{
    advisees.insertFront(s->id);
    s->advisorID = id;
}

void Faculty::print()
{
    Person::print();
    cout << "Department: " << department << endl;
    cout << "Advisees: " << endl;
    advisees.printList();
}

void Faculty::printAdvisees(BST<Person*> *sT)
{
    ListNode<int> *current = advisees.getHead();
    while (current!=NULL)
    {
        sT->searchPrint(current->data);
        current = current->next;
    }
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
