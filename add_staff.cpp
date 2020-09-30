//header file
#include "add_staff.h"
#include "ui_add_staff.h"
#include"staff_panel.h"
#include"ids.h"
#include<QMessageBox>
#include<QFile>
#include<ostream>
#include<QTextStream>
#include<QString>
//#include"library_card.h"
add_staff::add_staff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_staff)
{
    ui->setupUi(this);

    ui->comboBox_qualification->addItem("Select");
    ui->comboBox_qualification->addItem("B.Tech");
    ui->comboBox_qualification->addItem("M.Tech");
    ui->comboBox_qualification->addItem("Phd");

    //ui->comboBox_gendre->addItem("Select");
    ui->radioButton_male->setText("Male");
    ui->radioButton_female->setText("Female");

    ui->comboBox_dept->addItem("Select");
    ui->comboBox_dept->addItem("General Science Engineerinng");
    ui->comboBox_dept->addItem("Computer Science and Engineerinng");
    ui->comboBox_dept->addItem("Mechnical  Engineering");
    ui->comboBox_dept->addItem("Civil Engineering");
    ui->comboBox_dept->addItem("Electrical and Telicommunication Engineering");


    ui->comboBox_exp->addItem("Select");
    for(int i=1;i<30;i++)
    {
        ui->comboBox_exp->addItem(QString::number(i));
    }
    IDs id;
    int s_id=id.getID("Staff");
    ui->lineEdit_borrow->setText(QString::number(s_id));
    ui->lineEdit_borrow->setReadOnly(true);
}

add_staff::~add_staff()
{
    delete ui;
}

void add_staff::on_pushButton_clicked()
{
    int borrow_s=ui->lineEdit_borrow->text().toInt();
    std::string name_s=ui->lineEdit_fullname->text().toStdString();
    std::string email_id=ui->lineEdit_email->text().toStdString();
    std::string department=ui->comboBox_dept->currentText().toStdString();
    std::string s_gendre;
    if(ui->radioButton_female->isChecked())
    {
        s_gendre="Female";
    }
    else
    {
         s_gendre="Male";
    }
   // std::string s_gendre=ui->comboBox_gendre->currentText().toStdString();
    std::string qulific=ui->comboBox_qualification->currentText().toStdString();
    std::string s_experience=ui->comboBox_exp->currentText().toStdString();
    std::string phone=ui->lineEdit_phone->text().toStdString();
    std::string pass="staff";
    add_staff stf;
    stf.add_s(borrow_s,name_s,s_gendre,email_id,department,qulific,s_experience,phone,pass);
    std::ofstream out;
    out.open("staff.txt",std::ofstream::out | std::ofstream::app);
    out<<stf;
    out.close();
    IDs id;
    id.updateID("Staff",borrow_s);
    QMessageBox::information(this,"Add Staff","New Staff Recored Added Successfully....!");
    int s_id=id.getID("Staff");
    ui->lineEdit_borrow->setText(QString::number(s_id));
     ui->lineEdit_email->setText("");
     ui->lineEdit_fullname->setText("");
     ui->lineEdit_phone->setText("");
     ui->comboBox_dept->setCurrentIndex(0);
     ui->comboBox_exp->setCurrentIndex(0);
     ui->comboBox_qualification->setCurrentIndex(0);
    //Staff_Panel=new staff_panel(this);
    //Staff_Panel->show();
    }
