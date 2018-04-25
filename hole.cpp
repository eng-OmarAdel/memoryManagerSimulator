#include "hole.h"

hole::hole()
{

}

double hole::getSize()
{
    return hSize;
}

double hole::getAddress()
{
    return hAddress;
}

void hole::setSize(double size)
{
    hSize=size;
}

void hole::setAddress(double address)
{
    hAddress=address;
}
