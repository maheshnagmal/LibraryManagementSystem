#ifndef STUDENT_PRFILE_H
#define STUDENT_PRFILE_H

#include <QMainWindow>
#include"change_password.h"
namespace Ui {
class student_prfile;
}

class student_prfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit student_prfile(QWidget *parent = 0,QString name="");
    ~student_prfile();
    QString u_name;

private slots:
    void on_chang_password_clicked();

private:
    Ui::student_prfile *ui;
    change_password *Change_Password;
};

#endif // STUDENT_PRFILE_H
