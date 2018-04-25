#ifndef SIMWINDOW_H
#define SIMWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "global.h"

namespace Ui {
class simWindow;
}

class simWindow : public QDialog
{
    Q_OBJECT

public:
    explicit simWindow(QWidget *parent = 0);
    ~simWindow();

protected:
    void simWindow::paintEvent(QPaintEvent *event);

private slots:
    void on_backBTN_clicked();

private:
    Ui::simWindow *ui;
};

#endif // SIMWINDOW_H
