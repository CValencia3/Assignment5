#include "Manips.h"

// Need this to prevent things from being defined twice

Manips::Manips()
{
    cout << "HERE" << endl;
}

Manips::Manips(Person aP) : affectedPerson(aP)
{

}
