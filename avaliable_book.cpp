#include "avaliable_book.h"
#include "ui_avaliable_book.h"
#include"add_book.h"
avaliable_book::avaliable_book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::avaliable_book)
{
    ui->setupUi(this);
    ui->Details_table->setColumnCount(7);
    //ui->Details_table->insertRow(0);

        int i=0;
        add_book book;
        QString status="Available";
        std::ifstream in;
        in.open("book.txt",std::ofstream::in);
        in>>book;
        for(int j=0;!in.eof();j++){
              if(status==QString::fromStdString(book.status)) {
                  ui->Details_table->insertRow(i);
                  std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                  QString b_id=QString::number(book.book_id);
                  QString b_name=QString::fromStdString(book.book_name);
                  std::replace(book.publication.begin(),book.publication.end(),'_',' ');
                  QString b_publication=QString::fromStdString(book.publication);
                  QString b_edition=QString::number(book.edition);
                  QString b_isbn_no=QString::number(book.isbn_no);
                  QString Release_Year=QString::number(book.year);
                  std::replace(book.author.begin(),book.author.end(),'_',' ');
                  QString b_author=QString::fromStdString(book.author);
                  ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
                  ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
                  ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
                  ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
                  ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
                  ui->Details_table->setItem(i,5,new QTableWidgetItem(Release_Year));
                  ui->Details_table->setItem(i,6,new QTableWidgetItem(b_author));
                  i++;
              }
              in>>book;
        }
        in.close();
}

avaliable_book::~avaliable_book()
{
    delete ui;
}
