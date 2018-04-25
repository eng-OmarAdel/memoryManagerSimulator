#include "process.h"

process::process()
{

}

std::string process::getName()
{
    return pName;
}

double process::getSize()
{
    return pSize;
}

double process::getAddress()
{
    return pAddress;
}

void process::setName(std::string name)
{
    pName=name;
}

void process::setSize(double size)
{
    pSize=size;
}

void process::setAddress(double address)
{
    pAddress=address;
}
