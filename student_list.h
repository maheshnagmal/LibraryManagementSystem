#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <QMainWindow>

namespace Ui {
class Student_list;
}

class Student_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit Student_list(QWidget *parent = 0);
    ~Student_list();

private:
    Ui::Student_list *ui;
};

#endif // STUDENT_LIST_H
