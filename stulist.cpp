#include "stulist.h"

StuList::StuList()
{


}

std::vector<Student>* StuList::stulist=new std::vector<Student>;

std::vector<Student>* StuList::get(){
    if(stulist==NULL){
        StuList::stulist=new std::vector<Student>;

    }

return StuList::stulist;
}



StuList::~StuList(){

}
