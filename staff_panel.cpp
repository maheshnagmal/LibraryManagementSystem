#include "staff_panel.h"
#include "ui_staff_panel.h"
#include"staff_profile.h"
#include"search_book.h"
#include"first_page.h"
#include"book_transaction.h"
staff_panel::staff_panel(QWidget *parent,QString name,int id) :
    QMainWindow(parent),
    ui(new Ui::staff_panel)
{
    ui->setupUi(this);
    borrow_id=id;
    u_name=name;
}

staff_panel::~staff_panel()
{
    delete ui;
}

void staff_panel::on_pushButton_clicked()
{
    Staff_Profile=new staff_profile(this,u_name);
    Staff_Profile->show();
}

void staff_panel::on_pushButton_4_clicked()
{
    /*first_page *First_Page=new first_page(this);
    First_Page->show();*/
    this->close();
}

void staff_panel::on_search_book_clicked()
{
    Search_Book=new search_Book(this);
    Search_Book->show();
}
void staff_panel::on_book_transaction_clicked()
{
    book_transaction  *Book_Transaction=new book_transaction(this,"Staff",borrow_id);
    Book_Transaction->show();
}
