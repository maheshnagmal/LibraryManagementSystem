#ifndef STOCK_VERIFICATION_H
#define STOCK_VERIFICATION_H

#include <QMainWindow>

namespace Ui {
class stock_verification;
}

class stock_verification : public QMainWindow
{
    Q_OBJECT

public:
    explicit stock_verification(QWidget *parent = 0);
    ~stock_verification();

private:
    Ui::stock_verification *ui;
public :
    int issued_books=0,available_books=0,deleted_books=0;
};

#endif // STOCK_VERIFICATION_H
