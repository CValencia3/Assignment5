#include <string>
#include <iostream>

#include "BST.h"
#include "genDLL.h"
#include "StudDel.h"

int main(int argc, char const *argv[])
{

    BST<int> myTree;

    myTree.insert(100, 100);
    myTree.deleteR(100);

    StudDel myStud(10, "Matt", "Here", "Junior", 100);

    return 0;
}
