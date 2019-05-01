//TO DO
/*
Need to go back and clean up this code if there's time. There's a lot of copy/paste code here due to time constraints

*/
#include <string>
#include <iostream>

#include "database.h"

// These are all functions that deal with user input
//------------------------------------------------------------//
// Asks the user what option they want to go with. Takes a bool that controls
// whether the program is running
void askUserInput(bool &r, Database &mD);

// Processes the user input and decides what function to execute
void processUserInput(bool &r, int userInput, Database &mD);

// Asks for an id number and prints the student's information
void printStudentInformation(Database &mD);

// Asks for an id number and prints the information of the student's advisor
void printStudentAdvisor(Database &mD);

// Asks for an id number and prints the faculty's's information
void printFacultyInformation(Database &mD);

// Asks for an id number and prints the students being advised by this faculty member
void printFacultyAdvisees(Database &mD);

// Takes in a string and checks to see if it's a valid id number
bool isValidID(string tempString);

// Prints the menu of options
void printOptions();

// Asks a user for information and uses that to create a new student
void addNewStudent(Database &myDatabase);

// Asks for ID and deletes the student from the database
void deleteStudent(Database &myDatabase);

// Asks for ID and deletes faculty from the database
void deleteFaculty(Database &myDatabase);

// Asks for information and uses that to create a new student
void addNewFaculty(Database &myDatabase);

// Asks for student and faculty ids, and then changes the student's advisor to the given faculty
void changeStudentAdvisor(Database &myDatabase);

// Asks for student and faculty ids, and then changes the student's advisor to to a random faculty member
void removeStudentFromAdvisor(Database &myDatabase);

// Asks the user for input and parses it into an id
int parseUserID(string idType);
//------------------------------------------------------------//

