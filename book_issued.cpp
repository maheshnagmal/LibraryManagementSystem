#include "book_issued.h"
#include "ui_book_issued.h"
#include"book_issue.h"
#include<QMessageBox>
book_issued::book_issued(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::book_issued)
{
    ui->setupUi(this);
    ui->comboBox_member->addItem("select");
    ui->comboBox_member->addItem("Staff");
    ui->comboBox_member->addItem("Student");

    to_date=QDate::currentDate();
    from_date=QDate::currentDate();

    ui->from_date->setGridVisible(true);
    ui->to_date->setGridVisible(true);
    ui->from_date->setMaximumDate(QDate::currentDate());
    ui->to_date->setMaximumDate(QDate::currentDate());
}
book_issued::~book_issued()
{
    delete ui;
}
void book_issued::on_pushButton_clicked()
{

    QValidator *valid_borrow_id=new QIntValidator(1,10000,this);
    ui->lineEdit_borrow_id->setValidator(valid_borrow_id);
    if(ui->from_date->selectedDate().isNull() || ui->to_date->selectedDate().isNull() || ui->comboBox_member->currentText()=="Select") {
        QMessageBox::warning(this,"Warning","pls select proper dates!!\nSelct proper member");
    }
    else if(ui->lineEdit_borrow_id->text().isEmpty())
    {
        QMessageBox::warning(this,"Warnning","Pls Enter borrow id");
    }
    else if(!ui->lineEdit_borrow_id->hasAcceptableInput()){
        QMessageBox::warning(this,"Warnning","Pls Enter valid borrow id");
    }
    else {
        QDate Date;
        if(ui->comboBox_member->currentText()=="Student")   {
            int i=0,flag=0;
            book_issue book;
            ui->return_deatils->setColumnCount(9);
            std::ifstream in;
            in.open("student_issue.txt",std::ifstream::in);
            if(!in.fail())    {
                in>>book;
                for(int j=0;!in.eof();j++){
                    QString str=QString::fromStdString(book.issue_date);
                    Date=QDate::fromString(str,"dd/MM/yyyy");
                    if(Date>=to_date && Date<=from_date && book.borrow_id==ui->lineEdit_borrow_id->text().toInt()) {
                          ui->return_deatils->insertRow(i);
                          std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                          std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                          QString b_id=QString::number(book.book_id);
                          QString b_name=QString::fromStdString(book.book_name);
                          QString b_edition=QString::number(book.book_edition);
                          QString b_author=QString::fromStdString(book.book_author);
                          std::replace(book.stud_name.begin(),book.stud_name.end(),'_',' ');
                          std::replace(book.stud_dept.begin(),book.stud_dept.end(),'_',' ');
                          std::replace(book.stud_class.begin(),book.stud_class.end(),'_',' ');
                          QString s_name=QString::fromStdString(book.stud_name);
                          QString s_dept=QString::fromStdString(book.stud_dept);
                          QString s_class=QString::fromStdString(book.stud_class);
                          QString s_div=QString::fromStdString(book.stud_division);
                          QString borrow_id=QString::number(book.borrow_id);
                          ui->return_deatils->setItem(i,0,new QTableWidgetItem(b_id));
                          ui->return_deatils->setItem(i,1,new QTableWidgetItem(b_name));
                          ui->return_deatils->setItem(i,2,new QTableWidgetItem(b_author));
                          ui->return_deatils->setItem(i,3,new QTableWidgetItem(b_edition));
                          ui->return_deatils->setItem(i,4,new QTableWidgetItem(borrow_id));
                          ui->return_deatils->setItem(i,5,new QTableWidgetItem(s_name));
                          ui->return_deatils->setItem(i,6,new QTableWidgetItem(s_dept));
                          ui->return_deatils->setItem(i,7,new QTableWidgetItem(s_class));
                          ui->return_deatils->setItem(i,8,new QTableWidgetItem(s_div));
                          i++;
                          flag=1;
                      }
                      in>>book;
                }
                if(flag==0)
                {
                    QMessageBox::warning(this,"Warnning","Entered borrow id not issued book");
                }
                in.close();
             }
            else{
                QMessageBox::warning(this,"error","Currently nobody issued books");
                in.close();
            }

        }
       else if(ui->comboBox_member->currentText()=="Staff")   {
            int i=0,flag=0;
            book_issue book;
            ui->return_deatils->setColumnCount(6);
            std::ifstream in;
            in.open("staff_issue.txt",std::ifstream::in);
            if(!in.fail())    {
                in>>book;
                for(int j=0;!in.eof();j++){
                    QString str=QString::fromStdString(book.issue_date);
                    Date=QDate::fromString(str,"dd/MM/yyyy");
                    if(Date>=to_date && Date<=from_date && book.borrow_id==ui->lineEdit_borrow_id->text().toInt()) {
                          ui->return_deatils->insertRow(i);
                          std::replace(book.book_author.begin(),book.book_author.end(),'_',' ');
                          std::replace(book.book_name.begin(),book.book_name.end(),'_',' ');
                          QString b_id=QString::number(book.book_id);
                          QString b_name=QString::fromStdString(book.book_name);
                          QString b_edition=QString::number(book.book_edition);
                          QString b_author=QString::fromStdString(book.book_author);
                          std::replace(book.stud_name.begin(),book.stud_name.end(),'_',' ');
                          std::replace(book.stud_dept.begin(),book.stud_dept.end(),'_',' ');
                          std::replace(book.stud_class.begin(),book.stud_class.end(),'_',' ');
                          QString s_name=QString::fromStdString(book.stud_name);
                          QString s_dept=QString::fromStdString(book.stud_dept);
                          QString borrow_id=QString::number(book.borrow_id);
                          ui->return_deatils->setItem(i,0,new QTableWidgetItem(b_id));
                          ui->return_deatils->setItem(i,1,new QTableWidgetItem(b_name));
                          ui->return_deatils->setItem(i,2,new QTableWidgetItem(b_author));
                          ui->return_deatils->setItem(i,3,new QTableWidgetItem(b_edition));
                          ui->return_deatils->setItem(i,4,new QTableWidgetItem(borrow_id));
                          ui->return_deatils->setItem(i,5,new QTableWidgetItem(s_name));
                          ui->return_deatils->setItem(i,6,new QTableWidgetItem(s_dept));
                          i++;
                          flag=1;
                      }
                      in>>book;
                }
                in.close();
                if(flag==0)
                {
                    QMessageBox::warning(this,"Warnning","Entered borrow id not issued book");
                }
            }
            else    {
                QMessageBox::warning(this,"Error","Currently not any Staff issued books!");
            }
        }

    }

}
void book_issued::on_to_date_selectionChanged() {
    to_date=ui->to_date->selectedDate();
    //ui->label_2->setText(to_date);
}
void book_issued::on_from_date_selectionChanged() {
    from_date=ui->from_date->selectedDate();
}

void book_issued::on_comboBox_member_currentTextChanged(const QString &arg1)
{
    if(arg1!="Select")
        ui->return_deatils->clearContents();
    if(arg1=="Staff"){
        ui->return_deatils->setColumnHidden(8,true);
        ui->return_deatils->setColumnHidden(9,true);
    }
}
