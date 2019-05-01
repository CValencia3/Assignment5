//TO DO
/*
1. Add backwards fuctionality to changing a student's advisor
(the change should be reflected in the advisor's list)
2. Assigning a random advisor in faculty delete

*/
#include <string>
#include <iostream>

#include "database.h"

void askUserInput(bool &r, Database &mD);
void processUserInput(bool &r, int userInput, Database &mD);
void printStudentInformation(Database &mD);
void printStudentAdvisor(Database &mD);
void printFacultyInformation(Database &mD);
void printFacultyAdvisees(Database &mD);
bool isValidID(string tempString);
void printOptions();
void addNewStudent(Database &myDatabase);


int main(int argc, char const *argv[])
{
    Database myDatabase;
    bool running = true;

    // Introduction
    cout << "Welcome to our student database project." << endl;

    askUserInput(running, myDatabase);

    // while(runing)
    // {
    //    askUserInput(running, myDatabase);
    // }
    /*
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
    */

    return 0;
}

void askUserInput(bool &running, Database &myDatabase)
{
    string tempString = "";
    int input = 0;

    printOptions();

    while(true)
    {
        getline(cin, tempString);

        try
        {
            for(int i = 0; i < tempString.length(); ++i)
                if ((tempString[i]>'9')||(tempString[i]<'0'))
                    throw invalid_argument("That input contained a non-numeric character");

            input = stoi(tempString);

            if(input>14)
                throw invalid_argument("That was not one of the options on the list");
            break;
        }
        catch(invalid_argument)
        {
            cout << "That was not a valid argument. Please try again." << endl;
        }
    }

    processUserInput(running, input, myDatabase);
}

void processUserInput(bool &r, int userInput, Database &myDatabase)
{
    switch (userInput)
    {
        case 1:
        {
            // cout << 1 << endl;
            myDatabase.printAllStudents();
            break;
        }
        case 2:
        {
            // cout << 2 << endl;
            printStudentInformation(myDatabase);
            break;
        }
        case 3:
        {
            // cout << 3 << endl;
            printFacultyInformation(myDatabase);
            break;
        }
        case 4:
        {
            printStudentAdvisor(myDatabase);
            // cout << 4 << endl;
            break;
        }
        case 5:
        {
            printFacultyAdvisees(myDatabase);
            // cout << 5 << endl;
            break;
        }
        case 6:
        {

            // cout << 6 << endl;
            break;
        }
        case 7:
        {

            // cout << 7 << endl;
            break;
        }
        case 8:
        {

            // cout << 8 << endl;
            break;
        }
        case 9:
        {

            // cout << 9 << endl;
            break;
        }
        case 10:
        {

            // cout << 10 << endl;
            break;
        }
        case 11:
        {

            // cout << 11 << endl;
            break;
        }
        case 12:
        {

            // cout << 12 << endl;
            break;
        }
        case 13:
        {

            // cout << 13 << endl;
            break;
        }
        case 14:
        {

            // cout << 14 << endl;
            break;
        }
    }
}

void printStudentInformation(Database &myDatabase)
{
    cout << "Please enter a student ID number:" << endl;

    string userInput = "";
    int userNum = 0;

    while(true)
    {
        getline(cin, userInput);
        if(isValidID(userInput))
            break;

        cout << "That was an invalid ID number. Please try again" << endl;
    }

    userNum = stoi(userInput);
    if(myDatabase.containsStudentID(userNum))
        myDatabase.printStudentInformation(userNum);
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

bool isValidID(string tempString)
{
    int input = 0;
    try
    {
        for(int i = 0; i < tempString.length(); ++i)
            if ((tempString[i]>'9')||(tempString[i]<'0'))
                throw invalid_argument("That input contained a non-numeric character");

        input = stoi(tempString);
        return true;
    }
    catch(invalid_argument)
    {
        return false;
    }
}

void printOptions()
{
    cout << "Please select a number coninue:\n"
         << "  1) Print student information (id # asc)\n"
         << "  2) Find/display student given their id\n"
         << "  3) Find/display faculty given their id\n"
         << "  4) Given a student id, print their advisor\n"
         << "  5) Given a faculty id, print his/her advisees\n"
         << "  6) Add a new student\n"
         << "  7) Delete a student given the id\n"
         << "  8) Add a new faculty member\n"
         << "  9) Add a new faculty member\n"
         << "  10) Delete a faculty member given the id\n"
         << "  11) Change a student's advisor given the student id and the new faculty id\n"
         << "  12) Remove an advisee from a faculty member given the ids\n"
         << "  13) Rollback\n"
         << "  14) Exit" << endl;
}

void printFacultyInformation(Database &myDatabase)
{
    cout << "Please enter a faculty ID number:" << endl;

    string userInput = "";
    int userNum = 0;

    while(true)
    {
        getline(cin, userInput);
        if(isValidID(userInput))
            break;

        cout << "That was an invalid ID number. Please try again" << endl;
    }

    userNum = stoi(userInput);
    if(myDatabase.containsFacultyID(userNum))
        myDatabase.printFacultyInformation(userNum);
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

void printStudentAdvisor(Database &myDatabase)
{
    cout << "Please enter a student ID number:" << endl;

    string userInput = "";
    int userNum = 0;

    while(true)
    {
        getline(cin, userInput);
        if(isValidID(userInput))
            break;

        cout << "That was an invalid ID number. Please try again" << endl;
    }

    userNum = stoi(userInput);
    if(myDatabase.containsStudentID(userNum))
    {
        int advisorID = ((Student*)myDatabase.studentDatabase->findKey(userNum))->advisorID;
        myDatabase.printFacultyInformation(advisorID);
    }
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

void printFacultyAdvisees(Database &myDatabase)
{
    cout << "Please enter a faculty ID number:" << endl;

    string userInput = "";
    int userNum = 0;

    while(true)
    {
        getline(cin, userInput);
        if(isValidID(userInput))
            break;

        cout << "That was an invalid ID number. Please try again" << endl;
    }

    userNum = stoi(userInput);
    if(myDatabase.containsFacultyID(userNum))
    {
        ((Faculty*)myDatabase.facultyDatabase->findKey(userNum))->printAdvisees(myDatabase.studentDatabase);
    }
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

void addNewStudent(Database &myDatabase)
{

}
