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

int main(int argc, char const *argv[])
{
    ofstream tempStream;
    tempStream.open("temp.txt");

    BST<Person> myTree;

    Student s(10,"Matt","Freshman","Music",11,4.0);
    Faculty f(12,"Mandrew","associate","math");
    f.AddAvisee(10);
    f.save(tempStream);

    InsertedPerson myPerson(s, &myTree);
    // DeletedPerson myPerson2(f, &myTree);

    cout << "----------" << endl;
    myTree.printTree();

    myPerson.redoOperation();
    // myPerson2.undoOperation();

    myTree.printTree();

    myPerson.undoOperation();
    // myPerson2.redoOperation();

    cout << "----------" << endl;
    myTree.printTree();


    GenStack<Manips> myStudents(5);

    tempStream.close();

    return 0;
}
