#pragma once

#include <string>

#include "Manips.h"

class StudDel: public Manips
{
public:
    StudDel();
    StudDel(int id, string name, string department, string level, int advisor);
    void deleteManip();
    void inverse();

    string level;
    int advisor;
private:
};

StudDel::StudDel(int id, string n, string dp, string lvl, int ad)
{
    ID = id;
    name = n;
    department = dp;
    level = lvl;
    advisor = ad;
}

void StudDel::deleteManip()
{

}

void StudDel::inverse()
{

}
