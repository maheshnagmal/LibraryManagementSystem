#ifndef FIRST_PAGE_H
#define FIRST_PAGE_H

#include <QMainWindow>
#include "login.h"
namespace Ui {
class first_page;
}

class first_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit first_page(QWidget *parent = 0);
    ~first_page();

private slots:
    void on_librarian_login_clicked();

    void on_staff_login_clicked();

    void on_student_login_clicked();

private:
    Ui::first_page *ui;
    //Login *login;
};

#endif // FIRST_PAGE_H
