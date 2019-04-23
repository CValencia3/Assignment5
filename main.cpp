#include <string>
#include <iostream>

#include "BST.h"
#include "genDLL.h"
#include "DeletedPerson.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"

int main(int argc, char const *argv[])
{

    BST<Person> myTree;

    Student s(10,"Matt","Freshman","Music",11,4.0);
    Faculty f(12,"Mandrew","associate","math");
    f.AddAvisee(10);
    f.print();

    DeletedPerson myPerson(s, &myTree);
    DeletedPerson myPerson2(f, &myTree);

    cout << "----------" << endl;
    myTree.printTree();

    myPerson.undoOperation();
    // myPerson2.undoOperation();

    myTree.printTree();

    // Christian
    // For some reason, my tree won't delete null out the root node, so we need to fix that

    myPerson.redoOperation();
    // myPerson2.redoOperation();

    cout << "----------" << endl;
    myTree.printTree();


    GenStack<Manips> myStudents(5);

    return 0;
}
