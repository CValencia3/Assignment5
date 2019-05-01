# include "removeAdvisor.h"

using namespace std;

removeAdvisor::removeAdvisor()
{
    id = 3;
}

removeAdvisor::removeAdvisor(Person *aFac, int studentID, BST<Person*>* fT, BST<Person*> *sT, DoublyLinkedList<int>* IDs)
    :actualFaculty((Faculty*)aFac), facultyTree(fT), studentTree(sT), studentID(studentID)
{
    id = 3;
    facultyIDs = IDs;
}

void removeAdvisor::undoOperation() // Oposite of action done, so set advisor to old
{
    Faculty* tempFac = actualFaculty;
    Student* tempStud = (Student*)studentTree->findKey(studentID);

    tempFac->AddAdvisee(studentID);
    tempStud->advisorID = tempFac->id;
}

void removeAdvisor::redoOperation() // Action done, so delete
{
    Faculty* tempFac = actualFaculty;
    Student* tempStud = (Student*)studentTree->findKey(studentID);

    tempFac->removeAdvisee(studentID);

    int numberOfFaculty = facultyIDs->getSize();

    while(tempFac->id == tempStud->advisorID)
    {
        tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);
    }
}
