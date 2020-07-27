#ifndef STAFF_PROFILE_H
#define STAFF_PROFILE_H

#include <QMainWindow>
#include"change_password.h"
namespace Ui {
class staff_profile;
}

class staff_profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_profile(QWidget *parent = 0,QString="");
    QString u_name;
    ~staff_profile();

private slots:
    void on_change_pssword_clicked();

private:
    Ui::staff_profile *ui;
    change_password *Change_Password;
};

#endif // STAFF_PROFILE_H
