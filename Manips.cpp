#include "Manips.h"

// Need this to prevent things from being defined twice

Manips::Manips()
{
    cout << "HERE" << endl;
}

Manips::Manips(Person *myP, Person *oP, BST<Person*> *aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs, int t)
{
    affectedPerson = myP;
    otherPerson = oP;
    affectedTree = aT;
    otherTree = oT;
    facultyIDs = IDs;
    type = t;

}

Manips::Manips(Person *myP, BST<Person*> *aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs, int t)
{
    affectedPerson = myP;
    otherPerson = NULL;
    affectedTree = aT;
    otherTree = oT;
    facultyIDs = IDs;
    type = t;

}

void Manips::undoOperation()
{
    Faculty* tempFac;
    Student* tempStud;

    if(affectedPerson->isStudent)
    {
        tempStud = dynamic_cast<Student*> (affectedPerson);
        tempFac = dynamic_cast<Faculty*> (otherPerson);
        cout << "undoing remove advisor" << endl;
    }
    else
    {
        tempFac = dynamic_cast<Faculty*> (affectedPerson);
        tempStud = dynamic_cast<Student*> (otherPerson);
        cout << "undoing remove advisor" << endl;
    }


    // Undo remove advisor
        // int numberOfFaculty = facultyIDs->getSize();
        // tempStud->advisorID = otherID;

    // Undo add advisor
        // cout << facultyIDs->getSize() << endl;
        // int numberOfFaculty = facultyIDs->getSize();
        //
        // tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);
        //
        // tempFac->removeAdvisee(tempStud->id);

    // Undo Insert Person
        if(affectedPerson->isStudent)
        {
            // // If it's a student being edited
            // Student* tempStud = dynamic_cast<Student*> (affectedPerson);
            // Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));
            // tempFac->removeAdvisee(tempStud->id);

            cout << "undoing student insert" << endl;
        }
        else
        {
            // // if it's faculty being edited
            // Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);
            // ListNode<int>* current = tempFac->advisees.getHead();
            // int numberOfFaculty = facultyIDs->getSize();
            // while(current!=NULL && !(otherTree->isEmpty()))
            // {
            //     Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));
            //     cout << tempStud->advisorID << endl;
            //     tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);
            //
            //     current = current->next;
            // }
            cout << "undoing faculty insert" << endl;
        }
        // affectedTree->deleteR(affectedPerson->id);







    // Undo student Delete
        if(affectedPerson->isStudent)
        {
            // // If it's a student being edited
            //
            // // Insert the student and change the faculty to have them in their list
            //
            // Student* tempStud = dynamic_cast<Student*> (affectedPerson);
            //
            // Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));
            //
            // tempFac->AddAdvisee((tempStud->id));
        }
        else
        {
            // // if it's faculty being edited
            //
            // // Insert the faculty and give them back all of their students
            //
            // Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);
            // ListNode<int>* current = tempFac->advisees.getHead();
            //
            // while(current!=NULL && !(otherTree->isEmpty()))
            // {
            //     Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));
            //
            //     tempStud->advisorID = tempFac->id;
            //
            //     current = current->next;
            // }
        }

        // affectedTree->insert(affectedPerson->id, affectedPerson);
}

void Manips::redoOperation()
{

    Faculty* tempFac;
    Student* tempStud;

    if(affectedPerson->isStudent)
    {
        tempStud = dynamic_cast<Student*> (affectedPerson);
        tempFac = dynamic_cast<Faculty*> (otherPerson);
        cout << "redoing remove advisor" << endl;
    }
    else
    {
        cout << "redoing remove advisor" << endl;
        tempFac = dynamic_cast<Faculty*> (affectedPerson);
        tempStud = dynamic_cast<Student*> (otherPerson);
    }


    // Redo remove advisor
        // int numberOfFaculty = facultyIDs->getSize();
        // tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);
        // tempFac->removeAdvisee(tempStud->id);



    // Redo add advisor
        // int numberOfFaculty = facultyIDs->getSize();
        // tempStud->advisorID = otherID;
        //
        // tempFac->AddAdvisee(tempStud->id);

    // Redo person insert
        if(affectedPerson->isStudent)
        {
            cout << "redoing insert student" << endl;

            // // If it's a student being edited
            //
            // // Insert the student and change the faculty to have them in their list
            //
            // Student* tempStud = dynamic_cast<Student*> (affectedPerson);
            //
            // Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));
            //
            // tempFac->AddAdvisee((tempStud->id));
        }
        else
        {
            cout << "redoing insert faculty" << endl;

            // // if it's faculty being edited
            //
            //
            // // Insert the faculty and give them back all of their students
            //
            // Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);
            // ListNode<int>* current = tempFac->advisees.getHead();
            //
            // while(current!=NULL && !(otherTree->isEmpty()))
            // {
            //     Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));
            //
            //     tempStud->advisorID = tempFac->id;
            //
            //     current = current->next;
            // }

        }

        // affectedTree->insert(affectedPerson->id, affectedPerson);



    // Undoing faculty delete
        if(affectedPerson->isStudent)
        {
            cout << "redoing delete student" << endl;

            // // If it's a student being edited
            // Student* tempStud = dynamic_cast<Student*> (affectedPerson);
            // Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));
            //
            // tempFac->removeAdvisee(tempStud->id);
        }
        else
        {
            cout << "redoing delete faculty" << endl;

            // // if it's faculty being edited
            // Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);
            // ListNode<int>* current = tempFac->advisees.getHead();
            //
            // int numberOfFaculty = facultyIDs->getSize();
            //
            // while(current!=NULL&&!(otherTree->isEmpty()))
            // {
            //     Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));
            //
            //     tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);
            //
            //     current = current->next;
            // }
        }
        // affectedTree->deleteR(affectedPerson->id);
}
