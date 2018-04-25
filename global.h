#ifndef GLOBAL_H
#define GLOBAL_H
#include <vector>
#include "process.h"
#include "hole.h"

extern std::vector<process> processes;
extern std::vector<hole> holes;
extern double memSize;
extern std::string errorStr;

#endif // GLOBAL_H
