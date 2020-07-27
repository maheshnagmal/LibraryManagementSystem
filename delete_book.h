#ifndef DELETE_BOOK_H
#define DELETE_BOOK_H
#include<iostream>
#include<fstream>
#include<ostream>
#include<istream>
#include<QString>
#include<string>
#include <QDialog>

namespace Ui {
class Delete_Book;
}

class Delete_Book : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_Book(QWidget *parent = 0);
    ~Delete_Book();
    int book_id,book_edition;
    std::string book_name,book_author,reason;

    friend std::ostream &operator <<(std::ostream &out,const Delete_Book &obj){
        out<<obj.book_id<<"\t"<<obj.book_name<<"\t"<<obj.book_author<<"\t"<<obj.book_edition<<"\t"<<obj.reason<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,Delete_Book &obj){
        in>>obj.book_id>>obj.book_name>>obj.book_author>>obj.book_edition>>obj.reason;
        return in;
    }
private slots:
    void on_pushButton_clicked();
private:
    Ui::Delete_Book *ui;
};

#endif // DELETE_BOOK_H
