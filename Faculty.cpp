#include "Faculty.h"

using namespace std;

// Testing purposes
Faculty::Faculty()
{
    Person();
    level = "Associate Inky Cloud of Shadows";
    department = "Sentient Darkness";
    isStudent = false;
}

// Testing purposes
Faculty::Faculty(DoublyLinkedList<int>* IDs)
{
    Person();
    level = "Associate Inky Cloud of Shadows";
    department = "Sentient Darkness";
    isStudent = false;
    IDs->insertFront(id);
}

// Main constructor
Faculty::Faculty(int id, string nm, string lvl, string dept, DoublyLinkedList<int>* IDs)
    : Person(id,nm,lvl),
      department(dept)
    {
        isStudent = false;
        IDs->insertFront(id);
    }

// Secondary constructor
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
    if(advisees.find(id) == -1)
    {
        advisees.insertFront(s->id);
        s->advisorID = id;
    }
}

// Print information
void Faculty::print()
{
    Person::print();
    cout << "\tDepartment: " << department << endl;
    cout << "\tAdvisees: " << endl;
    cout << "----" << endl;
    advisees.printList();
    cout << "----" << endl;
}

// Print the information of all of the advisees
void Faculty::printAdvisees(BST<Person*> *sT)
{
    ListNode<int> *current = advisees.getHead();
    while (current!=NULL)
    {
        cout << endl;
        sT->searchPrint(current->data);
        current = current->next;
    }
    cout << endl;
}

// Save to file
void Faculty::save(ofstream &myStream)
{
    Person::save(myStream);
    myStream << department << endl;
}

void Faculty::removeAdvisee(int key)
{
    advisees.remove(key);
}
