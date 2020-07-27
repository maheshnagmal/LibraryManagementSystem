#include "book_return.h"
#include "ui_book_return.h"
#include"book_issue.h"
#include<QMessageBox>
#include<QDate>
#include<iostream>
book_return::book_return(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::book_return)
{
    ui->setupUi(this);
    ui->comboBox_memeber->addItem("Select");
    ui->comboBox_memeber->addItem("Staff");
    ui->comboBox_memeber->addItem("Student");
    ui->lineEdit_book_author->setReadOnly(true);
    ui->lineEdit_book_name->setReadOnly(true);
    ui->lineEdit_edition->setReadOnly(true);
    ui->lineEdit_class->setReadOnly(true);
    ui->lineEdit_due_date->setReadOnly(true);
    ui->lineEdit_full_name->setReadOnly(true);
    ui->lineEdit_dept->setReadOnly(true);
    ui->lineEdit_division->setReadOnly(true);
    ui->lineEdit_issue_date->setReadOnly(true);
    ui->lineEdit_current_date->setReadOnly(true);
    ui->lineEdit_fine->setReadOnly(true);
    //ui->lineEdit_issue_date->setReadOnly(true);

}
book_return::~book_return()
{
    delete ui;
}
void book_return::on_comboBox_memeber_editTextChanged(const QString &arg1)
{
    if(arg1=="Staff"){
        ui->label_class->hide();
        ui->label_div->hide();
        ui->lineEdit_class->hide();
        ui->lineEdit_division->hide();
    }
}

