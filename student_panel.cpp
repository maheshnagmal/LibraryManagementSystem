#include "student_panel.h"
#include "ui_student_panel.h"
#include"search_book.h"
#include"student_prfile.h"
#include"book_transaction.h"
student_panel::student_panel(QWidget *parent,QString name,int id) :
    QMainWindow(parent),
    ui(new Ui::student_panel)
{
    ui->setupUi(this);
    user_name=name;
    borrow_id=id;
}

student_panel::~student_panel()
{
    delete ui;
}

void student_panel::on_pushButton_3_clicked()
{
    Search_Book=new search_Book(this);
    Search_Book->show();
}

void student_panel::on_profilr_button_clicked()
{
    profile=new student_prfile(this,user_name);
    profile->show();
}

void student_panel::on_pushButton_clicked()
{
    /*first_page *First_Page=new first_page(this);
    First_Page->show();*/
    this->close();
}

void student_panel::on_book_transaction_clicked()
{
    book_transaction *Book_Transaction=new book_transaction(this,"Student",borrow_id);
    Book_Transaction->show();
}
