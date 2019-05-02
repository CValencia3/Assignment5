#pragma once

#include <string>

#include "Person.h"

// This parent class allows us to have a stack that will hold all of the
// differnt types of manipulations that we need

class Manips
{
public:
    Manips();
    Manips(Person affectedPerson);

    Person affectedPerson;
    int id;
};
//1 = insert person
//2 = delete
//3 = delete advisor
//4 = add advisor
