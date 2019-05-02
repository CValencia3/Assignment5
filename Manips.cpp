#include "Manips.h"

// This parent class allows us to have a stack that will hold all of the
// differnt types of manipulations that we need

Manips::Manips()
{

}

Manips::Manips(Person aP) : affectedPerson(aP)
{

}
