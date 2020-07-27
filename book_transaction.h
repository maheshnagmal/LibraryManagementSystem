#ifndef BOOK_TRANSACTION_H
#define BOOK_TRANSACTION_H

#include <QMainWindow>

namespace Ui {
class book_transaction;
}

class book_transaction : public QMainWindow
{
    Q_OBJECT

public:
    explicit book_transaction(QWidget *parent = 0,QString member="",int borrow_id=0);
    ~book_transaction();

private:
    Ui::book_transaction *ui;
public:
       QString user;
       int user_borrow_id;
};

#endif // BOOK_TRANSACTION_H
