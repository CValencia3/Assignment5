#pragma once

#include <string>

#include "Person.h"

class Manips
{
public:
    Manips();
    Manips(Person affectedPerson);
    virtual void undoOperation();
    virtual void redoOperation();

    Person affectedPerson;
private:
};
