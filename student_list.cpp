#include "student_list.h"
#include "ui_student_list.h"
#include"add_student.h"
#include<QMessageBox>
Student_list::Student_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Student_list)
{
    ui->setupUi(this);
    ui->student_details->setColumnCount(8);
        int i=0;
        Add_Student stud;
        std::ifstream in;
        in.open("student.txt",std::ifstream::in);
        if(in.fail())
        {
            QMessageBox::warning(this,"Error","No Records Available");
            ui->student_details->hide();
            in.close();

        }
        else    {
            in>>stud;
            for(int j=0;!in.eof();j++){
                      ui->student_details->insertRow(i);
                      std::replace(stud.name.begin(),stud.name.end(),'_',' ');
                      QString b_name=QString::fromStdString(stud.name);
                      std::replace(stud.dept.begin(),stud.dept.end(),'_',' ');
                      std::replace(stud.class_s.begin(),stud.class_s.end(),'_',' ');
                      ui->student_details->setItem(i,0,new QTableWidgetItem(QString::number(stud.borrow_id)));
                      ui->student_details->setItem(i,1,new QTableWidgetItem(b_name));
                      ui->student_details->setItem(i,2,new QTableWidgetItem(QString::fromStdString(stud.email)));
                      ui->student_details->setItem(i,3,new QTableWidgetItem(QString::fromStdString(stud.gendre)));
                      ui->student_details->setItem(i,4,new QTableWidgetItem(QString::fromStdString(stud.dept)));
                      ui->student_details->setItem(i,5,new QTableWidgetItem(QString::fromStdString(stud.class_s)));
                      ui->student_details->setItem(i,6,new QTableWidgetItem(QString::fromStdString(stud.div)));
                      ui->student_details->setItem(i,7,new QTableWidgetItem(QString::fromStdString(stud.phone_no)));
                      i++;
                      in>>stud;
                  }
            in.close();
           }
}

Student_list::~Student_list()
{
    delete ui;
}
