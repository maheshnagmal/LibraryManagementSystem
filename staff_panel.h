#ifndef STAFF_PANEL_H
#define STAFF_PANEL_H
#include <QMainWindow>
#include"staff_profile.h"
#include"search_book.h"
#include"first_page.h"
namespace Ui {
class staff_panel;
}

class staff_panel : public QMainWindow
{
    Q_OBJECT

public:
    explicit staff_panel(QWidget *parent = 0,QString="",int id=0);
    ~staff_panel();
    QString u_name;
    int borrow_id;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_search_book_clicked();



    void on_book_transaction_clicked();

private:
    Ui::staff_panel *ui;
    staff_profile *Staff_Profile;
    search_Book *Search_Book;
    //first_page *First_Page;
};

#endif // STAFF_PANEL_H
