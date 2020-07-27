#ifndef IDS_H
#define IDS_H
#include<ostream>
#include<QString>
#include<istream>
class IDs
{
public:
    int book_id,stud_id,staff_id,order_id;
    IDs();
    friend std::ostream &operator <<(std::ostream &out,const IDs &obj){
        out<<obj.book_id<<"\t"<<obj.stud_id<<"\t"<<obj.staff_id<<"\t"<<obj.order_id<<std::endl;
        return out;
    }
    friend std::istream &operator >>(std::istream &in,IDs &obj){
        in>>obj.book_id>>obj.stud_id>>obj.staff_id>>obj.order_id;
        return in;
    }
    int getID(QString member="");
    void updateID(QString member="",int id=0);
};

#endif // IDS_H
