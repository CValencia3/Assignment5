#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "BST.h"
#include "Person.h"

using namespace std;

class serializer
{
private:
public:
    serializer();
    ~serializer();
    void serializeTree(BST<Person*> &myTree);
    void serializeNode(TreeNode<Person*>* root, ofstream &myStream);
};
