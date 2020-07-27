#include "book_issue.h"
#include "ui_book_issue.h"
#include"add_book.h"
#include"add_staff.h"
#include"add_student.h"
#include<QDate>
#include<iostream>
#include<QMessageBox>
book_issue::book_issue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::book_issue) {
    ui->setupUi(this);
    ui->comboBox_issue_as->addItem("Select");
    ui->comboBox_issue_as->addItem("By Bookloan");
    ui->comboBox_issue_as->addItem("By Reference");
    ui->comboBox_issue_as->addItem("By ID");

    ui->user_type->addItem("Select");
    ui->user_type->addItem("Student");
    ui->user_type->addItem("Staff");
    if(ui->user_type->currentText()=="Staff") {
        ui->label_class->hide();
        ui->label_div->hide();
        ui->lineEdit_class->hide();
        ui->lineEdit_division->hide();
    }
    ui->lineEdit_book_author->setReadOnly(true);
    ui->lineEdit_book_name->setReadOnly(true);
    ui->lineEdit_edition->setReadOnly(true);
    ui->lineEdit_class->setReadOnly(true);
    ui->lineEdit_due_date->setReadOnly(true);
    ui->lineEdit_full_name->setReadOnly(true);
    ui->lineEdit_dept->setReadOnly(true);
    ui->lineEdit_issue_date->setReadOnly(true);
    ui->lineEdit_division->setReadOnly(true);
}

