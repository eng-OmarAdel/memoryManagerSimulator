#include "mainwindow.h"
#include <QApplication>
#include "global.h"

std::vector<process> processes;
std::vector<hole> holes;
double memSize;
std::string errorStr;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();

    return a.exec();
}
