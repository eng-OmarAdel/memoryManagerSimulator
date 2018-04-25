#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include "global.h"
#include "simwindow.h"
#include "error.h"
namespace Ui {
class mainWindow;
}

class mainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private slots:
    void on_addHoleBTN_clicked();

    void on_deleteHoleBTN_clicked();

    void on_clearHoleBTN_clicked();

    void on_addProcessBTN_clicked();

    void on_deleteProcessBTN_clicked();

    void on_clearProcessBTN_clicked();

    void on_memorySizeLE_textChanged(const QString &arg1);

    void on_exitBTN_clicked();

    void on_startBTN_clicked();

private:
    Ui::mainWindow *ui;
    QStandardItemModel *model;
};

#endif // MAINWINDOW_H