int main(int argc, char const *argv[])
{
    Database myDatabase;
    bool running = true;

    // Introduction
    cout << "Welcome to our student database project." << endl;

    while(running)
    {
       askUserInput(running, myDatabase);
    }
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

// Asks the user what option they want to go with. Takes a bool that controls
// whether the program is running
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

            if(input>15)
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

// Processes the user input and decides what function to execute
void processUserInput(bool &r, int userInput, Database &myDatabase)
{
    switch (userInput)
    {
        case 1:
            myDatabase.studentDatabase->printTree();
            break;
        case 2:
            myDatabase.facultyDatabase->printTree();
            break;
        case 3:
            printStudentInformation(myDatabase);
            break;
        case 4:
            printFacultyInformation(myDatabase);
            break;
        case 5:
            printStudentAdvisor(myDatabase);
            break;
        case 6:
            printFacultyAdvisees(myDatabase);
            break;
        case 7:
            if(myDatabase.facultyIDs->getSize() > 0)
                addNewStudent(myDatabase);
            else
                cout << "Sorry, but you need at least one faculty member to add students" << endl;
            break;
        case 8:
            deleteStudent(myDatabase);
            break;
        case 9:
            addNewFaculty(myDatabase);
            break;
        case 10:
            deleteFaculty(myDatabase);
            break;
        case 11:
            changeStudentAdvisor(myDatabase);
            break;
        case 12:
            removeStudentFromAdvisor(myDatabase);
            break;
        case 13:
            myDatabase.undo();
            break;
        case 14:
            myDatabase.redo();
            break;
        case 15:
            myDatabase.exit();
            r = false;
            break;
    }
}

// Asks for an id number and prints the student's information
void printStudentInformation(Database &myDatabase)
{
    int userNum = parseUserID("student");

    if(myDatabase.containsStudentID(userNum))
        myDatabase.printStudentInformation(userNum);
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Takes in a string and checks to see if it's a valid id number
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

// Prints the menu of options
void printOptions()
{
    cout << "Please select a number coninue:\n"
         << "  1) Print student information (id # asc)\n"
         << "  2) Print faculty information (id # asc)\n"
         << "  3) Find/display student given their id\n"
         << "  4) Find/display faculty given their id\n"
         << "  5) Given a student id, print their advisor\n"
         << "  6) Given a faculty id, print his/her advisees\n"
         << "  7) Add a new student\n"
         << "  8) Delete a student given the id\n"
         << "  9) Add a new faculty member\n"
         << "  10) Delete a faculty member given the id\n"
         << "  11) Change a student's advisor given the student id and the new faculty id\n"
         << "  12) Remove an advisee from a faculty member given the ids\n"
         << "  13) Rollback\n"
         << "  14) Rollforward\n"
         << "  15) Exit" << endl;
}

// Asks for an id number and prints the faculty's's information
void printFacultyInformation(Database &myDatabase)
{
    int userNum = parseUserID("faculty");

    if(myDatabase.containsFacultyID(userNum))
        myDatabase.printFacultyInformation(userNum);
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Asks for an id number and prints the information of the student's advisor
void printStudentAdvisor(Database &myDatabase)
{
    int userNum = parseUserID("student");

    if(myDatabase.containsStudentID(userNum))
    {
        int advisorID = ((Student*)myDatabase.studentDatabase->findKey(userNum))->advisorID;
        myDatabase.printFacultyInformation(advisorID);
    }
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Asks for an id number and prints the students being advised by this faculty member
void printFacultyAdvisees(Database &myDatabase)
{
    int userNum = parseUserID("faculty");
    if(myDatabase.containsFacultyID(userNum))
    {
        ((Faculty*)myDatabase.facultyDatabase->findKey(userNum))->printAdvisees(myDatabase.studentDatabase);
    }
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Asks a user for information and uses that to create a new student
void addNewStudent(Database &myDatabase)
{
    double gpa = 0;
    string name, level, major;
    name = level = major = "";

    int id, facID;
    id = facID = 0;

    cout << "Please enter the student's name:" << endl;
    getline(cin, name);
    cout << "Please enter their class standing:" << endl;
    getline(cin, level);
    cout << "Please enter their major:" << endl;
    getline(cin, major);
    cout << "Please enter their GPA" << endl;

    string tempString = "";
    while(true)
    {
        try
        {
            getline(cin, tempString);

            for(int i = 0; i < tempString.length(); ++i)
                if (((tempString[i]>'9')||(tempString[i]<'0'))&&(tempString[i] != '.'))
                    throw invalid_argument("That input contained a non-numeric character");

            gpa = stod(tempString);

            if ((gpa>5)||(gpa<0))
                throw invalid_argument("Invalid GPA");
            break;
        }
        catch(invalid_argument)
        {
            cout << "That was an invalid GPA" << endl;
        }
    }

    do { id = rand()%999999; } while(myDatabase.containsStudentID(id) || myDatabase.containsFacultyID(id));

    int numberOfFaculty = myDatabase.facultyIDs->getSize();
    facID = myDatabase.facultyIDs->index(rand()%numberOfFaculty);

    myDatabase.addStudent(id, name, level, major, facID, gpa);
}

// Asks for ID and deletes the student from the database
void deleteStudent(Database &myDatabase)
{
    int userNum = parseUserID("student");
    if(myDatabase.containsStudentID(userNum))
    {
        Student* tempStudent = (Student*)myDatabase.studentDatabase->findKey(userNum);

        myDatabase.deleteStudent(tempStudent->id,
                                 tempStudent->name,
                                 tempStudent->level,
                                 tempStudent->major,
                                 tempStudent->advisorID,
                                 tempStudent->GPA);
    }

    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Asks for information and uses that to create a new student
void addNewFaculty(Database &myDatabase)
{
    string name, level, department;
    name = level = department = "";

    int id;
    id = 0;

    cout << "Please enter the faculty's name:" << endl;
    getline(cin, name);
    cout << "Please enter their level of seniority:" << endl;
    getline(cin, level);
    cout << "Please enter their department:" << endl;
    getline(cin, department);


    do { id = rand()%999999; } while(myDatabase.containsStudentID(id) || myDatabase.containsFacultyID(id));
    myDatabase.addFaculty(id, name, level, department);
}

// Asks for ID and deletes faculty from the database
void deleteFaculty(Database &myDatabase)
{
    int userNum = parseUserID("faculty");
    if(myDatabase.containsFacultyID(userNum))
    {
        Faculty* tempFaculty = (Faculty*)myDatabase.facultyDatabase->findKey(userNum);

        myDatabase.deleteFaculty(tempFaculty->id,
                                 tempFaculty->name,
                                 tempFaculty->level,
                                 tempFaculty->department);
    }
    else
        cout << "That id number isn't in the database. Please try again." << endl;
    cout << endl;
}

// Asks for student and faculty ids, and then changes the student's advisor to the given faculty
void changeStudentAdvisor(Database &myDatabase)
{
    int studentNumber = parseUserID("student");
    int facultyNumber = parseUserID("faculty");

    myDatabase.replaceAdvisor(studentNumber, facultyNumber);
}

// Asks for student and faculty ids, and then changes the student's advisor to to a random faculty member
void removeStudentFromAdvisor(Database &myDatabase)
{
    int facultyNumber = parseUserID("faculty");
    int studentNumber = parseUserID("student");

    myDatabase.switchAdvisor(facultyNumber, studentNumber);
}

// Asks the user for input and parses it into an id
int parseUserID(string idType)
{
    cout << "Please enter a " << idType << " ID number:" << endl;

    string userInput = "";
    int userNum = 0;

    while(true)
    {
        getline(cin, userInput);
        if(isValidID(userInput))
            return stoi(userInput);

        cout << "That was an invalid ID number. Please try again" << endl;
    }
}
