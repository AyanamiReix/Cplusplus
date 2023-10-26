#include <iostream>
using namespace std;
#include <string>

class stu{

    string name;
    static int num;
    stu* pnext;
    static stu* pfirst;
public:
    stu(string);
    ~stu();
    void show_currentList();
    


};

stu* stu::pfirst=NULL;
int stu::num=0;

stu::stu(string sname):name(sname){
    cout<<"constructing..."<<this->name<<endl;
    pnext=pfirst;
    pfirst=this;
    num+=1;

}

stu::~stu(){
    cout<<"desconstructing..."<<this->name<<endl;
    if(pfirst==this){
        pfirst=pnext;
    }
    stu *p=pfirst;
    for(p;p;p=p->pnext){
        if(p->pnext==this){
            p->pnext=this->pnext;
        }
    }

    

}

void stu::show_currentList(){
    stu *p=pfirst;
    // while(p){
        
    //     cout<<p->name<<"->";
    //     p=p->pnext;
    //     }
    //     cout<<endl;
        
    
    for(stu *p1=pfirst;p1!=NULL;p1=p1->pnext){
        cout<<p1->name<<"-> ";
        
    }
    cout<<endl;
}




int main(){
    //test();
     stu stu1("aya");
    
    stu1.show_currentList();
    stu stu3("abc");
    stu1.show_currentList();
    stu stu4("aaafa");
    stu1.show_currentList();
    return 0;
}