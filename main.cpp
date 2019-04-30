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

    myDatabase.addStudent(100,"Joe","Freshman","Music",1000,4.0);
    myDatabase.addFaculty(8675309, "Joe Shmoe", "Regional Manager", "SCIENCE BITCH");
    myDatabase.deleteStudent(100);
    myDatabase.deleteFaculty(8675309);

    return 0;
}
