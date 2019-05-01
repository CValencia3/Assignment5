//TO DO
/*
1. Add backwards fuctionality to changing a student's advisor
(the change should be reflected in the advisor's list)
2. Assigning a random advisor in faculty delete

*/
#include <string>
#include <iostream>

#include "database.h"


int main(int argc, char const *argv[])
{
    Database myDatabase;
    myDatabase.addFaculty(515496, "Bill Nye", "Dan", "testing");

    myDatabase.addStudent(100,"Joe","Freshman","Music",515496,4.0);
    // myDatabase.undo();
    // myDatabase.redo();
    //
    // myDatabase.deleteStudent(100,"Joe","Freshman","Music",515496,4.0);
    // myDatabase.undo();


    // myDatabase.undo();

    myDatabase.addFaculty(8675309, "Joe Shmoe", "Regional Manager", "SCIENCE BITCH");
    // myDatabase.undo();
    // myDatabase.deleteFaculty(8675309, "Joe Shmoe", "Regional Manager", "SCIENCE BITCH");
    // myDatabase.replaceAdvisor(100, 8675309);
    myDatabase.replaceAdvisor(100, 8675309);
    cout << "\n\n\n\n\n\n\n\n" << endl;
    myDatabase.undo();

    return 0;
}
