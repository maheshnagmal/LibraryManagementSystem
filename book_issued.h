#ifndef BOOK_ISSUED_H
#define BOOK_ISSUED_H
#include<QDate>
#include <QMainWindow>

namespace Ui {
class book_issued;
}

class book_issued : public QMainWindow
{
    Q_OBJECT

public:
    explicit book_issued(QWidget *parent = 0);
    ~book_issued();

private slots:
    void on_pushButton_clicked();

    void on_to_date_selectionChanged();

    void on_from_date_selectionChanged();

    void on_comboBox_member_currentTextChanged(const QString &arg1);

private:
    Ui::book_issued *ui;

public:
    QDate to_date;
    QDate from_date;
};
#endif // BOOK_ISSUED_H
