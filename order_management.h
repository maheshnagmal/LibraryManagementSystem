#ifndef ORDER_MANAGEMENT_H
#define ORDER_MANAGEMENT_H

#include <QMainWindow>

namespace Ui {
class order_management;
}

class order_management : public QMainWindow
{
    Q_OBJECT

public:
    explicit order_management(QWidget *parent = 0);
    ~order_management();

private slots:

    void on_pushButton_clicked();

    void on_lineEdit_price_editingFinished();

private:
    Ui::order_management *ui;
};

#endif // ORDER_MANAGEMENT_H
