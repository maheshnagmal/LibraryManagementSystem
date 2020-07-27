#include "delete_book.h"
#include "ui_delete_book.h"
#include"add_book.h"
#include<QMessageBox>
#include<iostream>
Delete_Book::Delete_Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_Book)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
    ui->comboBox->addItem("Select");
    ui->comboBox->addItem("Fully damaged");
    ui->comboBox->addItem("Out of Syllabus");
    ui->comboBox->addItem("Missing");
}

Delete_Book::~Delete_Book()
{
    delete ui;
}

void Delete_Book::on_pushButton_clicked()
{
    int book_id=ui->lineEdit->text().toInt();
    int flag=0;
    add_book book;
    Delete_Book d_book;
    std::ofstream out_d;
    out_d.open("Deleted_Book.txt",std::ofstream::out | std::ofstream::app);
    std::ifstream in;
    std::ofstream out;
    in.open("book.txt",std::ifstream::in | std::ifstream::app);
    out.open("book_temp.txt",std::ofstream::out);
    while(!in.eof())
    {
        in>>book;
        int b_id=book.book_id;
        if(b_id==book_id){
            d_book.book_id=book.book_id;
            d_book.book_name=book.book_name;
            d_book.book_author=book.author;
            d_book.book_edition=book.edition;
            d_book.reason=ui->comboBox->currentText().toStdString();
            std::replace(d_book.reason.begin(),d_book.reason.end(),' ','_');
            flag=1;
        }
    }
    in.close();
    in.open("book.txt",std::ifstream::in | std::ifstream::app);
    if(flag==1)
    {
        in>>book;
        while(!in.eof()) {
            int b_id=book.book_id;
            if(b_id!=book_id){
                out<<book;
            }
            in>>book;
        }
        in.close();
        out.close();
        remove("book.txt");
        rename("book_temp.txt" , "book.txt");
        QMessageBox::information(this,"Sucess","Book record deleted Sucessfully!!");
        ui->lineEdit->setText("");
       }
       else if(flag==0){
           QMessageBox::information(this,"Fail","Given Book Id is Not available in System\nPlease Enter Correct Book ID!!!");
       }
    out_d<<d_book;
    out_d.close();
    ui->comboBox->setCurrentIndex(0);
}
