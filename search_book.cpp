#include "search_book.h"
#include "ui_search_book.h"
#include"add_book.h"
#include<QMessageBox>
search_Book::search_Book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_Book)
{
    ui->setupUi(this);
    ui->search_box->setFocus();
    ui->search_by->addItem("Select");
    ui->search_by->addItem("ID");
    ui->search_by->addItem("Book Name");
    ui->search_by->addItem("Keyword");
    ui->search_by->addItem("Author Name");
    ui->search_by->addItem("Publication");
}

search_Book::~search_Book()
{
    delete ui;
}

void search_Book::on_pushButton_clicked()
{
        ui->search_box->setValidator(new QRegExpValidator(QRegExp("^[a-zA-Z0-9]*$"),this));
        if(!ui->search_box->text().isNull()|ui->search_by->currentText()=="Select")   {
            QMessageBox::warning(this,"Warning","Pls Select proper keyword\nPls Enter proper Data");
        }
        else if(!ui->search_box->hasAcceptableInput())   {
            ui->search_box->setPlaceholderText("Enter Correct data to search");
        }
        else    {
            QString search_data=ui->search_box->text();
            QString search_by=ui->search_by->currentText();
            if(search_by=="Select Your Choice")
            {
                QMessageBox::warning(this,"Warning","Pls Select proper keyword");
            }
            else if(search_by=="ID"){
                search_by_id(search_data);
            }
            else if(search_by=="Book Name"){
                search_by_name(search_data);
            }
            else if(search_by=="Keyword"){
                search_by_key(search_data);
            }
            else if(search_by=="Author Name"){
                search_by_author(search_data);
            }
            else if(search_by=="Publication"){
                search_by_publication(search_data);
            }
        }

        ui->search_box->setText("");
        ui->search_by->setCurrentIndex(0);
}
void search_Book::search_by_id(QString id){
    ui->Details_table->setColumnCount(7);
    add_book book;
    std::ifstream in;
    int i=0;
    in.open("book.txt",std::ofstream::in | std::ofstream::app);
    while(!in.eof()){
        in>>book;
        QString b_id=QString::number(book.book_id);
        if(b_id==id){
            ui->Details_table->insertRow(i);
            std::replace(book.publication.begin(),book.publication.end(),'_',' ');
            QString b_publication=QString::fromStdString(book.publication);
            std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
            QString b_name=QString::fromStdString(book.book_name);
            QString b_edition=QString::number(book.edition);
            QString b_isbn_no=QString::number(book.isbn_no);
            QString b_status=QString::fromStdString(book.status);
            std::replace(book.author.begin(),book.author.end(),'_',' ');
            QString b_author=QString::fromStdString(book.author);          ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
          ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
          ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
          ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
          ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
          ui->Details_table->setItem(i,5,new QTableWidgetItem(b_author));
          ui->Details_table->setItem(i,6,new QTableWidgetItem(b_status));
          i++;
      }
  }
}
void search_Book::search_by_name(QString name){
    ui->Details_table->setColumnCount(7);
    add_book book;
    std::ifstream in;
    int i=0;
    in.open("book.txt",std::ofstream::in | std::ofstream::app);
    while(!in.eof()){
        in>>book;
        std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
        QString b_name=QString::fromStdString(book.book_name);
        if(b_name==name){
            ui->Details_table->insertRow(i);
            std::replace(book.publication.begin(),book.publication.end(),'_',' ');
            QString b_publication=QString::fromStdString(book.publication);
            QString b_id=QString::number(book.book_id);
            QString b_edition=QString::number(book.edition);
            QString b_isbn_no=QString::number(book.isbn_no);
            QString b_status=QString::fromStdString(book.status);
            std::replace(book.author.begin(),book.author.end(),'_',' ');
            QString b_author=QString::fromStdString(book.author);
            ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
          ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
          ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
          ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
          ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
          ui->Details_table->setItem(i,5,new QTableWidgetItem(b_author));
          ui->Details_table->setItem(i,6,new QTableWidgetItem(b_status));
          i++;
      }
  }
}
void search_Book::search_by_key(QString key){
    ui->Details_table->setColumnCount(7);
    add_book book;
    std::ifstream in;
    int i=0;
    in.open("book.txt",std::ofstream::in | std::ofstream::app);
    while(!in.eof()){
        in>>book;
        QString b_key=QString::fromStdString(book.book_key);
        if(b_key==key){
            ui->Details_table->insertRow(i);
            std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
            std::replace(book.publication.begin(),book.publication.end(),'_',' ');
            std::replace(book.author.begin(),book.author.end(),'_',' ');
            QString b_author=QString::fromStdString(book.author);
            QString b_publication=QString::fromStdString(book.publication);
            QString b_name=QString::fromStdString(book.book_name);
            QString b_id=QString::number(book.book_id);
            QString b_edition=QString::number(book.edition);
            QString b_isbn_no=QString::number(book.isbn_no);
            QString b_status=QString::fromStdString(book.status);
          ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
          ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
          ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
          ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
          ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
          ui->Details_table->setItem(i,5,new QTableWidgetItem(b_author));
          ui->Details_table->setItem(i,6,new QTableWidgetItem(b_status));
          i++;
      }
  }
}
void search_Book::search_by_author(QString author){
    ui->Details_table->setColumnCount(7);
    add_book book;
    std::ifstream in;
    int i=0;
    in.open("book.txt",std::ofstream::in | std::ofstream::app);
    while(!in.eof()){
        in>>book;
        std::replace(book.author.begin(),book.author.end(),'_',' ');
        QString b_author=QString::fromStdString(book.author);
        if(b_author==author){
            ui->Details_table->insertRow(i);
            std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
            std::replace(book.publication.begin(),book.publication.end(),'_',' ');
            QString b_publication=QString::fromStdString(book.publication);
            QString b_name=QString::fromStdString(book.book_name);
            QString b_id=QString::number(book.book_id);
            QString b_edition=QString::number(book.edition);
            QString b_isbn_no=QString::number(book.isbn_no);
            QString b_status=QString::fromStdString(book.status);
          ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
          ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
          ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
          ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
          ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
          ui->Details_table->setItem(i,5,new QTableWidgetItem(b_author));
          ui->Details_table->setItem(i,6,new QTableWidgetItem(b_status));
          i++;
      }
  }
}
void search_Book::search_by_publication(QString publication){
    ui->Details_table->setColumnCount(7);
    add_book book;
    std::ifstream in;
    int i=0;
    in.open("book.txt",std::ofstream::in | std::ofstream::app);
    while(!in.eof()){
        in>>book;
        std::replace(book.publication.begin(),book.publication.end(),'_',' ');
        QString b_publication=QString::fromStdString(book.publication);
        if(b_publication==publication){
            ui->Details_table->insertRow(i);
          std::replace(book.author.begin(),book.author.end(),'_',' ');
          std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
          QString b_name=QString::fromStdString(book.book_name);
          QString b_id=QString::number(book.book_id);
          QString b_edition=QString::number(book.edition);
          QString b_isbn_no=QString::number(book.isbn_no);
          QString b_author=QString::fromStdString(book.author);
          QString b_status=QString::fromStdString(book.status);
          ui->Details_table->setItem(i,0,new QTableWidgetItem(b_id));
          ui->Details_table->setItem(i,1,new QTableWidgetItem(b_name));
          ui->Details_table->setItem(i,2,new QTableWidgetItem(b_publication));
          ui->Details_table->setItem(i,3,new QTableWidgetItem(b_edition));
          ui->Details_table->setItem(i,4,new QTableWidgetItem(b_isbn_no));
          ui->Details_table->setItem(i,5,new QTableWidgetItem(b_author));
          ui->Details_table->setItem(i,6,new QTableWidgetItem(b_status));
          i++;
      }
  }
}

void search_Book::on_search_box_editingFinished()
{
    QString search_data=ui->search_box->text();
    QString search_by=ui->search_by->currentText();
    if(search_by=="Select Your Choice")
    {
        QMessageBox::warning(this,"Warning","Pls Select proper keyword");
    }
    else if(search_by=="ID"){
        search_by_id(search_data);
    }
    else if(search_by=="Book Name"){
        search_by_name(search_data);
    }
    else if(search_by=="Keyword"){
        search_by_key(search_data);
    }
    else if(search_by=="Author Name"){
        search_by_author(search_data);
    }
    else if(search_by=="Publication"){
        search_by_publication(search_data);
    }
    if(!ui->search_box->hasAcceptableInput())
    {
        ui->search_box->setPlaceholderText("Enter Correct data to search");
    }
    ui->search_box->setText("");
    ui->search_by->setCurrentIndex(0);
}
