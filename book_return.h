#ifndef BOOK_RETURN_H
#define BOOK_RETURN_H

#include <QMainWindow>

namespace Ui {
class book_return;
}

class book_return : public QMainWindow
{
    Q_OBJECT

public:
    explicit book_return(QWidget *parent = 0);
    ~book_return();

private slots:
    void on_comboBox_memeber_editTextChanged(const QString &arg1);

    void on_comboBox_memeber_currentTextChanged(const QString &arg1);

    void on_lineEdit_book_id_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::book_return *ui;
 public:
    std::string book_name,book_author,stud_name,stud_class,stud_division,stud_dept,return_date;
    int book_id,borrow_id,book_edition,fine;
    void add_issue_details_student(int b_id,std::string b_name,std::string b_author,int b_edition,int borrow,std::string name_s,std::string deptm,std::string s_class,std::string s_div,std::string current_date,int fine_s=0){
         book_id=b_id;
         book_author=b_author;
         book_name=b_name;
         book_edition=b_edition;
         borrow_id=borrow;
         stud_name=name_s;
         stud_class=s_class;
         stud_division=s_div;
         stud_dept=deptm;
         return_date=current_date;
         fine=fine_s;
         std::replace(stud_name.begin(),stud_name.end(),' ','_');
         std::replace(stud_dept.begin(),stud_dept.end(),' ','_');
         std::replace(stud_class.begin(),stud_class.end(),' ','_');
         std::replace(book_name.begin(),book_name.end(),' ','_');
         std::replace(book_author.begin(),book_author.end(),' ','_');
    }
    friend std::ostream &operator <<(std::ostream &out,const book_return &obj){
        out<<obj.borrow_id<<"\t"<<obj.stud_name<<"\t"<<obj.stud_dept<<"\t"<<obj.stud_class<<"\t"<<obj.stud_division<<"\t"<<obj.book_id<<"\t"<<obj.book_name<<"\t"<<obj.book_author<<"\t"<<obj.book_edition<<"\t"<<obj.return_date<<"\t"<<obj.fine<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,book_return &obj){
        in>>obj.borrow_id>>obj.stud_name>>obj.stud_dept>>obj.stud_class>>obj.stud_division>>obj.book_id>>obj.book_name>>obj.book_author>>obj.book_edition>>obj.return_date>>obj.fine;
        return in;
    }
    void add_return_details_staff(int b_id,std::string b_name,std::string b_author,int b_edition,int borrow,std::string name_s,std::string deptm,std::string r_date){
         book_id=b_id;
         book_author=b_author;
         book_name=b_name;
         book_edition=b_edition;
         borrow_id=borrow;
         stud_name=name_s;
         stud_dept=deptm;
         return_date=r_date;
         stud_class="111";
         stud_division="222";
         fine=0;
         std::replace(stud_name.begin(),stud_name.end(),' ','_');
         std::replace(stud_dept.begin(),stud_dept.end(),' ','_');
         std::replace(book_name.begin(),book_name.end(),' ','_');
         std::replace(book_author.begin(),book_author.end(),' ','_');
    }
};
#endif // BOOK_RETURN_H
