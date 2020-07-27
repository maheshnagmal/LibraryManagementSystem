#include "first_page.h"
#include "ui_first_page.h"
#include"login.h"
first_page::first_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first_page)
{
    ui->setupUi(this);

}

first_page::~first_page()
{
    delete ui;
}

void first_page::on_librarian_login_clicked()
{

    Login *login=new Login(this,"librarian");
    login->show();
}

void first_page::on_staff_login_clicked()
{

    Login *login=new Login(this,"staff");
    login->show();
}

void first_page::on_student_login_clicked()
{

    Login *login=new Login(this,"student");
    login->show();
}
