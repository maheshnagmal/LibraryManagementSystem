#ifndef ADD_STUDENT_H
#define ADD_STUDENT_H

#include <QDialog>
#include<fstream>
#include<ostream>
#include<istream>
#include<QString>
#include<string>
#include"library_card.h"

namespace Ui {
class Add_Student;
}

class Add_Student : public QDialog
{
    Q_OBJECT
public:
    int borrow_id;
   std ::string password,name,email,dept,class_s,div,gendre,phone_no;
public:
    explicit Add_Student(QWidget *parent = 0);
    ~Add_Student();

private slots:
//    void on_pushButton_reset_clicked();

    void on_pushButton_add_student_clicked();
    void verify_data();
private:
    Ui::Add_Student *ui;
    library_card *Library_Card;
public:
    void add_stud(int borrow,std::string name_s,std::string gendre_s,std::string email_id,std::string deptm,std::string class_std,std::string division,std::string phone,std::string pass){
         borrow_id=borrow;
         name=name_s;
         std::replace(name.begin(),name.end(),' ','_');
         gendre=gendre_s;
         std::replace(gendre.begin(),gendre.end(),' ','_');
         email=email_id;
         std::replace(email.begin(),email.end(),' ','_');
         dept=deptm;
         std::replace(dept.begin(),dept.end(),' ','_');
         class_s=class_std;
         std::replace(class_s.begin(),class_s.end(),' ','_');
         div=division;
         std::replace(div.begin(),div.end(),' ','_');
         phone_no=phone;
         password=pass;
         std::replace(password.begin(),password.end(),' ','_');
    }
    friend std::ostream &operator <<(std::ostream &out,const Add_Student &obj){
        out<<obj.borrow_id<<"\t"<<obj.name<<"\t"<<obj.gendre<<"\t"<<obj.email<<"\t"<<obj.dept<<"\t"<<obj.class_s<<"\t"<<obj.div<<"\t"<<obj.phone_no<<"\t"<<obj.password<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,Add_Student &obj){
        in>>obj.borrow_id>>obj.name>>obj.gendre>>obj.email>>obj.dept>>obj.class_s>>obj.div>>obj.phone_no>>obj.password;
        return in;
    }
};

#endif // ADD_STUDENT_H
