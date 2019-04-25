
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
    //I think the problem is that this casts everything to a Person
    BST<Person> myTree;

    Student s(10,"Matt","Freshman","Music",11,4.0);
    Student q(100,"Joe","Freshman","Music",11,4.0);
    Student l(101,"Helen","Freshman","Music",11,4.0);

    //Virtual works when you access it like this
    Person *test;
    test = &q;
    test->print();


    Faculty f(12,"Mandrew","associate","math");
    f.AddAvisee(10);

    //By the time we put them in here the casting is already too late.
    //Either we make this a template class or split it up
    //Faculty need special things about its advisee list anyway
    InsertedPerson myPerson(s, &myTree);
    InsertedPerson myPerson1(q, &myTree);
    InsertedPerson myPerson2(l, &myTree);
    // DeletedPerson myPerson2(f, &myTree);



    myPerson.redoOperation();
    myPerson1.redoOperation();
    myPerson2.redoOperation();

    cout << "----------" << endl;
    myTree.printTree();


    // // myPerson2.undoOperation();
    //
    // serializer myS;
    // myS.serializeTree(myTree);
    //
    // myTree.printTree();
    //
    // myPerson.undoOperation();
    // // myPerson2.redoOperation();
    //
    // cout << "----------" << endl;
    // myTree.printTree();


    GenStack<Manips> myStudents(5);


    return 0;
}
