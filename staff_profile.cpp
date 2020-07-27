#include "staff_profile.h"
#include"add_staff.h"
#include "ui_staff_profile.h"
#include"change_password.h"
staff_profile::staff_profile(QWidget *parent,QString name) :
    QMainWindow(parent),
    ui(new Ui::staff_profile)
{
    ui->setupUi(this);
    u_name=name;
    add_staff staff;
    std::ifstream in;
    QString email;
    in.open("staff.txt" ,std::ofstream::in | std::ofstream::app);
    while(!in.eof())
    {
        in>>staff;
        email=QString::fromStdString(staff.email);
        if(u_name==email)
        {
            std::replace(staff.name.begin(),staff.name.end(),'_',' ');
            std::replace(staff.department.begin(),staff.department.end(),'_',' ');
            //std::replace(staff.div.begin(),staff.div.end(),'_',' ');
            ui->lineEdit_borrow->setText(QString::number(staff.borrow_id));
            ui->lineEdit_fullname->setText(QString::fromStdString(staff.name));
            ui->lineEdit_dept->setText(QString::fromStdString(staff.department));
            ui->lineEdit_email->setText(QString::fromStdString(staff.email));
            ui->lineEdit_gender->setText(QString::fromStdString(staff.gendre));
            ui->lineEdit_phone->setText(QString ::fromStdString(staff.phone_no));
            break;
        }
     }
    in.close();
}

staff_profile::~staff_profile()
{
    delete ui;
}

void staff_profile::on_change_pssword_clicked()
{
    Change_Password=new change_password(this,"Staff",u_name);
    Change_Password->show();
}
