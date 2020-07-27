#ifndef AVALIABLE_BOOK_H
#define AVALIABLE_BOOK_H

#include <QMainWindow>

namespace Ui {
class avaliable_book;
}

class avaliable_book : public QMainWindow
{
    Q_OBJECT

public:
    explicit avaliable_book(QWidget *parent = 0);
    ~avaliable_book();

private:
    Ui::avaliable_book *ui;
};

#endif // AVALIABLE_BOOK_H
