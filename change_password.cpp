#include "change_password.h"
#include "ui_change_password.h"
#include"add_staff.h"
#include"add_student.h"
#include<QMessageBox>
change_password::change_password(QWidget *parent,QString type,QString mailID) :
    QMainWindow(parent),
    ui(new Ui::change_password)
{
    ui->setupUi(this);
    ui->old_pass->setFocus();
    if(type=="Student"){
        memberType=type;
    }else if(type=="Staff"){
        memberType=type;
    }
    emailID=mailID;
}

change_password::~change_password()
{
    delete ui;
}
void change_password::change_pass_stud(){
    int flag=0;
    Add_Student student;
    std::ifstream in;
    std::ofstream out;
    in.open("student.txt",std::ifstream::in | std::ifstream::app);
    out.open("student_temp.txt",std::ofstream::out |std::ofstream::app);
    std::string pass=ui->new_pass->text().toStdString();
    std::string old_pass=ui->old_pass->text().toStdString();
    if(ui->new_pass->text()==ui->reenter_pass->text()) {
        in>>student;
        while(!in.eof()){
            std::string b_id=student.email;
            if(b_id!=emailID.toStdString()){
                out<<student;
            }
            else if(old_pass==student.password){
                student.password=pass;
                out<<student;
                flag=1;
            }
            in>>student;
        }
        in.close();
        out.close();
        remove("student.txt");
        rename("student_temp.txt" , "student.txt");
    }
    if(flag==1){
        QMessageBox::information(this,"Chnage Password","Password Change Successfully...!");
    }
    else{
        QMessageBox::information(this,"Chnage Password","Plz Enter Correct Passwords...!");
    }
}
void change_password::change_pass_staff(){
    add_staff staff;
    int flag=0;
    std::ifstream in;
    std::ofstream out;
    in.open("staff.txt",std::ifstream::in | std::ifstream::app);
    out.open("staff_temp.txt",std::ofstream::out);
    std::string pass=ui->new_pass->text().toStdString();
    std::string old_pass=ui->old_pass->text().toStdString();
    if(ui->new_pass->text()==ui->reenter_pass->text()) {
        in>>staff;
        while(!in.eof()){
            std::string b_id=staff.email;
            if(b_id!=emailID.toStdString()){
                out<<staff;
            }
            else if(old_pass==staff.password){
                staff.password=pass;
                flag=1;
                out<<staff;
            }
            in>>staff;
        }
        in.close();
        out.close();
        remove("staff.txt");
        rename("staff_temp.txt" , "staff.txt");
    }
    if(flag==1){
        QMessageBox::information(this,"Change Password","Password Change Successfully...!");
    }
    else{
        QMessageBox::information(this,"Change Password","Please Enter Correct Passwords...!");
    }
}
void change_password::on_change_password_2_clicked()
{
    if(memberType=="Student"){
        change_pass_stud();
    }
    else if(memberType=="Staff"){
        change_pass_staff();
    }
    ui->new_pass->setText("");
    ui->old_pass->setText("");
    ui->reenter_pass->setText("");
    QMessageBox::information(this,"Success","Password Changed Successfully...!");
}
