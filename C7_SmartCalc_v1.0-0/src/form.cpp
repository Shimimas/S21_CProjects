#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(-1000, 1000);
}

Form::~Form()
{
    delete ui;
}

void Form::slot()
{
    ui->widget->xAxis->setRange(-1000, 1000);
}
