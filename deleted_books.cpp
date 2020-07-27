#include "deleted_books.h"
#include "ui_deleted_books.h"
#include"delete_book.h"
#include<istream>
#include<QMessageBox>
Deleted_books::Deleted_books(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deleted_books)
{
    ui->setupUi(this);
    ui->Delete_book_Details->setColumnCount(5);
    Delete_Book book;
    std::ifstream in;
    in.open("Deleted_Book.txt",std::ifstream::in);
    if(in.fail())
    {
        QMessageBox::warning(this,"Error","No Records Available");
        ui->Delete_book_Details->hide();
        in.close();

    }
    if(!in.fail())  {
    in>>book;
    for(int i=0;!in.eof();i++){
              ui->Delete_book_Details->insertRow(i);
              std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
              QString b_id=QString::number(book.book_id);
              QString b_name=QString::fromStdString(book.book_name);
              QString b_edition=QString::number(book.book_edition);
              std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
              QString b_author=QString::fromStdString(book.book_author);
              std::replace(book.reason.begin(),book.reason.end(),'_',' ');
              QString reason=QString::fromStdString(book.reason);
              ui->Delete_book_Details->setItem(i,0,new QTableWidgetItem(b_id));
              ui->Delete_book_Details->setItem(i,1,new QTableWidgetItem(b_name));
              ui->Delete_book_Details->setItem(i,2,new QTableWidgetItem(b_author));
              ui->Delete_book_Details->setItem(i,3,new QTableWidgetItem(b_edition));
              ui->Delete_book_Details->setItem(i,4,new QTableWidgetItem(reason));
              i++;
              in>>book;
          }

    in.close();
    }

}

Deleted_books::~Deleted_books()
{
    delete ui;
}
