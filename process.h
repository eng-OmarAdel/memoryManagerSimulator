#ifndef PROCESS_H
#define PROCESS_H
#include <string>

class process
{
public:
    process();
    std::string getName();
    double getSize();
    double getAddress();
    void setName(std::string name);
    void setSize(double size);
    void setAddress(double address);
private:
    std::string pName;
    double pSize;
    double pAddress;
};

#endif // PROCESS_H
