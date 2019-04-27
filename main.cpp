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

<<<<<<< HEAD
    //Create some test students and faculty
    Student s(10,"Matt","Freshman","Music",11,4.0);
    Student q(100,"Joe","Freshman","Music",11,4.0);
    Student l;
    Student c;

    Faculty f;
    Faculty w;

    //Add students to advisee
    f.AddAdvisee(10);
    w.AddAdvisee(&c);
    w.AddAdvisee(&l);

    //Creat operations and add students
    InsertedPerson myPerson(&s, &studentDatabase);
    InsertedPerson myPerson1(&q, &studentDatabase);
    InsertedPerson myPerson2(&l, &studentDatabase);
    InsertedPerson student4(&c, &studentDatabase);
    myPerson.redoOperation();
    myPerson1.redoOperation();
    myPerson2.redoOperation();
    student4.redoOperation();

    InsertedPerson addFaculty(&f, &facultyDatabase);
    InsertedPerson addFaculty2(&w, &facultyDatabase);
    addFaculty.redoOperation();
    addFaculty2.redoOperation();

    cout << "----------" << endl;

    cout << "Printing test Faculty" << endl;
    facultyDatabase.printTree();
    cout << endl << "Printing test Student" << endl;
    c.print();

    cout << endl << "Print Advisor Test" << endl;
    c.printAdvisor(&facultyDatabase);

    cout << endl << "Print Advisees Test" << endl;
    w.printAdvisees(&studentDatabase);




    cout << "----------" << endl;
    studentDatabase.printTree();


    myPerson2.undoOperation();

    serializer myS;
    myS.serializeTree(studentDatabase);

    cout << "Testing student Lookup" << endl;
    cout << studentDatabase.contains(100) << endl;
    cout << studentDatabase.contains(200) << endl;

    cout << "----------" << endl;
    studentDatabase.searchPrint(100);
    studentDatabase.searchPrint(140);


    GenStack<Manips> undo(5);
    GenStack<Manips> redo(5);
=======
    // Student s(10,"Matt","Freshman","Music",11,4.0);
    // Student q(100,"Joe","Freshman","Music",11,4.0);
    // Student l(101,"Helen","Freshman","Music",11,4.0);
    //
    // Faculty f(12,"Mandrew","associate","math");
    // f.AddAvisee(10);
    //
    // InsertedPerson myPerson(&s, &myTree);
    // InsertedPerson myPerson1(&q, &myTree);
    // InsertedPerson myPerson2(&l, &myTree);
    //
    // myPerson.redoOperation();
    // myPerson1.redoOperation();
    // myPerson2.redoOperation();
    //
    // cout << "----------" << endl;
    // myTree.printTree();
    //
    // serializer myS;
    // myS.serializeTree(myTree);
>>>>>>> d2a8ab147a65d6937e68b2c2aa2ea54e33aae536


    return 0;
}
