#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QMainWindow>

namespace Ui {
class about_us;
}

class about_us : public QMainWindow
{
    Q_OBJECT

public:
    explicit about_us(QWidget *parent = 0);
    ~about_us();

private:
    Ui::about_us *ui;
};

#endif // ABOUT_US_H
