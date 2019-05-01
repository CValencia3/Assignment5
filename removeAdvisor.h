#pragma once

#include <string>
#include <typeinfo>

#include "Manips.h"
#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

class removeAdvisor: public Manips
{
public:
    removeAdvisor();
    removeAdvisor(Person *myP, int otherID, BST<Person*>* aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs);
    void undoOperation(); // Change Advisor
    void redoOperation(); // Change back

private:
    Person *affectedPerson;
    BST<Person*>* affectedTree; // Tree that contains the person
    BST<Person*>* otherTree; // Tree that contains the person
    int otherID;
    DoublyLinkedList<int>* facultyIDs;
};

removeAdvisor::removeAdvisor()
{
    id = 3;
}

removeAdvisor::removeAdvisor(Person *myP, int oID, BST<Person*>* aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs)
    :affectedPerson(myP), affectedTree(aT), otherTree(oT), otherID(oID)
{
    id = 3;
    facultyIDs = IDs;
}

void removeAdvisor::undoOperation() // Oposite of action done, so set advisor to old
{
    Faculty* tempFac;
    Student* tempStud;

    if(affectedPerson->isStudent)
    {
        // If it's a student's advisor being edited

        // Gives the student the faculty member and adds their name to the faculty's list of advisees

        tempStud = dynamic_cast<Student*> (affectedPerson);
        tempFac = dynamic_cast<Faculty*> (otherTree->findKey(otherID));
    }
    else
    {
        // if it's faculty being edited

        // Insert the faculty and give them back all of their students

        tempFac = dynamic_cast<Faculty*> (affectedPerson);
        tempStud = dynamic_cast<Student*> (otherTree->findKey(otherID));
    }

    int numberOfFaculty = facultyIDs->getSize();
    tempStud->advisorID = otherID;

    tempFac->AddAdvisee(tempStud->id);
}

void removeAdvisor::redoOperation() // Action done, so delete
{
    Faculty* tempFac;
    Student* tempStud;

    if(affectedPerson->isStudent)
    {
        // If it's a student's advisor being edited

        // removes the faculty and randomly assigns

        tempStud = dynamic_cast<Student*> (affectedPerson);
        tempFac = dynamic_cast<Faculty*> (otherTree->findKey(otherID));
    }
    else
    {
        // if it's faculty being edited

        // removes the student and randomly assigns

        tempFac = dynamic_cast<Faculty*> (affectedPerson);
        tempStud = dynamic_cast<Student*> (otherTree->findKey(otherID));
    }

    cout << facultyIDs->getSize() << endl;
    int numberOfFaculty = facultyIDs->getSize();

    tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);

    tempFac->removeAdvisee(tempStud->id);
}
