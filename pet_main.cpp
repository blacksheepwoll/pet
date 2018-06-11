#include "pet_main.h"
#include "ui_pet_main.h"

pet_main::pet_main(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pet_main)
{
    ui->setupUi(this);
}

pet_main::~pet_main()
{
    delete ui;
}
