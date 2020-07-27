#include "vender_details.h"
#include "ui_vender_details.h"
vender_details::vender_details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vender_details)
{
    ui->setupUi(this);
}

vender_details::~vender_details()
{
    delete ui;
}
