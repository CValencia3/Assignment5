#pragma once

#include <string>

#include "Person.h"

class Manips
{
public:
    Manips();
    Manips(Person affectedPerson);
    // virtual void undoOperation() = 0;
    // virtual void redoOperation() = 0;

    Person affectedPerson;
    int id;
private:
};
//1 = insert person
//2 = delete
//3 = delete advisor
//4 = add advisor
