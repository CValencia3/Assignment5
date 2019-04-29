#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Person.h"
#include "Student.h"
#include "Faculty.h"

#include "BST.h"
#include "genDLL.h"

using namespace std;

class serializer
{
private:
public:
    serializer();
    ~serializer();
    void serializeTree(BST<Person*> &students, BST<Person*> &faculty);
    void serializeNode(TreeNode<Person*>* root, ofstream &myStream);
    void deserialize(BST<Person*> &students, BST<Person*> &faculty, DoublyLinkedList<int>* IDs);

    int parseInt(string s);
    double parseDouble(string s);

    void reverseAssignAdvisees(BST<Person*> &students, BST<Person*> &faculty);
    void recAdd(TreeNode<Person*>* node, BST<Person*> &faculty);
    void searchAddAdvisee(int advisor, int advisee, BST<Person*> &faculty);

    DoublyLinkedList<int>* FacultyIDs;
};
