#include "addAdvisor.h"

using namespace std;

// Default contructor
addAdvisor::addAdvisor()
{
    id = 4; //4 = add advisor
}

// Overloaded constructor that takes in:
    // pointer to a person
    // id for a faculty
    // pointer to the student database
    // pointer to the faculty database
    // pointer to list of faculty ids
addAdvisor::addAdvisor(Person *aSt, int fID, BST<Person*>* sT, BST<Person*> *fT, DoublyLinkedList<int>* IDs)
    :actualStudent((Student*)aSt), studentTree(sT), facultyTree(fT), facultyID(fID)
{
    id = 4; //4 = add advisor
    facultyIDs = IDs;
    originalFaculty = actualStudent->advisorID;
}

// Oposite the action, so set advisor to old
void addAdvisor::undoOperation()
{
    Faculty* tempFac = (Faculty*)(facultyTree->findKey(facultyID));
    Student* tempStud = actualStudent;

    tempStud->advisorID = originalFaculty;
    tempFac->removeAdvisee(tempStud->id);

    Faculty* oldFac = (Faculty*)(facultyTree->findKey(originalFaculty));
    oldFac->advisees.insertFront(tempStud->id);
}

void addAdvisor::redoOperation() // Action done, so delete
{
    Student* tempStud = actualStudent;
    Faculty* tempFac = (Faculty*)(facultyTree->findKey(facultyID));

    tempStud->advisorID = facultyID;

    tempFac->AddAdvisee(tempStud->id);
}
