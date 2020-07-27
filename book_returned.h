#ifndef BOOK_RETURNED_H
#define BOOK_RETURNED_H
#include<QDate>
#include <QMainWindow>

namespace Ui {
class book_returned;
}

class book_returned : public QMainWindow
{
    Q_OBJECT

public:
    explicit book_returned(QWidget *parent = 0);

    ~book_returned();

private slots:

    void on_to_date_selectionChanged();

    void on_from_date_selectionChanged();

    void on_pushButton_clicked();

    void on_comboBox_member_currentTextChanged(const QString &arg1);

private:
    Ui::book_returned *ui;
public:
    QDate to_date;
    QDate from_date;

};

#endif // BOOK_RETURNED_H
