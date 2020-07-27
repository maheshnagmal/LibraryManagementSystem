#ifndef BOOK_ISSUE_H
#define BOOK_ISSUE_H
#include <QMainWindow>
#include"add_book.h"
#include"add_student.h"
namespace Ui {
class book_issue;
}

class book_issue : public QMainWindow
{
    Q_OBJECT
public:
    explicit book_issue(QWidget *parent = 0);
    ~book_issue();
private slots:
    void on_user_type_editTextChanged(const QString &arg1);
    void on_lineEdit_book_id_editingFinished();
    void on_lineEdit_borrow_id_editingFinished();
    void on_pushButton_clicked();
    void on_comboBox_issue_as_currentTextChanged(const QString &arg1);
    void on_user_type_currentTextChanged(const QString &arg1);

private:
    Ui::book_issue *ui;
public:
    std::string book_name,book_author,stud_name,stud_class,stud_division,stud_dept,issue_as,issue_date,due_date;
    int book_id,borrow_id,book_edition;
    friend std::ostream &operator <<(std::ostream &out,const book_issue &obj){
        out<<obj.book_id<<"\t"<<obj.book_name<<"\t"<<obj.book_author<<"\t"<<obj.book_edition<<"\t"<<obj.borrow_id<<"\t"<<obj.stud_name<<"\t"<<obj.stud_class<<"\t"<<obj.stud_division<<"\t"<<obj.stud_dept<<"\t"<<obj.issue_as<<"\t"<<obj.issue_date<<"\t"<<obj.due_date<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,book_issue &obj){
       in>>obj.book_id>>obj.book_name>>obj.book_author>>obj.book_edition>>obj.borrow_id>>obj.stud_name>>obj.stud_class>>obj.stud_division>>obj.stud_dept>>obj.issue_as>>obj.issue_date>>obj.due_date;
        return in;
    }
};
#endif // BOOK_ISSUE_H
