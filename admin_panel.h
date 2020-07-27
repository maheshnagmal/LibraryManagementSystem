#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QMainWindow>
#include"add_student.h"
#include"add_staff.h"
#include"add_book.h"
#include"delete_book.h"
#include"search_book.h"
#include"delete_members.h"
#include"order_management.h"
#include"vender_details.h"
#include"about_us.h"
#include"avaliable_book.h"
#include"first_page.h"
#include"book_issue.h"
#include"book_return.h"
#include"book_issued.h"
#include"book_returned.h"
namespace Ui {
class Admin_Panel;
}

class Admin_Panel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin_Panel(QWidget *parent = 0);
    ~Admin_Panel();

private slots:
    void on_actionAdd_Student_triggered();


    void on_actionAdd_Staff_triggered();

    void on_actionAdd_Book_triggered();

    void on_actionDelete_Book_triggered();

    void on_actionSearch_Book_triggered();

    void on_actionDelete_Student_triggered();

    void on_actionOrder_management_triggered();

    void on_actionVender_Details_triggered();

    void on_actionAbout_Us_triggered();

    void on_actionAvailable_Books_triggered();

    void on_actionBy_Department_triggered();

    void on_pushButton_clicked();

    void on_actionBook_Issue_triggered();

    void on_actionBook_Return_triggered();

    void on_actionIssued_Book_triggered();

    void on_actionReturned_Book_triggered();

    void on_actionStock_Management_triggered();

    void on_actionStudent_Details_2_triggered();

    void on_actionStaff_Details_2_triggered();

    void on_actionDeleted_Books_triggered();

private:
    Ui::Admin_Panel *ui;
    book_issue *Book_Issue;
    book_return *Book_Return;
    book_issued *Book_Issued;
    book_returned *Book_Returned;
};

#endif // ADMIN_PANEL_H