void book_return::on_comboBox_memeber_currentTextChanged(const QString &arg1)
{
    if(arg1=="Staff") {

        ui->label_class->hide();
        ui->label_div->hide();
        ui->lineEdit_class->hide();
        ui->lineEdit_division->hide();
        ui->lineEdit_fine->hide();
        ui->label_fine->hide();
    }

}
void book_return::on_lineEdit_book_id_editingFinished() {
      QDate current_date=QDate::currentDate();
    if(ui->comboBox_memeber->currentText()=="Student")
    {
        int flag=0;
        book_issue stud;
        std::ifstream in;
        int id=ui->lineEdit_book_id->text().toInt();
        in.open("student_issue.txt" ,std::ifstream::in | std::ifstream::app);
        in>>stud;
        while(!in.eof())
        {
            if(id==stud.book_id)
            {
                std::replace(stud.book_name.begin(),stud.book_name.end(),'_',' ');
                std::replace(stud.book_author.begin(),stud.book_author.end(),'_',' ');
                ui->lineEdit_book_name->setText(QString::fromStdString( stud.book_name));
                ui->lineEdit_edition->setText(QString::number( stud.book_edition));
                ui->lineEdit_book_author->setText(QString::fromStdString( stud.book_author));
                std::replace(stud.stud_name.begin(),stud.stud_name.end(),'_',' ');
                std::replace(stud.stud_dept.begin(),stud.stud_dept.end(),'_',' ');
                std::replace(stud.stud_class.begin(),stud.stud_class.end(),'_',' ');
                ui->lineEdit_borrow_id->setText(QString::number(stud.borrow_id));
                ui->lineEdit_full_name->setText(QString::fromStdString(stud.stud_name));
                ui->lineEdit_dept->setText(QString::fromStdString(stud.stud_dept));
                ui->lineEdit_class->setText(QString::fromStdString(stud.stud_class));
                ui->lineEdit_division->setText(QString::fromStdString(stud.stud_division));
                ui->lineEdit_issue_date->setText(QString::fromStdString(stud.issue_date));
                ui->lineEdit_due_date->setText(QString::fromStdString(stud.due_date));
                ui->lineEdit_current_date->setText(current_date.toString(Qt::LocalDate));
                QDate i_date=QDate::fromString(ui->lineEdit_current_date->text(),"dd/MM/yyyy");
                QDate d_date=QDate::fromString(ui->lineEdit_due_date->text(),"dd/MM/yyyy");
                if(i_date>d_date)
                {
                    int diff=d_date.daysTo(i_date);
                    ui->lineEdit_fine->setText(QString::number(diff*10));
                }
                else{
                    ui->lineEdit_fine->setText("0");
                }
                flag=1;
                //break;
            }
            in>>stud;
         }
        in.close();
        if(flag==0)
        {
            QMessageBox::warning(this,"Warning","Book is not issued by anyone~~or not valid bok id");
        }
    }
    else if(ui->comboBox_memeber->currentText()=="Staff")
    {
        int flag=0;
        book_issue stud;
        std::ifstream in;
        int id=ui->lineEdit_book_id->text().toInt();
        in.open("staff_issue.txt" ,std::ifstream::in | std::ifstream::app);
        in>>stud;
        while(!in.eof())
        {
            if(id==stud.book_id)
            {
                std::replace(stud.book_name.begin(),stud.book_name.end(),'_',' ');
                std::replace(stud.book_author.begin(),stud.book_author.end(),'_',' ');
                ui->lineEdit_book_name->setText(QString::fromStdString( stud.book_name));
                ui->lineEdit_edition->setText(QString::number( stud.book_edition));
                ui->lineEdit_book_author->setText(QString::fromStdString( stud.book_author));
                std::replace(stud.stud_name.begin(),stud.stud_name.end(),'_',' ');
                std::replace(stud.stud_dept.begin(),stud.stud_dept.end(),'_',' ');
                //std::replace(stud.stud_class.begin(),stud.stud_class.end(),'_',' ');
                ui->lineEdit_borrow_id->setText(QString::number(stud.borrow_id));
                ui->lineEdit_full_name->setText(QString::fromStdString(stud.stud_name));
                ui->lineEdit_dept->setText(QString::fromStdString(stud.stud_dept));
                ui->lineEdit_issue_date->setText(QString::fromStdString(stud.issue_date));
                ui->lineEdit_due_date->setText(QString::fromStdString(stud.due_date));
                ui->lineEdit_current_date->setText(current_date.toString(Qt::LocalDate));
                flag=1;
            }
            in>>stud;
         }
        in.close();
        if(flag==0)
        {
            QMessageBox::warning(this,"Warning","Book is not issued by anyone~~or not valid bok id");
        }
    }
    else {
        QMessageBox::warning(this,"Warnning","Select proper member");
    }
}
void book_return::on_pushButton_clicked()
{
    int borrow_id=ui->lineEdit_borrow_id->text().toInt();
    int edition=ui->lineEdit_edition->text().toInt();
    int book_id=ui->lineEdit_book_id->text().toInt();
    std::string book_name=ui->lineEdit_book_name->text().toStdString();
    std::string book_author=ui->lineEdit_book_author->text().toStdString();
    std::string s_name=ui->lineEdit_full_name->text().toStdString();
    std::string s_dept=ui->lineEdit_dept->text().toStdString();
    std::string s_class=ui->lineEdit_class->text().toStdString();
    std::string s_div=ui->lineEdit_division->text().toStdString();
    int fine=ui->lineEdit_fine->text().toInt();
    std::string return_date=ui->lineEdit_current_date->text().toStdString();
    if(!ui->lineEdit_book_id->text().isEmpty())
    {
        int id=ui->lineEdit_book_id->text().toInt();
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
                else{
                    book.status="Available";
                    out<<book;
                }
                in>>book;
            }
            in.close();
            out.close();
            remove("book.txt");
            rename("book_temp.txt" , "book.txt");

            if(ui->comboBox_memeber->currentText()=="Student") {
                book_return std;
                std.add_issue_details_student(book_id,book_name,book_author,edition,borrow_id,s_name,s_dept,s_class,s_div,return_date,fine);
                std::ofstream out;
                out.open("student_return.txt" ,std::ofstream::out | std::ofstream::app);
                out<<std;
                out.close();

                book_issue issue;
                std::ifstream in_i;
                std::ofstream out_i;
                in_i.open("student_issue.txt",std::ifstream::in | std::ifstream::app);
                out_i.open("student_temp.txt",std::ofstream::out);
                in_i>>issue;
                while(!in_i.eof())
                {
                    int b_id=issue.book_id;
                    if(b_id!=book_id){
                        out_i<<issue;
                    }
                    in_i>>issue;
                }
                in_i.close();
                out_i.close();
                remove("student_issue.txt");
                rename("student_temp.txt" , "student_issue.txt");
            }
            else if(ui->comboBox_memeber->currentText()=="Staff") {
                book_return std;
                std.add_return_details_staff(book_id,book_name,book_author,edition,borrow_id,s_name,s_dept,return_date);
                std::ofstream out;
                out.open("staff_return.txt" ,std::ofstream::out | std::ofstream::app);
                out<<std;
                out.close();

                book_issue issue;
                std::ifstream in_i;
                std::ofstream out_i;
                in_i.open("staff_issue.txt",std::ifstream::in | std::ifstream::app);
                out_i.open("staff_temp.txt",std::ofstream::out);
                in_i>>issue;
                while(!in_i.eof())
                {
                    int b_id=issue.book_id;
                    if(b_id!=book_id){
                        out_i<<issue;
                    }
                    in_i>>issue;
                }
                in_i.close();
                out_i.close();
                remove("staff_issue.txt");
                rename("staff_temp.txt" , "staff_issue.txt");
            }
    }
    //std::string issue_as=ui->comboBox_issue_as->currentText().toStdString();
    QMessageBox::information(this,"Issue Book","Book Issued Successfully.....!");
    ui->lineEdit_fine->setText("");
    ui->lineEdit_current_date->setText("");
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
    ui->lineEdit_due_date->setText("");
    ui->comboBox_memeber->setCurrentIndex(0);
}
