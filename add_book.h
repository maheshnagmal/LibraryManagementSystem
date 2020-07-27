#ifndef ADD_BOOK_H
#define ADD_BOOK_H

#include <QMainWindow>
#include<iostream>
#include<fstream>
#include<ostream>
#include<istream>
#include<QString>
#include<string>

namespace Ui {
class add_book;
}

class add_book : public QMainWindow
{
    Q_OBJECT
public:
    int book_id,price,isbn_no,year,edition;
    std::string book_name,book_key,publication,author,book_format,book_type,dept,status;
public:
    explicit add_book(QWidget *parent = 0);
    ~add_book();

private slots:
    void on_pushButton_clicked();
    int validation();
    void on_button_add_book_clicked();

private:
    Ui::add_book *ui;
public:
    void book(int b_id,std::string b_name,std::string b_key,std::string b_publication,std::string b_author,int b_price,std::string b_format,std::string b_type,std::string b_dept,int b_isbn_no,int b_year,int b_edition,std::string b_status){
        book_id=b_id;
        book_name=b_name;
        std::replace(book_name.begin(),book_name.end(),' ','_');
        book_key=b_key;
        std::replace(book_key.begin(),book_key.end(),' ','_');
        publication=b_publication;
        std::replace(publication.begin(),publication.end(),' ','_');
        author=b_author;
        std::replace(author.begin(),author.end(),' ','_');
        price=b_price;
        book_format=b_format;
        std::replace(book_format.begin(),book_format.end(),' ','_');
        book_type=b_type;
        std::replace(book_type.begin(),book_type.end(),' ','_');
        dept=b_dept;
        std::replace(dept.begin(),dept.end(),' ','_');
        isbn_no=b_isbn_no;
        year=b_year;
        edition=b_edition;
        status=b_status;
    }
    friend std::ostream &operator <<(std::ostream &out,const add_book &obj){
        out<<obj.book_id<<"\t"<<obj.book_name<<"\t"<<obj.book_key<<"\t"<<obj.publication<<"\t"<<obj.author<<"\t"<<obj.price<<"\t"<<obj.book_format<<"\t"<<obj.book_type<<"\t"<<obj.dept<<"\t"<<obj.isbn_no<<"\t"<<obj.year<<"\t"<<obj.edition<<"\t"<<obj.status<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,add_book &obj){
        in>>obj.book_id>>obj.book_name>>obj.book_key>>obj.publication>>obj.author>>obj.price>>obj.book_format>>obj.book_type>>obj.dept>>obj.isbn_no>>obj.year>>obj.edition>>obj.status;
        return in;
    }
};
#endif // ADD_BOOK_H
