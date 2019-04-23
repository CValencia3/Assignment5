#pragma once

#include <string>

#include "Person.h"

class Manips
{
public:
    Manips();
    Manips(Person affectedPerson);
    virtual void inverse();

    Person affectedPerson;
private:
};

Manips::Manips()
{

}

Manips::Manips(Person aP) : affectedPerson(aP)
{

}

void Manips::inverse()
{

}
