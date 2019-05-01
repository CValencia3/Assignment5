#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "BST.h"
#include "genDLL.h"
#include "DeletedPerson.h"
#include "InsertedPerson.h"
#include "Student.h"
#include "Faculty.h"
#include "serializer.h"
#include "removeAdvisor.h"
#include "addAdvisor.h"
#include "Undo.h"
#include "Redo.h"


using namespace std;
class Database
{
    // Methods
public:
    Database(); // Constructor
    ~Database(); // Destructor

    void initialize(); // Deserialize function
    void exit(); // Serialize function
    void addStudent(int id, string nm, string lvl, string mjr, int adv, double gpa);
    void deleteStudent(int id, string nm, string lvl, string mjr, int adv, double gpa);
    void addFaculty(int id, string name, string level, string department);
    void deleteFaculty(int id);

    void undo(); // pulls the most recent obect from the undo stack and puts it on the redo stack
    void redo(); // pulls the most recent obect from the redo stack and puts it on the undo stack

    BST<Person*>* studentDatabase; // Student Tree
    BST<Person*>* facultyDatabase; // Faculty Tree
    DoublyLinkedList<int>* facultyIDs; // Faculty IDs
    Undo undoStack;
    Redo redoStack;
    serializer myS;
    // Redo Stack
private:
};

Database::~Database()
{
    // cout << "Here" << endl;
    delete studentDatabase;
    delete facultyDatabase;
    delete facultyIDs;
}

Database::Database()
{
    studentDatabase = new BST<Person*>;
    facultyDatabase = new BST<Person*>;
    facultyIDs = new DoublyLinkedList<int>;
    // undoStack = new Undo(5);
    // redoStack = new Redo(5);

    initialize();

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

void Database::deleteStudent(int id, string nm, string lvl, string mjr, int adv, double gpa)
{
    cout << studentDatabase->elements() << endl;


    Student* tempStudent = new Student(id, nm, lvl, mjr, adv, gpa); // Create student object

    Manips* myP = new DeletedPerson(tempStudent, studentDatabase, facultyDatabase); // Create deletedStudent object
    ((Faculty*)facultyDatabase->findKey(adv))->removeAdvisee(id); // Remove student from list of advisees
    studentDatabase->deleteR(id); // Remove the student from the database

    undoStack.push(myP); // Add to undo stack

    redoStack.clear(); // Clear the redos

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

void Database::addFaculty(int id, string name, string level, string department)
{
    Faculty* tempFaculty = new Faculty(id, name, level, department, facultyIDs);

    InsertedPerson* myNip = new InsertedPerson(tempFaculty, facultyDatabase, studentDatabase, facultyIDs);

    Manips* myP = myNip;
    undoStack.push(myNip);

    facultyDatabase->insert(tempFaculty->id, tempFaculty);

    redoStack.clear();

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

void Database::deleteFaculty(int id)
{
    DeletedPerson* myNip = new DeletedPerson(facultyDatabase->findKey(id), facultyDatabase, studentDatabase, facultyIDs);
    undoStack.push(myNip);

    facultyDatabase->deleteR(id);

    redoStack.clear();

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}

void Database::undo()
{
    if(undoStack.isEmpty())
    {
        cout << "empty" << endl;
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

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->undoOperation();
            redoStack.push(temp);

            cout << "case: 1" << endl;
            break;
        }
        case 2:
        {
            DeletedPerson* temp = (DeletedPerson*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->undoOperation();
            redoStack.push(temp);

            cout << "case: 2" << endl;
            break;
        }
        case 3:
        {
            removeAdvisor* temp = (removeAdvisor*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->undoOperation();
            redoStack.push(temp);

            cout << "case: 3" << endl;
            break;
        }
        case 4:
        {
            addAdvisor* temp = (addAdvisor*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->undoOperation();
            redoStack.push(temp);

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
        cout << "empty" << endl;
        return;
    }


    Manips* pop = redoStack.pop();
    switch (pop->id)
    {
        case 1:
        {
            InsertedPerson* temp = (InsertedPerson*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 1" << endl;
            break;
        }
        case 2:
        {
            DeletedPerson* temp = (DeletedPerson*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 2" << endl;
            break;
        }
        case 3:
        {
            removeAdvisor* temp = (removeAdvisor*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 3" << endl;
            break;
        }
        case 4:
        {
            addAdvisor* temp = (addAdvisor*)pop;

            cout << temp->affectedPerson->id << " " << temp->affectedPerson->name << endl;
            temp->redoOperation();
            undoStack.push(temp);

            cout << "case: 4" << endl;
            break;
        }
    }

    cout << "Elements in Student Tree: " << studentDatabase->elements() << endl;
    cout << "Elements in Faculty Tree: " << facultyDatabase->elements() << endl << endl << endl;
}
