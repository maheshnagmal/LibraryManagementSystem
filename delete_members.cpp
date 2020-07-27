#include "delete_members.h"
#include "ui_delete_members.h"
#include"book_issue.h"
#include<QMessageBox>
#include"add_staff.h"
#include"add_student.h"
delete_members::delete_members(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::delete_members)
{
    ui->setupUi(this);
    ui->lineEdit_borrow_id->setFocus();
    ui->members_type->addItem("Select");
    ui->members_type->addItem("Staff");
    ui->members_type->addItem("Student");

   }

delete_members::~delete_members()
{
    delete ui;
}

void delete_members::on_Delete_member_clicked()
{
    int borrow_id;
    ui->lineEdit_borrow_id->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    if(!ui->lineEdit_borrow_id->hasAcceptableInput()||ui->members_type->currentText()=="Select"||ui->reasons->currentText()=="Select")
    {
        QMessageBox::warning(this,"Warning","Pls Enter Coreect data");
    }
    else
    {
        borrow_id=ui->lineEdit_borrow_id->text().toInt();
        int flag=0;
        if(1==check_book_issue(borrow_id)){
                QMessageBox::information(this,"Heelo","Student Should Return The Book");
        }else{
            if(ui->members_type->currentText()=="Student"){
                Add_Student student;
                std::ifstream in;
                std::ofstream out;
                in.open("student.txt",std::ifstream::in | std::ifstream::app);
                out.open("student_temp.txt",std::ofstream::out);
                while(!in.eof()) {
                    in>>student;
                    int b_id=student.borrow_id;
                    if(b_id==borrow_id){
                        flag=1;
                    }

                }
                in.close();
                in.open("student.txt",std::ifstream::in | std::ifstream::app);
                if(flag==1) {
                    in>>student;
                    while(!in.eof()) {
                        int b_id=student.borrow_id;
                        if(b_id!=borrow_id){
                            out<<student;
                        }
                        in>>student;
                    }
                    in.close();
                    out.close();
                    remove("student.txt");
                    rename("student_temp.txt" , "student.txt");
                    QMessageBox::information(this,"Sucess","Student record deleted Sucessfully!!");
                    ui->lineEdit_borrow_id->setText("");
               }
               else if(flag==0){
                   QMessageBox::information(this,"Fail","Given Borrow Id of Student is Not available in System\nPls Enter Correct Borrow ID!!!");
               }
            }
        }
        if(ui->members_type->currentText()=="Staff") {
            add_staff staff;
            int flag=0;
            std::ifstream in;
            std::ofstream out;
            in.open("staff.txt",std::ifstream::in | std::ifstream::app);
            out.open("staff_temp.txt",std::ofstream::out);
            while(!in.eof()) {
                in>>staff;
                int b_id=staff.borrow_id;
                if(b_id==borrow_id) {
                    flag=1;
                }
            }
            in.close();
            in.open("staff.txt",std::ifstream::in | std::ifstream::app);
            if(flag==1) {
                in>>staff;
                while(!in.eof()){
                    int b_id=staff.borrow_id;
                    QMessageBox::information(this,"Sucess",QString::number(b_id));
                    if(b_id!=borrow_id){
                        out<<staff;
                    }
                    in>>staff;
                }
                in.close();
                out.close();
                remove("staff.txt");
                rename("staff_temp.txt" , "staff.txt");
                QMessageBox::information(this,"Sucess","Staff record deleted Sucessfully!!");
                ui->lineEdit_borrow_id->setText("");
            }
            else if(flag==0) {
                QMessageBox::information(this,"Fail","Given Borrow Id of staff is Not available in System\nPls Enter Correct Borrow ID!!!");
            }
        }
     }
    ui->lineEdit_borrow_id->setText("");
    ui->members_type->setCurrentIndex(0);
    ui->reasons->setCurrentIndex(0);
}

void delete_members::on_members_type_currentTextChanged(const QString &arg1)
{
    if(arg1=="Staff") {
        ui->reasons->clear();
        ui->reasons->addItem("Select");
        ui->reasons->addItem("Resining");
        ui->reasons->addItem("Death");

    }
    else if(arg1=="Student" || arg1=="Select") {
        ui->reasons->clear();
        ui->reasons->addItem("Select");
        ui->reasons->addItem("Year Down");
        ui->reasons->addItem("Leaving");
        ui->reasons->addItem("Completion");
        ui->reasons->addItem("Death");
    }
}
int delete_members::check_book_issue(int id){
    book_issue book;
    std::ifstream in;
    int flag=0;
    in.open("student_issue.txt",std::ifstream::in);
    in>>book;
    while(!in.eof()){
        if(book.borrow_id==id){
            flag=1;
            break;
        }
        in>>book;
    }
    in.close();
    if(flag==1){
        return 1;
    }
    else{
        return 0;
    }
}
