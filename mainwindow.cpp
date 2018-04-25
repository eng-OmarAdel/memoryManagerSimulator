#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_addHoleBTN_clicked()
{
    ui->holeTable->setRowCount(ui->holeTable->rowCount()+1);
    holes.push_back(hole());
}

void mainWindow::on_deleteHoleBTN_clicked()
{
    ui->holeTable->removeRow(ui->holeTable->currentRow());
    holes.erase(holes.begin() + ui->holeTable->currentRow());
}

void mainWindow::on_clearHoleBTN_clicked()
{
    ui->holeTable->setRowCount(0);
    holes.clear();
}

void mainWindow::on_addProcessBTN_clicked()
{
    ui->processTable->setRowCount(ui->processTable->rowCount()+1);
    processes.push_back(process());
}

void mainWindow::on_deleteProcessBTN_clicked()
{
    ui->processTable->removeRow(ui->processTable->currentRow());
    processes.erase(processes.begin() + ui->processTable->currentRow());
}

void mainWindow::on_clearProcessBTN_clicked()
{
    ui->processTable->setRowCount(0);
    processes.clear();
}

void mainWindow::on_memorySizeLE_textChanged(const QString &arg1)
{
    ui->processTable->setEnabled(true);
    ui->holeTable->setEnabled(true);
    ui->addHoleBTN->setEnabled(true);
    ui->addProcessBTN->setEnabled(true);
    ui->deleteHoleBTN->setEnabled(true);
    ui->deleteProcessBTN->setEnabled(true);
    ui->startBTN->setEnabled(true);
}

void mainWindow::on_exitBTN_clicked()
{
    exit(0);
}

void mainWindow::on_startBTN_clicked()
{
    memSize=ui->memorySizeLE->text().toDouble();
    for(int i=0;i<holes.size();i++)
    {
        double address,size;
        address = ui->holeTable->item(i,0)->text().toDouble();
        size = ui->holeTable->item(i,1)->text().toDouble();
        holes[i].setAddress(address);
        holes[i].setSize(size);
    }
    for(int i=0;i<processes.size();i++)
    {
        double size;
        size = ui->processTable->item(i,0)->text().toDouble();
        processes[i].setName("P"+std::to_string(i+1));
        processes[i].setSize(size);
    }
    if(ui->FFRB->isChecked())
    {
        for(int i=0;i<processes.size();i++)
        {
            int flag=1;
            for(int j=0;j<holes.size();j++)
            {
                if(holes[j].getSize()>=processes[i].getSize())
                {
                    processes[i].setAddress(holes[j].getAddress());
                    holes[j].setAddress(holes[j].getAddress() + processes[i].getSize());
                    holes[j].setSize(holes[j].getSize()-processes[i].getSize());
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
                errorStr="P"+std::to_string(i+1)+" doesn't fit in any of the available holes at time of insertion";
                error errorWindow;
                errorWindow.setModal(true);
                errorWindow.exec();
                return;
            }
        }
    }
    else if(ui->BFRB->isChecked())
    {
        for(int i=0;i<processes.size();i++)
        {
            int flag=1;
            double currentHoleSize=memSize;
            int currentHoleIndex;
            for(int j=0;j<holes.size();j++)
            {
                //if i found a suitable size i will put the process in it but i will not edit the hole
                //if i found a tighter spot i will replace the process there.
                //when i finally find the right spot i will only update this hole.
                if(holes[j].getSize()>=processes[i].getSize() && (holes[j].getSize() < currentHoleSize))
                {
                    processes[i].setAddress(holes[j].getAddress());
                    currentHoleSize=holes[j].getSize();
                    currentHoleIndex=j;
                    flag=0;
                }
            }
            if(flag)
            {
                errorStr="P"+std::to_string(i+1)+" doesn't fit in any of the available holes at time of insertion";
                error errorWindow;
                errorWindow.setModal(true);
                errorWindow.exec();
                return;
            }
            else
            {
                holes[currentHoleIndex].setAddress(holes[currentHoleIndex].getAddress() + processes[i].getSize());
                holes[currentHoleIndex].setSize(holes[currentHoleIndex].getSize()-processes[i].getSize());
            }
        }
    }
    simWindow window;
    window.setModal(true);
    window.exec();
}
