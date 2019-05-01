#include "database.h"

using namespace std;

Database::~Database()
{
    delete studentDatabase;
    delete facultyDatabase;
    delete facultyIDs;
}

Database::Database()
{
    studentDatabase = new BST<Person*>;
    facultyDatabase = new BST<Person*>;
    facultyIDs = new DoublyLinkedList<int>;
    initialize();

    collectFaculty();


    //exit();
}

void Database::initialize()
{
    // serializer myS;
    myS.deserialize(*studentDatabase, *facultyDatabase);
}

void Database::exit()
{
    // serializer myS;
    myS.serializeTree(*studentDatabase, *facultyDatabase);
}

// DONE
void Database::addStudent(int id, string nm, string lvl, string mjr, int adv, double gpa)
{
    Student* tempStudent = new Student(id, nm, lvl, mjr, adv, gpa);

    studentDatabase->insert(tempStudent->id, tempStudent);
    myS.searchAddAdvisee(adv,id,*facultyDatabase);
    Manips* myP = new InsertedPerson(tempStudent, studentDatabase, facultyDatabase);
    undoStack.push(myP);

    redoStack.clear();

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

// DONE
void Database::deleteStudent(int id, string nm, string lvl, string mjr, int adv, double gpa)
{
    Student* tempStudent = new Student(id, nm, lvl, mjr, adv, gpa); // Create student object

    Manips* myP = new DeletedPerson(tempStudent, studentDatabase, facultyDatabase); // Create deletedStudent object
    ((Faculty*)facultyDatabase->findKey(adv))->removeAdvisee(id); // Remove student from list of advisees
    studentDatabase->deleteR(id); // Remove the student from the database

    undoStack.push(myP); // Add to undo stack

    redoStack.clear(); // Clear the redos

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

// DONE
void Database::addFaculty(int id, string nm, string lvl, string dpt)
{

    Faculty* tempFaculty = new Faculty(id, nm, lvl, dpt);

    facultyDatabase->insert(tempFaculty->id, tempFaculty);
    facultyIDs->insertFront(tempFaculty->id);

    Manips* myP = new InsertedPerson(tempFaculty, facultyDatabase, studentDatabase);
    undoStack.push(myP);

    redoStack.clear();

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

// DONE
void Database::deleteFaculty(int id, string nm, string lvl, string dpt)
{
    Faculty* tempFaculty = new Faculty(id, nm, lvl, dpt);
    DeletedPerson* myNip = new DeletedPerson(tempFaculty, facultyDatabase, studentDatabase);

    undoStack.push(myNip);
    Faculty* actualFaculty = (Faculty*)facultyDatabase->findKey(id);

    facultyIDs->remove(actualFaculty->id);

    int facultyNum = actualFaculty->advisees.getSize();

    while(!(actualFaculty->advisees.isEmpty()))
    {
        Student* tempStudent = (Student*)(studentDatabase->findKey(actualFaculty->advisees.removeFront()));
        tempStudent->advisorID = facultyIDs->index(rand()%facultyNum);
    }

    facultyDatabase->deleteR(id);
    redoStack.clear();

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

// Done
void Database::replaceAdvisor(int studID, int facID)
{
    addAdvisor* tempAdd = new addAdvisor(studentDatabase->findKey(studID), facID, studentDatabase, facultyDatabase, facultyIDs);
    tempAdd->redoOperation();
    undoStack.push(tempAdd);
    studentDatabase->printTree();
}

void Database::switchAdvisor(int facID, int studID)
{
    removeAdvisor* tempRemove = new removeAdvisor(facultyDatabase->findKey(facID), studID, facultyDatabase, studentDatabase, facultyIDs);
    tempRemove->redoOperation();
    undoStack.push(tempRemove);
    studentDatabase->printTree();
}

void Database::undo()
{
    if(undoStack.isEmpty())
    {
        cout << "There's nothing to undo" << endl;
        return;
    }
    // undoStack->pop()->undoOperation();
    //This is the right cast for insert person.

    Manips* pop = undoStack.pop();
    switch (pop->id)
    {
        case 1:
        {
            InsertedPerson* temp = (InsertedPerson*)pop;
            temp->undoOperation();
            redoStack.push(temp);

            cout << "case: 1" << endl;
            break;
        }
        case 2:
        {
            DeletedPerson* temp = (DeletedPerson*)pop;
            temp->undoOperation();
            redoStack.push(temp);

            cout << "case: 2" << endl;
            break;
        }
        case 3:
        {
            // replaceAdvisor* temp = (replaceAdvisor*)pop;
            // temp->undoOperation();
            // redoStack.push(temp);

            cout << "case: 3" << endl;
            break;
        }
        case 4:
        {
            addAdvisor* temp = (addAdvisor*)pop;
            temp->undoOperation();
            redoStack.push(temp);

            studentDatabase->printTree();

            cout << "case: 4" << endl;
            break;
        }
    }
    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

void Database::redo()
{
    if(redoStack.isEmpty())
    {
        cout << "There's nothing to redo" << endl;
        return;
    }


    Manips* pop = redoStack.pop();
    switch (pop->id)
    {
        case 1:
        {
            InsertedPerson* temp = (InsertedPerson*)pop;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 1" << endl;
            break;
        }
        case 2:
        {
            DeletedPerson* temp = (DeletedPerson*)pop;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 2" << endl;
            break;
        }
        case 3:
        {
            // removeAdvisor* temp = (removeAdvisor*)pop;
            // temp->redoOperation();
            // undoStack.push(temp);
            //
            // cout << "case: 3" << endl;
            // break;
        }
        case 4:
        {
            addAdvisor* temp = (addAdvisor*)pop;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 4" << endl;
            break;
        }
    }

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

void Database::collectFaculty()
{
    recCollectFaculty(facultyDatabase->root);
}

void Database::recCollectFaculty(TreeNode<Person*>* myNode)
{
    if(myNode == NULL) return;

    facultyIDs->insertFront(myNode->value->id);
    recCollectFaculty(myNode->right);
    recCollectFaculty(myNode->left);
}

void Database::printStudentInformation(int id)
{
    cout << endl;
    studentDatabase->findKey(id)->print();
}

void Database::printFacultyInformation(int id)
{
    cout << endl;
    facultyDatabase->findKey(id)->print();
}

bool Database::containsStudentID(int id)
{
    try
    {
        studentDatabase->findKey(id);
        return true;
    }
    catch(invalid_argument)
    { return false; }
}

bool Database::containsFacultyID(int id)
{
    try
    {
        facultyDatabase->findKey(id);
        return true;
    }
    catch(invalid_argument)
    { return false; }
}