book_issue::~book_issue() {
    delete ui;
}
void book_issue::on_user_type_editTextChanged(const QString &arg1) {
    if(arg1=="Staff"){
        ui->label_class->hide();
        ui->label_div->hide();
        ui->lineEdit_class->hide();
        ui->lineEdit_division->hide();
    }
}
void book_issue::on_lineEdit_book_id_editingFinished() {
    int count=0,flag=0;
    QString name;
    add_book book;
    std::ifstream in;
    ui->lineEdit_book_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),ui->lineEdit_book_id));
    if(!ui->lineEdit_book_id->hasAcceptableInput())
    {
        QMessageBox::warning(this,"Warning","Enter Valid Book id");
        ui->lineEdit_book_id->setText("");
    }
    else{
        int id=ui->lineEdit_book_id->text().toInt();
        in.open("book.txt",std::ifstream::in);
        if(!in.fail())  {
            in>>book;
            while(!in.eof()){
                if(id==book.book_id && book.status=="Available"){
                    std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                    std::replace(book.author.begin(),book.author.end(),'_',' ');
                    ui->lineEdit_book_name->setText(QString::fromStdString( book.book_name));
                    ui->lineEdit_edition->setText(QString::number(book.edition));
                    ui->lineEdit_book_author->setText(QString::fromStdString( book.author));
                    name=QString::fromStdString( book.book_name);
                    flag=1;
                    break;
                }
                else if(id==book.book_id && book.status=="Issued"){
                    QMessageBox::information(this,"Fail","This Book Is Already Issued");
                    break;
                }
             in>>book;
             }
            in.close();
            if(flag==1){
              add_book book;
              std::ifstream in;
              std::ofstream out;
              in.open("book.txt",std::ifstream::in | std::ifstream::app);
              out.open("book_temp.txt",std::ofstream::out |std::ofstream::app);
              in>>book;
              while(!in.eof()){
                  int b_id=book.book_id;
                  if(b_id!=id){
                      out<<book;
                  }
                  else    {
                      book.status="Issued";
                      out<<book;
                  }
                  name=QString::fromStdString( book.book_name);
                  if(name==ui->lineEdit_book_name->text()){
                      count++;
                  }
                  in>>book;
              }
              in.close();
              out.close();
              remove("book.txt");
              rename("book_temp.txt" , "book.txt");
          }
          else{
              QMessageBox::warning(this,"Warning","Book Not Available");
          }
       }
       else  {
            QMessageBox::warning(this,"Error","Does Not Exits File");
       }
    }
}
void book_issue::on_lineEdit_borrow_id_editingFinished() {
    QValidator *valid_borrow_id=new QIntValidator(1,10000,this);
    ui->lineEdit_borrow_id->setValidator(valid_borrow_id);
    if(!ui->lineEdit_borrow_id->hasAcceptableInput())
    {
        QMessageBox::warning(this,"Warning","Pls Enter Correct Borrow Id");
    }
    else    {
        if(ui->user_type->currentText()=="Student")
        {
            int flag=0;
            Add_Student stud;
            std::ifstream in;
            int id=ui->lineEdit_borrow_id->text().toInt();
            in.open("student.txt" ,std::ofstream::in | std::ofstream::app);
            if(!in.fail())   {
                in>>stud;
                while(!in.eof())
                {
                    if(id==stud.borrow_id)
                    {
                        std::replace(stud.name.begin(),stud.name.end(),'_',' ');
                        std::replace(stud.dept.begin(),stud.dept.end(),'_',' ');
                        std::replace(stud.class_s.begin(),stud.class_s.end(),'_',' ');
                        ui->lineEdit_borrow_id->setText(QString::number(stud.borrow_id));
                        ui->lineEdit_full_name->setText(QString::fromStdString(stud.name));
                        ui->lineEdit_dept->setText(QString::fromStdString(stud.dept));
                        ui->lineEdit_class->setText(QString::fromStdString(stud.class_s));
                        ui->lineEdit_division->setText(QString::fromStdString(stud.div));
                        flag=1;
                    }
                in>>stud;
                }
                in.close();
             }
            else    {
                QMessageBox::warning(this,"Warning","Students are not available");
                in.close();
             }
            if(flag==0)
            {
                QMessageBox::warning(this,"Error"," Borrow id user not available");
            }
         }
        else if(ui->user_type->currentText()=="Staff")
        {
            int flag=0;
            add_staff staff;
            std::ifstream in;
            int id=ui->lineEdit_borrow_id->text().toInt();
            in.open("staff.txt" ,std::ofstream::in | std::ofstream::app);
            if(!in.fail())  {
                in>>staff;
                while(!in.eof())
                {
                    if(id==staff.borrow_id)
                    {
                        std::replace(staff.name.begin(),staff.name.end(),'_',' ');
                        std::replace(staff.department.begin(),staff.department.end(),'_',' ');
                        ui->lineEdit_borrow_id->setText(QString::number(staff.borrow_id));
                        ui->lineEdit_full_name->setText(QString::fromStdString(staff.name));
                        ui->lineEdit_dept->setText(QString::fromStdString(staff.department));
                        flag=1;
                    }
                    in>>staff;
                }
                in.close();
                if(flag==0) {
                    QMessageBox::warning(this,"Error"," Given borrow id Staff is not avialble");
                }
            }
            else    {
                QMessageBox::warning(this,"Warning","No Staff is Available");
            }
        }
        else{
            QMessageBox::information(this,"warnning","select correct Choice!!");
        }
   }

}
void book_issue::on_pushButton_clicked() {
    book_issue std;
    std.borrow_id=ui->lineEdit_borrow_id->text().toInt();
    std.book_edition=ui->lineEdit_edition->text().toInt();
    std.book_id=ui->lineEdit_book_id->text().toInt();

    std.book_name=ui->lineEdit_book_name->text().toStdString();
    std::replace(std.book_name.begin(),std.book_name.end(),' ','_');

    std.book_author=ui->lineEdit_book_author->text().toStdString();
    std::replace(std.book_author.begin(),std.book_author.end(),' ','_');

    std.stud_name=ui->lineEdit_full_name->text().toStdString();
    std::replace(std.stud_name.begin(),std.stud_name.end(),' ','_');

    std.stud_dept=ui->lineEdit_dept->text().toStdString();
    std::replace(std.stud_dept.begin(),std.stud_dept.end(),' ','_');

    std.stud_class=ui->lineEdit_class->text().toStdString();
    std::replace(std.stud_class.begin(),std.stud_class.end(),' ','_');

    std.stud_division=ui->lineEdit_division->text().toStdString();
    std.issue_date=ui->lineEdit_issue_date->text().toStdString();
    std.due_date=ui->lineEdit_due_date->text().toStdString();
    std.issue_as=ui->comboBox_issue_as->currentText().toStdString();
    std::replace(std.issue_as.begin(),std.issue_as.end(),' ','_');


    if(ui->user_type->currentText()=="Student") {
        std::ofstream out;
        out.open("student_issue.txt" ,std::ofstream::out | std::ofstream::app);
        out<<std;
        out.close();
    }
    else if(ui->user_type->currentText()=="Staff") {
        std.stud_class="111";
        std.stud_division="222";
        std::ofstream out;
        out.open("staff_issue.txt" ,std::ofstream::out | std::ofstream::app);
        out<<std;
        out.close();
    }
    QMessageBox::information(this,"Issue Book","Book Issued Successfully.....!");
    ui->comboBox_issue_as->setCurrentIndex(0);
    ui->lineEdit_book_author->setText("");
    ui->lineEdit_book_id->setText("");
    ui->lineEdit_book_name->setText("");
    ui->lineEdit_borrow_id->setText("");
    ui->lineEdit_class->setText("");
    ui->lineEdit_dept->setText("");
    ui->lineEdit_division->setText("");
    ui->lineEdit_due_date->setText("");
    ui->lineEdit_edition->setText("");
    ui->lineEdit_full_name->setText("");
    ui->lineEdit_issue_date->setText("");
    ui->user_type->setCurrentIndex(0);
}
void book_issue::on_comboBox_issue_as_currentTextChanged(const QString &arg1){
    QDate cd=QDate::currentDate();
    QDate currentD;
    currentD=cd;
    ui->lineEdit_issue_date->setText(currentD.toString(Qt::LocalDate));
    QDate dd;
    if(arg1=="By Bookloan"){
        dd=currentD.addDays(182);
    }
    else if(arg1=="By Reference"){
        dd=currentD.addDays(7);
    }
    else if(arg1=="By ID"){
        dd=currentD.addDays(1);
    }
    ui->lineEdit_due_date->setText(dd.toString(Qt::LocalDate));
}
void book_issue::on_user_type_currentTextChanged(const QString &arg1){
    if(arg1=="Staff") {
        ui->lineEdit_class->hide();
        ui->lineEdit_division->hide();
        ui->label_class->hide();
        ui->label_div->hide();
    }
    else if(arg1=="Student" || arg1=="Select") {
        ui->lineEdit_class->show();
        ui->lineEdit_division->show();
        ui->label_class->show();
        ui->label_div->show();
    }
}
