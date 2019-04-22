#include <string>
#include <iostream>

#include "BST.h"
#include "genDLL.h"
#include "StudDel.h"
#include "GenStack.h"
#include "testClass.h"

int main(int argc, char const *argv[])
{

    // BST<int> myTree;
    //
    // myTree.insert(100, 100);
    // myTree.deleteR(100);
    //
    StudDel myStud(10, "Matt", "Here", "Junior", 100);

    GenStack<Manips> myStudents(5);
    // StudDel myStud;
    myStudents.push(myStud);

    testClass a(5);
    testClass b(5);

    if(a==b) cout << "a" << endl;
    if(a<=b) cout << "b" << endl;
    if(a>=b) cout << "c" << endl;
    if(a!=b) cout << "d" << endl;

    return 0;
}
