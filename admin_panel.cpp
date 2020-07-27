#include "admin_panel.h"
#include"ui_admin_panel.h"
#include"add_book.h"
#include"add_student.h"
#include"add_staff.h"
#include"delete_book.h"
#include"delete_members.h"
#include"order_management.h"
#include"vender_details.h"
#include"avaliable_book.h"
#include"about_us.h"
#include"first_page.h"
#include"book_issue.h"
#include"book_return.h"
#include"book_issued.h"
#include"book_returned.h"
#include"change_password.h"
#include"stock_verification.h"
#include"deleted_books.h"
#include"student_list.h"
#include"staff_list.h"
Admin_Panel::Admin_Panel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin_Panel)
{
    ui->setupUi(this);
}

Admin_Panel::~Admin_Panel()
{
    delete ui;
}

void Admin_Panel::on_actionAdd_Student_triggered()
{
    Add_Student *add_student=new Add_Student(this);
    //hide();
    add_student->show();

}

void Admin_Panel::on_actionAdd_Staff_triggered()
{
    add_staff *Add_Staff=new add_staff(this);
    Add_Staff->show();
   // hide();
}

void Admin_Panel::on_actionAdd_Book_triggered()
{
       add_book *Add_Book=new add_book(this);
       Add_Book->show();
       //hide();
}

void Admin_Panel::on_actionDelete_Book_triggered()
{
    Delete_Book *delete_book=new Delete_Book(this);
    delete_book->show();
    //hide();
}

void Admin_Panel::on_actionSearch_Book_triggered()
{
    search_Book *Search_Book=new search_Book(this);
    Search_Book->show();

}
void Admin_Panel::on_actionDelete_Student_triggered()
{
    delete_members *Delete_Members=new delete_members(this);
    Delete_Members->show();
    //hide();
}
void Admin_Panel::on_actionOrder_management_triggered()
{
    order_management *Order_Management=new order_management(this);
    Order_Management->show();
}
void Admin_Panel::on_actionVender_Details_triggered()
{
    vender_details *Vender_Details=new vender_details(this);
    Vender_Details->show();
}

void Admin_Panel::on_actionAbout_Us_triggered()
{
    about_us *About_Us=new about_us(this);
    About_Us->show();
}

void Admin_Panel::on_actionAvailable_Books_triggered()
{
    avaliable_book *Available_Book=new avaliable_book(this);
    Available_Book->show();
}
void Admin_Panel::on_actionBy_Department_triggered()
{
    //Book_Issued=new book_issued(this);
    //Book_Issued->show();
}

void Admin_Panel::on_pushButton_clicked()
{
   this->close();
}

void Admin_Panel::on_actionBook_Issue_triggered()
{
    book_issue *Book_Issue=new book_issue(this);
    Book_Issue->show();
}
void Admin_Panel::on_actionBook_Return_triggered()
{
    Book_Return=new book_return(this);
    Book_Return->show();
}

void Admin_Panel::on_actionIssued_Book_triggered()
{
    Book_Issued=new book_issued(this);
    Book_Issued->show();
}
void Admin_Panel::on_actionReturned_Book_triggered()
{
    Book_Returned=new book_returned(this);
    Book_Returned->show();
}

void Admin_Panel::on_actionStock_Management_triggered()
{
    stock_verification *obj=new stock_verification(this);
    obj->show();
}

void Admin_Panel::on_actionStudent_Details_2_triggered()
{
    Student_list *stud=new Student_list(this);
    stud->show();
}

void Admin_Panel::on_actionStaff_Details_2_triggered()
{
    Staff_list *staff=new Staff_list(this);
    staff->show();
}

void Admin_Panel::on_actionDeleted_Books_triggered()
{
    Deleted_books *book=new Deleted_books(this);
    book->show();
}
