#include "error.h"
#include "ui_error.h"

error::error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::error)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    ui->label->setText(QString::fromStdString(errorStr));
}

error::~error()
{
    delete ui;
}

void error::on_buttonBox_accepted()
{
}

void error::on_buttonBox_rejected()
{
}
