#ifndef STUDENT_PANEL_H
#define STUDENT_PANEL_H
#include"search_book.h"
#include <QMainWindow>
#include"staff_profile.h"
#include"student_prfile.h"
#include"first_page.h"
namespace Ui {
class student_panel;
}

class student_panel : public QMainWindow
{
    Q_OBJECT

public:
    explicit student_panel(QWidget *parent = 0,QString user_name="",int id=0);
    ~student_panel();
    QString user_name;
    int borrow_id;
private slots:
    void on_pushButton_3_clicked();

    void on_profilr_button_clicked();

    void on_pushButton_clicked();

    void on_book_transaction_clicked();

private:
    Ui::student_panel *ui;
    search_Book *Search_Book;
    student_prfile *profile;

};
#endif // STUDENT_PANEL_H
