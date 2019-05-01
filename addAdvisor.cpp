#include "addAdvisor.h"

using namespace std;

addAdvisor::addAdvisor()
{
    id = 4;
}

addAdvisor::addAdvisor(Person *aSt, int fID, BST<Person*>* sT, BST<Person*> *fT, DoublyLinkedList<int>* IDs)
    :actualStudent((Student*)aSt), studentTree(sT), facultyTree(fT), facultyID(fID)
{
    id = 4;
    facultyIDs = IDs;
    originalFaculty = actualStudent->advisorID;
}

void addAdvisor::undoOperation() // Oposite of action done, so set advisor to old
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
