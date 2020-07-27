#include "ids.h"
#include<ostream>
#include<fstream>
IDs::IDs()
{

}
int IDs::getID(QString member){
    IDs id;
    std::ifstream in;
    in.open("IDs.txt",std::ifstream::in);
    in>>id;
    if(member=="Book"){
        return id.book_id;
    }
    else if(member=="Student"){
        return id.stud_id;
    }
    else if(member=="Staff"){
        return id.staff_id;
    }
    else if(member=="Order"){
        return id.order_id;
    }
    return 0;
}
void IDs::updateID(QString member,int lid){
    IDs id;
    std::ifstream in;
    std::ofstream out;
    out.open("IDs_temp.txt",std::ofstream::in |std::ofstream::app);
    in.open("IDs.txt",std::istream::in);
    in>>id;
    if(member=="Book"){
        id.book_id=id.book_id+lid;
        out<<id;
    }
    else if(member=="Student"){
      id.stud_id=id.stud_id+1;
      out<<id;
    }
    else if(member=="Staff"){
        id.staff_id=id.staff_id+1;
        out<<id;
    }
    else if(member=="Order"){
        id.order_id=id.order_id+1;
        out<<id;
    }
    in.close();
    out.close();
    remove("IDs.txt");
    rename("IDs_temp.txt","IDs.txt");
}
