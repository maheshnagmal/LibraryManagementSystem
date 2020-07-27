#ifndef VENDER_DETAILS_H
#define VENDER_DETAILS_H

#include <QMainWindow>

namespace Ui {
class vender_details;
}

class vender_details : public QMainWindow
{
    Q_OBJECT

public:
    explicit vender_details(QWidget *parent = 0);
    ~vender_details();

private:
    Ui::vender_details *ui;
};

#endif // VENDER_DETAILS_H
