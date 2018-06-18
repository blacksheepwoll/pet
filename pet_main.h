#ifndef PET_MAIN_H
#define PET_MAIN_H

#include <QDialog>
#include <QSystemTrayIcon>
#include <QWidget>

namespace Ui {
class pet_main;
}

class pet_main : public QDialog
{
    Q_OBJECT

public:
    explicit pet_main(QWidget *parent = 0);
    QSystemTrayIcon *myTrayIcon;
    QMovie *mgif_happy;
    QMovie *mgif_eat;
    QMovie *mgif_play;
    QMovie *mgif_rest;
    QMovie *mgif_sport1;
    QMovie *mgif_work;
    QMovie *mgif_sport3;
    QMovie *mgif_angry;
    ~pet_main();

private slots:
    void on_button_exit_clicked();

    void on_button_return_clicked();

    void on_button_play_clicked();

    void on_button_work_clicked();

    void on_button_eat_clicked();

    void on_button_sport_clicked();

    void on_button_sleep_clicked();

    void on_button_musci_clicked();

    void activated(QSystemTrayIcon::ActivationReason reason);
private:
    QWidget *w;
    int state;
    int happiness;
    int health;
    int hungry;
    int meal;
    void update_lineexit();
    void changegif(QMovie *m);
    int judge();
    int set(int a,int b,int c);
    void setall(int happy,int heal,int hung);
    void c_happiness(int n);
    void c_health(int n);
    void c_hungry(int n);

    Ui::pet_main *ui;
};

#endif // PET_MAIN_H
