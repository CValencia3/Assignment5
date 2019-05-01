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
    void addFaculty(int id, string nm, string lvl, string dpt);
    void deleteFaculty(int id, string nm, string lvl, string dpt);
    void collectFaculty();
    void recCollectFaculty(TreeNode<Person*>* myNode);
    void printStudentInformation(int id);
    void printFacultyInformation(int id);
    bool containsStudentID(int id);
    bool containsFacultyID(int id);

    void replaceAdvisor(int studID, int facID); // replace the current advisor with a specific faculty member
    void switchAdvisor(int facID, int studID);  // Remove the current student from the faculty member's
                                                // list and randomly assign them

    void undo(); // pulls the most recent obect from the undo stack and puts it on the redo stack
    void redo(); // pulls the most recent obect from the redo stack and puts it on the undo stack

    BST<Person*>* studentDatabase; // Student Tree
    BST<Person*>* facultyDatabase; // Faculty Tree
    DoublyLinkedList<int>* facultyIDs; // Faculty IDs
    Undo undoStack;
    Redo redoStack;
    serializer myS;
    // Redo Stack
};
