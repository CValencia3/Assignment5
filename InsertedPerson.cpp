
#include <string>
#include <typeinfo>

#include "InsertedPerson.h"

InsertedPerson::InsertedPerson()
{

}

InsertedPerson::~InsertedPerson()
{
    // try
    // {
        delete facultyIDs;
    // }
    // catch exception
    // {
    //
    // }
}

InsertedPerson::InsertedPerson(Person *myP, BST<Person*> *aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs)
    :affectedPerson(myP), affectedTree(aT), otherTree(oT)
{
    id = 1;
    facultyIDs = IDs;
}
InsertedPerson::InsertedPerson(Person *myP, BST<Person*> *aT, BST<Person*> *oT)
    :affectedPerson(myP), affectedTree(aT), otherTree(oT)
{
    id = 1;
    if(!myP->isStudent)
    {
        facultyIDs = new DoublyLinkedList<int>;
        recFacultyID(affectedTree->root);
    }

}
void InsertedPerson::recFacultyID(TreeNode<Person*>* node)
{
    if(node == NULL) return;
    recFacultyID(node->left);
    facultyIDs->insertFront(node->key);
    recFacultyID(node->right);
}

void InsertedPerson::undoOperation() // Oposite of action done
{
    cout << "t" << endl;
    if(affectedPerson->isStudent)
    {
        // If it's a student being edited

        cout << "t" << endl;
        Student* tempStud = dynamic_cast<Student*> (affectedPerson);
        cout << "t" << endl;

        Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));
        cout << "t" << endl;

        tempFac->removeAdvisee(tempStud->id);
        cout << "t" << endl;

    }
    else
    {
        // if it's faculty being edited
        Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);
        ListNode<int>* current = tempFac->advisees.getHead();
        int numberOfFaculty = facultyIDs->getSize();
        while(current!=NULL && !(otherTree->isEmpty()))
        {

            Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));

            cout << tempStud->advisorID << endl;

            tempStud->advisorID = facultyIDs->index(rand()%numberOfFaculty);


            current = current->next;
        }
    }
    affectedTree->deleteR(affectedPerson->id);
}

void InsertedPerson::redoOperation() // Action done
{
    if(affectedPerson->isStudent)
    {
        // If it's a student being edited

        // Insert the student and change the faculty to have them in their list

        Student* tempStud = dynamic_cast<Student*> (affectedPerson);

        Faculty* tempFac = dynamic_cast<Faculty*> (otherTree->findKey(tempStud->advisorID));

        tempFac->AddAdvisee((tempStud->id));
    }
    else
    {
        // if it's faculty being edited


        // Insert the faculty and give them back all of their students

        Faculty* tempFac = dynamic_cast<Faculty*> (affectedPerson);

        ListNode<int>* current = tempFac->advisees.getHead();

        while(current!=NULL && !(otherTree->isEmpty()))
        {

            Student* tempStud = dynamic_cast<Student*> (otherTree->findKey(current->data));


            tempStud->advisorID = tempFac->id;


            current = current->next;
        }

    }

    affectedTree->insert(affectedPerson->id, affectedPerson);
}
