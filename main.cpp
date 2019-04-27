
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
    //Fixed by passing by reference!
    BST<Person*> myTree;

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


    return 0;
}
