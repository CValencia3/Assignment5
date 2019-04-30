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
    void deleteStudent(int id);
    void addFaculty(int id, string name, string level, string department);
    void deleteFaculty(int id);

    void undo();
    void redo();
    // undo() // pulls the most recent obect from the undo stack and puts it on the redo stack
    // redo() // pulls the most recent obect from the redo stack and puts it on the undo stack

private:

    // Variables
public:
    BST<Person*>* studentDatabase; // Student Tree
    BST<Person*>* facultyDatabase; // Faculty Tree
    DoublyLinkedList<int>* facultyIDs; // Faculty IDs
    Undo* undoStack;
    Redo* redoStack;
    // Redo Stack
private:
};

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
    undoStack = new Undo(5);
    redoStack = new Redo(5);

    initialize();

    exit();
}

void Database::initialize()
{
    serializer myS;
    myS.deserialize(*studentDatabase, *facultyDatabase);
}

void Database::exit()
{
    serializer myS;
    myS.serializeTree(*studentDatabase, *facultyDatabase);
}

void Database::addStudent(int id, string nm, string lvl, string mjr, int adv, double gpa)
{
    Student* tempStudent = new Student(id, nm, lvl, mjr, adv, gpa);
    studentDatabase->insert(tempStudent->id, tempStudent);


    InsertedPerson* myNip = new InsertedPerson(tempStudent, studentDatabase, facultyDatabase, facultyIDs);
    undoStack->push(myNip);

    redoStack->clear();
}

void Database::deleteStudent(int id)
{
    DeletedPerson* myNip = new DeletedPerson(studentDatabase->findKey(id), studentDatabase, facultyDatabase, facultyIDs);

    undoStack->push(myNip);
    studentDatabase->deleteR(id);

    redoStack->clear();
}

void Database::addFaculty(int id, string name, string level, string department)
{
    Faculty* tempFaculty = new Faculty(id, name, level, department, facultyIDs);

    InsertedPerson* myNip = new InsertedPerson(tempFaculty, facultyDatabase, studentDatabase, facultyIDs);
    undoStack->push(myNip);

    facultyDatabase->insert(tempFaculty->id, tempFaculty);

    redoStack->clear();
}

void Database::deleteFaculty(int id)
{
    DeletedPerson* myNip = new DeletedPerson(facultyDatabase->findKey(id), facultyDatabase, studentDatabase, facultyIDs);
    undoStack->push(myNip);

    facultyDatabase->deleteR(id);

    redoStack->clear();
}

void Database::undo()
{
    if(undoStack->isEmpty())
        return;

    Manips* tempManip = undoStack->pop();
    tempManip->undoOperation();
    redoStack->push(tempManip);
}

void Database::redo()
{
    if(redoStack->isEmpty())
        return;

    Manips* tempManip = redoStack->pop();
    tempManip->redoOperation();
    undoStack->push(tempManip);
}
