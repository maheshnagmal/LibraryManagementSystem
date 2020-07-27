#include "stock_verification.h"
#include "ui_stock_verification.h"
#include "add_book.h"
#include "delete_book.h"
#include"ids.h"
#include<QMessageBox>
stock_verification::stock_verification(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stock_verification)
{
    ui->setupUi(this);
    add_book book;
    Delete_Book d_book;
    std::ifstream b_in,d_in,obj;
    b_in.open("book.txt",std::ifstream::in);
    if(b_in.fail())
    {
        QMessageBox::warning(this,"Error","Books not Available");
        ui->lineEdit_available_book->setText("0");
        ui->lineEdit_issued_book->setText("0");
        b_in.close();

    }
    else    {
        b_in>>book;
        while(!b_in.eof()){
            if(book.status=="Available"){
                available_books=available_books+1;
            }
            else if(book.status=="Issued"){
                issued_books=issued_books+1;
            }
         b_in>>book;
         }
        b_in.close();
    }
    d_in.open("Deleted_Book.txt",std::ifstream::in);
    if(d_in.fail())
    {
        QMessageBox::warning(this,"Error","No Deleted books Available");
        ui->lineEdit_deleted_book->setText("0");
    }
    else    {
        d_in>>d_book;
        while(!d_in.eof()){
           deleted_books=deleted_books+1;
            d_in>>d_book;
        }
       d_in.close();
   }
   IDs ids_obj;
   obj.open("IDs.txt",std::ifstream::in);
   obj>>ids_obj;
   ui->lineEdit_total_book->setText(QString::number((ids_obj.book_id-1)));
   ui->lineEdit_available_book->setText(QString::number(available_books));
   ui->lineEdit_issued_book->setText(QString::number(issued_books));
   ui->lineEdit_deleted_book->setText(QString::number(deleted_books));
    ui->lineEdit_total_book->setReadOnly(true);
    ui->lineEdit_available_book->setReadOnly(true);
    ui->lineEdit_deleted_book->setReadOnly(true);
    ui->lineEdit_issued_book->setReadOnly(true);
    obj.close();
    if((ids_obj.book_id-1)==(available_books+deleted_books+issued_books))
    {
        ui->label_status->setText("Stock Verified");
    }
    else
    {
        ui->label_status->setText("Something Wrong!!!\nSome Books Missing");
    }
}
stock_verification::~stock_verification()
{
    delete ui;
}
