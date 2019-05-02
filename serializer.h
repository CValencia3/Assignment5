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
    // Serialize a whole tree
    void serializeTree(BST<Person*> &students, BST<Person*> &faculty);
    // Recursively serialize a node
    void serializeNode(TreeNode<Person*>* root, ofstream &myStream);
    // Deserialize from a file
    void deserialize(BST<Person*> &students, BST<Person*> &faculty);

    // Parse
    int parseInt(string s);
    double parseDouble(string s);

    // Assign advisees to advisors
    void reverseAssignAdvisees(BST<Person*> &students, BST<Person*> &faculty);
    // recursive assign
    void recAdd(TreeNode<Person*>* node, BST<Person*> &faculty);
    // find advisee and assign to faculty
    void searchAddAdvisee(int advisor, int advisee, BST<Person*> &faculty);

    DoublyLinkedList<int>* FacultyIDs;
};
