#ifndef SELECT_PET_H
#define SELECT_PET_H

#include <QDialog>

namespace Ui {
class Select_pet;
}

class Select_pet : public QDialog
{
    Q_OBJECT

public:
    explicit Select_pet(QWidget *parent = 0);
    ~Select_pet();

private:
    Ui::Select_pet *ui;
};

#endif // SELECT_PET_H
