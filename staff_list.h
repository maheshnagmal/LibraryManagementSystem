#ifndef STAFF_LIST_H
#define STAFF_LIST_H

#include <QMainWindow>

namespace Ui {
class Staff_list;
}

class Staff_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit Staff_list(QWidget *parent = 0);
    ~Staff_list();

private:
    Ui::Staff_list *ui;
};

#endif // STAFF_LIST_H
