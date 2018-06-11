#ifndef PET_MAIN_H
#define PET_MAIN_H

#include <QDialog>

namespace Ui {
class pet_main;
}

class pet_main : public QDialog
{
    Q_OBJECT

public:
    explicit pet_main(QWidget *parent = 0);
    ~pet_main();

private:
    Ui::pet_main *ui;
};

#endif // PET_MAIN_H
