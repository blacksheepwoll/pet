#include "select_pet.h"
#include "ui_select_pet.h"

Select_pet::Select_pet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Select_pet)
{
    ui->setupUi(this);
}

Select_pet::~Select_pet()
{
    delete ui;
}
