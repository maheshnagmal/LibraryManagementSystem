#ifndef SEARCH_BOOK_H
#define SEARCH_BOOK_H

#include <QDialog>

namespace Ui {
class search_Book;
}

class search_Book : public QDialog
{
    Q_OBJECT

public:
    explicit search_Book(QWidget *parent = 0);

    void search_by_id(QString id="");
    void search_by_name(QString name="");
    void search_by_key(QString key="");
    void search_by_author(QString author="");
    void search_by_publication(QString publication="");

    ~search_Book();

private slots:

    void on_pushButton_clicked();

    void on_search_box_editingFinished();

private:
    Ui::search_Book *ui;
};

#endif // SEARCH_BOOK_H
