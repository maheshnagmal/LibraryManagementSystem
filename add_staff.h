#ifndef ADD_STAFF_H
#define ADD_STAFF_H

#include <QDialog>
#include<fstream>
#include<ostream>
#include<istream>
#include<QString>
#include<string>
#include"staff_panel.h"
namespace Ui {
class add_staff;
}

class add_staff : public QDialog
{
    Q_OBJECT
public:
    int borrow_id;
   std ::string password,name,email,department,qualification,gendre,experience,phone_no;
public:
    explicit add_staff(QWidget *parent = 0);
    ~add_staff();

private slots:
    void on_pushButton_clicked();
private:
    Ui::add_staff *ui;
    //staff_panel *Staff_Panel;
public:
   void add_s(int borrow,std::string name_s,std::string s_gendre,std::string email_id,std::string deptm,std::string qulifi,std::string s_experience,std::string phone,std::string pass){
       borrow_id=borrow;
       name=name_s;
       std::replace(name.begin(),name.end(),' ','_');
       gendre=s_gendre;
       std::replace(gendre.begin(),gendre.end(),' ','_');
       email=email_id;
       std::replace(email.begin(),email.end(),' ','_');
       department=deptm;
       std::replace(department.begin(),department.end(),' ','_');
       qualification=qulifi;
       std::replace(qualification.begin(),qualification.end(),' ','_');
       experience=s_experience;
       std::replace(experience.begin(),experience.end(),' ','_');
       phone_no=phone;
       password=pass;
       std::replace(password.begin(),password.end(),' ','_');
  }
    friend std::ostream &operator <<(std::ostream &out,const add_staff &obj){
        out<<obj.borrow_id<<"\t"<<obj.name<<"\t"<<obj.email<<"\t"<<obj.gendre<<"\t"<<obj.department<<"\t"<<obj.qualification<<"\t"<<obj.experience<<"\t"<<obj.phone_no<<"\t"<<obj.password<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,add_staff &obj){
        in>>obj.borrow_id>>obj.name>>obj.email>>obj.gendre>>obj.department>>obj.qualification>>obj.experience>>obj.phone_no>>obj.password;
        return in;
    }
};

#endif // ADD_STAFF_H
