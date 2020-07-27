#include "order_management.h"
#include "ui_order_management.h"
#include"ids.h"
#include<QPdfWriter>
#include<QPainter>
#include<QDate>
#include<QMessageBox>
#include<QUrl>
#include<QDesktopServices>
order_management::order_management(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::order_management)
{
    ui->setupUi(this);
    ui->comboBox_realeas_year->addItem("Select");
    for(int i=1998;i<2019;i++)
    {
         ui->comboBox_realeas_year->addItem(QString::number((i)));
    }
    ui->comboBox_book_edition->addItem("Select");
    for(int i=1;i<10;i++)
    {
         ui->comboBox_book_edition->addItem(QString::number((i)));
    }
    ui->vender->addItem("Select");
    ui->vender->addItem("Saraswati Book Depo");
    ui->vender->addItem("Chhaya Book  pvt.LTD");
    ui->vender->addItem("Kitab Ghar");
    ui->vender->addItem("Krishana Book Store");
    ui->vender->addItem("Book Ganga");
}

order_management::~order_management()
{
    delete ui;
}
void order_management::on_pushButton_clicked()
{
    QMessageBox::information(this,"success","PDF Generated Successfully...!");
    IDs id;
    int b_id=id.getID("Order");
    QDate cd=QDate::currentDate();
    QString vender=ui->vender->currentText();
    QString book_name=ui->lineEdit_book_name->text();
    QString book_a=ui->lineEdit_author1->text()+" "+ui->lineEdit_author2->text()+" "+ui->lineEdit_author3->text()+" "+ui->lineEdit_author4->text();
    QString publication=ui->lineEdit_publication->text();
    QString release_year=ui->comboBox_realeas_year->currentText();
    QString quantity=ui->lineEdit_quantity->text();
    QString price=ui->lineEdit_price->text();
    QString edition=ui->comboBox_book_edition->currentText();
    QString total=ui->lineEdit_total->text();
    QString current=cd.toString()+QString::number(b_id)+".pdf";
    QString o_id=cd.toString("yyyy/MM/dd")+"/"+QString::number(b_id);
    ui->lineEdit_author1->setText(vender);
    QPdfWriter pdf(current);
    QPainter painter(&pdf);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Times New Romn",12));
    painter.drawText(8500,50,o_id);
    painter.drawPixmap(QRect(3000,100,3500,3000),QPixmap("E:/QT/BOOKHOLICS/book1.jpg"));
    painter.drawText(3000,3500,"Vender:");
    painter.drawText(5000,3500,vender);
    painter.drawText(3000,3900,"Book Name :");
    painter.drawText(5000,3900,book_name);
    painter.drawText(3000,4300,"Author  :");
    painter.drawText(5000,4300,book_a);
    painter.drawText(3000,4700,"Publication :");
    painter.drawText(5000,4700,publication);
    painter.drawText(3000,5100,"Release Year:");
    painter.drawText(5000,5100,release_year);
    painter.drawText(3000,5500,"Quantity :");
    painter.drawText(5000,5500,quantity);
    painter.drawText(3000,5900,"Price:");
    painter.drawText(5000,5900,price);
    painter.drawText(3000,6300,"Edition :");
    painter.drawText(5000,6300,edition);
    painter.drawText(3000,6700,"Total:");
    painter.drawText(5000,6700,total);
    painter.drawPixmap(QRect(6700,7750,2900,600),QPixmap("E:/QT/BOOKHOLICS/sign.jpeg"));
    painter.drawText(6900,8600,"SIGNATURE OF LIBRARIAN");
    painter.drawText(200,8600,"SIGNATURE OF PRINCIPAL");

    painter.end();
    id.updateID("Order",b_id);
    ui->comboBox_realeas_year->setCurrentIndex(0);
    ui->comboBox_book_edition->setCurrentIndex(0);
    ui->vender->setCurrentIndex(0);
    ui->lineEdit_book_name->setText("");
    ui->lineEdit_quantity->setText("");
    ui->lineEdit_publication->setText("");
    ui->lineEdit_author1->setText("");
    ui->lineEdit_author2->setText("");
    ui->lineEdit_author3->setText("");
    ui->lineEdit_author4->setText("");
    ui->lineEdit_price->setText("");
    ui->lineEdit_total->setText("");
}
void order_management::on_lineEdit_price_editingFinished()
{
    float total=ui->lineEdit_price->text().toFloat()*ui->lineEdit_quantity->text().toInt();
    QString t;
    t.setNum(total);
    ui->lineEdit_total->setText(t);
}
