#pragma once

#include <string>

class testClass
{
public:
    testClass();
    testClass(int i);

    bool operator==(const testClass& otherNum);
    bool operator<=(const testClass& otherNum);
    bool operator>=(const testClass& otherNum);
    bool operator!=(const testClass& otherNum);
private:
    int myVal;
};

testClass::testClass()
{

}

testClass::testClass(int i)
{
    myVal = i;
}

bool testClass::operator==(const testClass& otherNum)
{
    return (this->myVal == otherNum.myVal);
}

bool testClass::operator<=(const testClass& otherNum)
{
    return (this->myVal <= otherNum.myVal);
}

bool testClass::operator>=(const testClass& otherNum)
{
    return (this->myVal <= otherNum.myVal);
}

bool testClass::operator!=(const testClass& otherNum)
{
    return (this->myVal != otherNum.myVal);
}
