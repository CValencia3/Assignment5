//TO DO
/*
1. Add backwards fuctionality to changing a student's advisor
(the change should be reflected in the advisor's list)
2. Assigning a random advisor in faculty delete

*/
#include <string>
#include <iostream>
#include <fstream>

#include "BST.h"
#include "genDLL.h"
#include "DeletedPerson.h"
#include "InsertedPerson.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "serializer.h"

int main(int argc, char const *argv[])
{
    //Create two trees
    BST<Person*> studentDatabase;
    BST<Person*> facultyDatabase;

    DoublyLinkedList<int> facultyIDs;

    //Create some test students and faculty

    Faculty f(&facultyIDs);
    Faculty w(&facultyIDs);

    Student s(10,"Matt","Freshman","Music",f.id,4.0);
    Student q(100,"Joe","Freshman","Music",f.id,4.0);
    Student l;
    Student c;

    //Add students to advisee
    f.AddAdvisee(10);
    w.AddAdvisee(&c);
    w.AddAdvisee(&l);

    //Creat operations and add students
    InsertedPerson myPerson(&s, &studentDatabase, &facultyDatabase, &facultyIDs);
    InsertedPerson myPerson1(&q, &studentDatabase, &facultyDatabase, &facultyIDs);
    InsertedPerson myPerson2(&l, &studentDatabase, &facultyDatabase, &facultyIDs);
    InsertedPerson student4(&c, &studentDatabase, &facultyDatabase, &facultyIDs);
    myPerson.redoOperation();
    myPerson1.redoOperation();
    myPerson2.redoOperation();
    student4.redoOperation();

    InsertedPerson addFaculty(&f, &facultyDatabase, &studentDatabase, &facultyIDs);
    InsertedPerson addFaculty2(&w, &facultyDatabase, &studentDatabase, &facultyIDs);
    addFaculty.redoOperation();
    addFaculty2.redoOperation();

    studentDatabase.printTree();

    cout << "\n\n\n\n";


    addFaculty.undoOperation();

    cout << "\n\n\n\n";

    studentDatabase.printTree();





    //
    // cout << "----------" << endl;
    //
    // cout << "Printing test Faculty" << endl;
    // facultyDatabase.printTree();
    // cout << endl << "Printing test Student" << endl;
    // c.print();
    //
    // cout << endl << "Print Advisor Test" << endl;
    // c.printAdvisor(&facultyDatabase);
    //
    // cout << endl << "Print Advisees Test" << endl;
    // w.printAdvisees(&studentDatabase);
    //
    //
    //
    //
    // cout << "----------" << endl;
    // studentDatabase.printTree();
    //
    //
    // myPerson2.undoOperation();
    //
    // serializer myS;
    // myS.serializeTree(studentDatabase);
    //
    // cout << "Testing student Lookup" << endl;
    // cout << studentDatabase.contains(100) << endl;
    // cout << studentDatabase.contains(200) << endl;
    //
    // cout << "----------" << endl;
    // studentDatabase.searchPrint(100);
    // studentDatabase.searchPrint(140);
    //
    //
    // GenStack<Manips> undo(5);
    // GenStack<Manips> redo(5);


    return 0;
}
