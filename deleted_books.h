#ifndef DELETED_BOOKS_H
#define DELETED_BOOKS_H

#include <QMainWindow>

namespace Ui {
class Deleted_books;
}

class Deleted_books : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deleted_books(QWidget *parent = 0);
    ~Deleted_books();

private:
    Ui::Deleted_books *ui;
};

#endif // DELETED_BOOKS_H
