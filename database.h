#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "BST.h"
#include "genDLL.h"
#include "Student.h"
#include "Faculty.h"
#include "serializer.h"

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

    void undo(); // pulls the most recent obect from the undo stack and puts it on the redo stack
    void redo(); // pulls the most recent obect from the redo stack and puts it on the undo stack

private:

    // Variables
public:
    BST<Person*>* studentDatabase; // Student Tree
    BST<Person*>* facultyDatabase; // Faculty Tree
    DoublyLinkedList<int>* facultyIDs; // Faculty IDs


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
    // undoStack = new Undo(5);
    // redoStack = new Redo(5);

    initialize();

    // studentDatabase->printTree();


    BST<Person*>* newTree = studentDatabase->copyTree();
    // newTree->printTree();
    delete newTree;
    exit();

    cout << "jere" << endl;

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
    cout << "done" << endl;

}

void Database::addStudent(int id, string nm, string lvl, string mjr, int adv, double gpa)
{
    Student* tempStudent = new Student(id, nm, lvl, mjr, adv, gpa);

    studentDatabase->insert(tempStudent->id, tempStudent);
}

void Database::deleteStudent(int id)
{
    studentDatabase->deleteR(id);
}

void Database::addFaculty(int id, string name, string level, string department)
{
    // facultyDatabase->insert(tempFaculty->id, tempFaculty);
}

void Database::deleteFaculty(int id)
{
    facultyDatabase->deleteR(id);
}

void Database::undo()
{

}

void Database::redo()
{

}
