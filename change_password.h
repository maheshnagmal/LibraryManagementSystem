#ifndef CHANGE_PASSWORD_H
#define CHANGE_PASSWORD_H

#include <QMainWindow>

namespace Ui {
class change_password;
}

class change_password : public QMainWindow
{
    Q_OBJECT

public:
    explicit change_password(QWidget *parent = 0,QString type="",QString mailID="");
    QString memberType,emailID;
    void change_pass_stud();
    void change_pass_staff();
    ~change_password();

private slots:
    void on_change_password_2_clicked();

private:
    Ui::change_password *ui;
};

#endif // CHANGE_PASSWORD_H
