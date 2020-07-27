#include "add_book.h"
#include "ui_add_book.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QValidator>
#include"ids.h"
#include<QFile>
#include<ostream>
#include<QTextStream>
#include<fstream>
#include<iostream>
#include<QString>
#include<QRegularExpression>
#include<QRegularExpressionValidator>
add_book::add_book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_book)
{
    ui->setupUi(this);
    ui->department->addItem("Select");
    ui->department->addItem("General Science and Engineering");
    ui->department->addItem("Computer Science and Engineering");
    ui->department->addItem("Electrical and Telicommunication Engineering");
    ui->department->addItem("Mechnical Engineering");
    ui->department->addItem("Civil Engineering");

    ui->book_releas_year->addItem("Select");
    for(int i=1998;i<2019;i++)
    {
        ui->book_releas_year->addItem(QString::number(i));
    }
    ui->book_format->addItem("Select");
    ui->book_format->addItem("CD");
    ui->book_format->addItem("E-Book");
    ui->book_format->addItem("Printed");

    ui->type_of_book->addItem("select");
    ui->type_of_book->addItem("Reference");
    ui->type_of_book->addItem("Text Book");

    ui->book_edition->addItem("select");
    for (int i=1;i<10;i++)
    {
        ui->book_edition->addItem(QString::number(i));
    }
    IDs id;
    int b_id=id.getID("Book");
    ui->book_id->setText(QString::number(b_id));
    ui->book_id->setReadOnly(true);
}
add_book::~add_book()
{
    delete ui;
}
int add_book::validation()
{
    int flag=0;
    QRegExp rx("regex");
    QValidator *validator=new QRegExpValidator(rx,this);
    ui->book_name->setValidator(validator);
    ui->book_keyword->setValidator(validator);
    ui->book_publication->setValidator(validator);
    ui->book_author_1->setValidator(validator);
    ui->book_author_2->setValidator(validator);
    ui->book_author_3->setValidator(validator);
    ui->book_author_4->setValidator(validator);
    ui->book_price->setValidator(new QDoubleValidator(0.00,3000.00,2,this));
    ui->book_quantity->setValidator(new QIntValidator(1,100,this));
    ui->book_isbn_no->setValidator(new QIntValidator(1,100000,this));

    ui->book_edition->setValidator(new QIntValidator(1,10,this));
    if(!ui->book_name->hasAcceptableInput())
    {
        ui->book_name->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");

    }
    else if(!ui->book_keyword->hasAcceptableInput())
    {
        ui->book_keyword->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        //Sui->book_keyword->;
    }
    else if(!ui->book_publication->hasAcceptableInput())
    {
        ui->book_publication->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        //ui->book_publication->clear;
    }
    else if(!ui->book_author_1->hasAcceptableInput())
    {
        ui->book_author_1->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_author_1->clear();
    }
    else if(!ui->book_author_2->hasAcceptableInput())
    {
        ui->book_author_2->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_author_2->clear();
    }
    else if(!ui->book_author_3->hasAcceptableInput())
    {
        ui->book_author_3->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_author_3->clear();
    }
    else if(!ui->book_author_4->hasAcceptableInput())
    {
        ui->book_author_4->setStyleSheet("ui->book_author{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_author_4->clear();
    }
    else if(!ui->book_price->hasAcceptableInput())
    {
        ui->book_price->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_price->clear();
    }
    else if(!ui->book_quantity->hasAcceptableInput())
    {
        ui->book_quantity->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_quantity->clear();
    }
    else if(ui->book_format->currentIndex()==-1)
    {
      ui->book_format->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
    }
    else if(!ui->book_isbn_no->hasAcceptableInput())
    {
        ui->book_isbn_no->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_isbn_no->clear();
    }
   else if(ui->book_edition->currentIndex()==-1)
    {
        ui->book_edition->setStyleSheet("QLineEdit{padding:2px;border-style:solid;border:2px solid red;border-radius:8px;}");
        ui->book_edition->setCurrentText("Select");
    }
    else{
        flag=1;
    }
    if(flag==0)
    {
        return 0;
    }
    else{
        return 1;
    }
}
void add_book::on_pushButton_clicked()
{
   /* QRegularExpression IDValidator("\\b[A-Z0-9._%+-]+@[A-Z0.9-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_ID->setValidator(new QRegularExpressionValidator(IDValidator,this));
    if(!ui->lineEdit_ID->hasAcceptableInput())
    {
        //QMessageBox::warning(this,);
        ui->lineEdit_ID->setStyleSheet("QLineEdit {color:Red;}");
    }*/

}
void add_book::on_button_add_book_clicked()
{
   int flag=validation();
   ui->book_author_4->setText(QString::number(flag));

     if(flag==1)
     {
    add_book std;
    std::ofstream out;
    out.open("book.txt",std::ofstream::out | std::ofstream::app);
    int  b_id=ui->book_id->text().toInt();
    int b_isbn_no=ui->book_isbn_no->text().toInt();
    for(int i=0;i<ui->book_quantity->text().toInt();i++){
        std::string b_name=ui->book_name->text().toStdString();
        std::string b_key=ui->book_keyword->text().toStdString();
        std::string b_publication=ui->book_publication->text().toStdString();
        std::string b_author=ui->book_author_1->text().toStdString()+" "+ui->book_author_2->text().toStdString()+" "+ui->book_author_3->text().toStdString()+" "+ui->book_author_4->text().toStdString();
        int b_price=ui->book_price->text().toInt();
        std::string b_format=ui->book_format->currentText().toStdString();
        std::string b_type=ui->type_of_book->currentText().toStdString();
        std::string b_dept=ui->department->currentText().toStdString();
        int b_year=ui->book_releas_year->currentText().toInt();
        int b_edition=ui->book_edition->currentText().toInt();
        std::string b_status="Available";
        std.book(b_id,b_name,b_key,b_publication,b_author,b_price,b_format,b_type,b_dept,b_isbn_no,b_year,b_edition,b_status);
        out<<std;
        b_id=b_id+1;
        b_isbn_no++;
    }
    out.close();
    IDs id;
    id.updateID("Book",ui->book_quantity->text().toInt());
    QMessageBox::information(this,"Add Book","New Book Details Added Successfully...!");
    b_id=id.getID("Book");
    ui->book_id->setText(QString::number(b_id));
    ui->book_name->setText("");
    ui->book_author_1->setText("");
    ui->book_author_2->setText("");
    ui->book_author_3->setText("");
    ui->book_author_4->setText("");
    ui->book_isbn_no->setText("");
    ui->book_price->setText("");
    ui->book_publication->setText("");
    ui->book_quantity->setText("");
    ui->book_keyword->setText("");
    ui->book_edition->setCurrentIndex(0);
    ui->book_format->setCurrentIndex(0);
    ui->type_of_book->setCurrentIndex(0);
    ui->book_releas_year->setCurrentIndex(0);
    ui->department->setCurrentIndex(0);
}
}
