//TO DO
/*
1. Add backwards fuctionality to changing a student's advisor
(the change should be reflected in the advisor's list)
2. Assigning a random advisor in faculty delete

*/
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

#include "BST.h"
#include "genDLL.h"
#include "DeletedPerson.h"
#include "InsertedPerson.h"
#include "GenStack.h"
#include "Student.h"
#include "Faculty.h"
#include "serializer.h"
#include "removeAdvisor.h"
#include "addAdvisor.h"


int main(int argc, char const *argv[])
{
    //Create two trees
    BST<Person*> studentDatabase;
    BST<Person*> facultyDatabase;
    DoublyLinkedList<int> facultyIDs;
    //Create serializer
    serializer myS;
    myS.deserialize(studentDatabase, facultyDatabase);


    // for (int i = 0; i < 10; i++)
    // {
    //     Person *j = new Student();
    //     studentDatabase.insert(j->id, j);
    //     Person *k = new Faculty();
    //     Faculty* l = (Faculty*)k;
    //     l->AddAdvisee((Student*)j);
    //     facultyDatabase.insert(k->id, k);
    // }
    //Create some test students and faculty

    Faculty f(&facultyIDs);
    // Faculty w(&facultyIDs);
    //
    // Student s(10,"Matt","Freshman","Music",f.id,4.0);

    // Student q(100,"Joe","Freshman","Music",f.id,4.0);
    // Student l;
    // Student c;
    //
    // //Add students to advisee
    f.AddAdvisee(1176343);
    // f.AddAdvisee(100);
    // w.AddAdvisee(&c);
    // w.AddAdvisee(&l);
    //
    // InsertedPerson addFaculty(&f, &facultyDatabase, &studentDatabase);
    // InsertedPerson addFaculty2(&w, &facultyDatabase, &studentDatabase, &facultyIDs);
    studentDatabase.printTree();


    removeAdvisor myAdvisor(studentDatabase.findKey(1176343), 8413845, &studentDatabase, &facultyDatabase, &facultyIDs);
    addAdvisor yourAdvisor(studentDatabase.findKey(1176343), 8413845, &studentDatabase, &facultyDatabase, &facultyIDs);

    myAdvisor.redoOperation();
    yourAdvisor.redoOperation();

    // Person *myP, int oID, BST<Person*>* aT, BST<Person*> *oT, DoublyLinkedList<int>* IDs

    cout << "\n\n\n\n\n" << endl;

    studentDatabase.printTree();


    // myS.serializeTree(studentDatabase, facultyDatabase);

    //studentDatabase.printTree();
    cout << "----------" << endl;
    //facultyDatabase.printTree();



    return 0;
}
