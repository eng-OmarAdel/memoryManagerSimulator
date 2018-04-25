#include "simwindow.h"
#include "ui_simwindow.h"

simWindow::simWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simWindow)
{
    ui->setupUi(this);
}

simWindow::~simWindow()
{
    delete ui;
}

void simWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect;
    QPoint vertex(50,30);
    rect.setTopLeft(vertex);

    QRect bgndR;
    bgndR.setTopLeft(vertex);
    bgndR.setSize(QSize(190 , 400));
    QBrush bgndB(Qt::DiagCrossPattern);
    painter.fillRect(bgndR,bgndB);
    for(int i=0;i<=memSize;i+=(50*memSize/1000))
    {
        QPoint addressPoint(vertex);
        addressPoint.setX(addressPoint.x()-40);
        addressPoint.setY(addressPoint.y() + 4 + i*400/memSize);
        QString addressText(QString::number(i));
        painter.drawText(addressPoint,addressText);
    }
    for(int i=0;i<processes.size();i++)
    {
        double scale = 400 / memSize;
        double h = processes[i].getSize()*scale ;
        vertex.setY(30 + processes[i].getAddress() * scale );
        rect.setTopLeft(vertex);
        rect.setSize(QSize(190 , h));
        QBrush brush(QColor(102,153,153));
        painter.fillRect(rect,brush);
        painter.drawRect(rect);


        QString text(" P" + QString::number(i+1));
        painter.drawText(rect,text);

        QPoint addressPoint(rect.topRight());
        addressPoint.setX(addressPoint.x()+20);
        addressPoint.setY(addressPoint.y()+4);
        QString addressText(QString::number(processes[i].getAddress()));
        painter.drawText(addressPoint,addressText);


    }
    for(int i=0;i<holes.size();i++)
    {
        if(holes[i].getSize()>0)
        {
            double scale = 400/ memSize;
            double h = holes[i].getSize()*scale ;
            vertex.setY(30 + holes[i].getAddress() * scale );
            rect.setTopLeft(vertex);
            rect.setSize(QSize(190 , h));
            QBrush brush(QColor(254,254,250));
            painter.fillRect(rect,brush);
            painter.drawRect(rect);


            QString text(" H" + QString::number(i+1));
            painter.drawText(rect,text);

            QPoint addressPoint(rect.topRight());
            addressPoint.setX(addressPoint.x()+20);
            addressPoint.setY(addressPoint.y()+4);
            QString addressText(QString::number(holes[i].getAddress()));
            painter.drawText(addressPoint,addressText);

        }
    }
}

void simWindow::on_backBTN_clicked()
{
    accept();
}
