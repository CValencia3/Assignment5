#include <string>
#include <iostream>

#include "BST.h"
#include "genQ.h"
#include "genDLL.h"

int main(int argc, char const *argv[])
{

    BST<int> myTree;

    myTree.insert(100, 100);
    myTree.deleteR(100);

    return 0;
}
