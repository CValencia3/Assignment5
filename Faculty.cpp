#include "Faculty.h"

using namespace std;

Faculty::Faculty()
{
    Person();
    level = "Associate Inky Cloud of Shadows";
    department = "Sentient Darkness";
    isStudent = false;
}
Faculty::Faculty(DoublyLinkedList<int>* IDs)
{
    Person();
    level = "Associate Inky Cloud of Shadows";
    department = "Sentient Darkness";
    isStudent = false;
    IDs->insertFront(id);
}
Faculty::Faculty(int id, string nm, string lvl, string dept, DoublyLinkedList<int>* IDs)
    : Person(id,nm,lvl),
      department(dept)
    {
        isStudent = false;
        IDs->insertFront(id);
    }
Faculty::Faculty(int id, string nm, string lvl, string dept)
    : Person(id,nm,lvl),
      department(dept)
    {
        isStudent = false;
    }
Faculty::~Faculty()
{

}

void Faculty::AddAdvisee(int id)
{
    if(advisees.find(id)==-1)
        advisees.insertFront(id);
}

void Faculty::AddAdvisee(Student *s)
{
    if(advisees.find(id)==-1)
    {
        advisees.insertFront(s->id);
        s->advisorID = id;
    }
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
    Person::save(myStream);
    myStream << department << endl;
}

void Faculty::removeAdvisee(int key)
{
    advisees.remove(key);
}
