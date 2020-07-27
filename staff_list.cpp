#include "staff_list.h"
#include "ui_staff_list.h"
#include"add_staff.h"
#include<QMessageBox>
Staff_list::Staff_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Staff_list)
{
    ui->setupUi(this);
    ui->staff_details->setColumnCount(8);
        int i=0;
        add_staff staff;
        std::ifstream in;
        in.open("staff.txt",std::ifstream::in);
        if(in.fail())
        {
            QMessageBox::warning(this,"Error","No Records Available");
            ui->staff_details->hide();
            in.close();

        }
        else    {
            in>>staff;
            for(int j=0;!in.eof();j++){
                      ui->staff_details->insertRow(i);
                      std::replace(staff.name.begin(),staff.name.end(),'_',' ');
                      QString b_name=QString::fromStdString(staff.name);
                      std::replace(staff.department.begin(),staff.department.end(),'_',' ');
                      ui->staff_details->setItem(i,0,new QTableWidgetItem(QString::number(staff.borrow_id)));
                      ui->staff_details->setItem(i,1,new QTableWidgetItem(b_name));
                      ui->staff_details->setItem(i,2,new QTableWidgetItem(QString::fromStdString(staff.email)));
                      ui->staff_details->setItem(i,3,new QTableWidgetItem(QString::fromStdString(staff.gendre)));
                      ui->staff_details->setItem(i,4,new QTableWidgetItem(QString::fromStdString(staff.qualification)));
                      ui->staff_details->setItem(i,5,new QTableWidgetItem(QString::fromStdString(staff.experience)));
                      ui->staff_details->setItem(i,6,new QTableWidgetItem(QString::fromStdString(staff.department)));
                      ui->staff_details->setItem(i,7,new QTableWidgetItem(QString::fromStdString(staff.phone_no)));
                      i++;
                      in>>staff;
                  }
            in.close();
        }
}

Staff_list::~Staff_list()
{
    delete ui;
}
