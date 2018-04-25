#ifndef HOLE_H
#define HOLE_H


class hole
{
public:
    hole();
    double getSize();
    double getAddress();
    void setSize(double size);
    void setAddress(double address);
private:
    double hSize;
    double hAddress;
};

#endif // HOLE_H
