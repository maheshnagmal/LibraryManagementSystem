#ifndef DELETE_MEMBERS_H
#define DELETE_MEMBERS_H

#include <QMainWindow>

namespace Ui {
class delete_members;
}

class delete_members : public QMainWindow
{
    Q_OBJECT

public:
    explicit delete_members(QWidget *parent = 0);
    ~delete_members();
    int check_book_issue(int id);

private slots:

    void on_Delete_member_clicked();

    void on_members_type_currentTextChanged(const QString &arg1);

private:
    Ui::delete_members *ui;
};

#endif // DELETE_MEMBERS_H
