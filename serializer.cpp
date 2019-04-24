#include <iostream>
#include <fstream>
#include <string>

#include "serializer.h"
#include "Person.h"

#include "BST.h"

serializer::serializer()
{

}

serializer::~serializer()
{

}

void serializer::serializeTree(BST<Person> &myTree)
{
    ofstream tempStream;
    tempStream.open("temp.txt");

    serializeNode(myTree.root, tempStream);

    tempStream.close();
}

void serializer::serializeNode(TreeNode<Person>* root, ofstream &myStream)
{
    if(root->left!=NULL) serializeNode(root->left, myStream);
    if(root!= NULL) root->value.save(myStream);
    if(root->right!=NULL) serializeNode(root->right, myStream);
}
