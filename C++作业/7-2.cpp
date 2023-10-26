#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class stu{
    friend void search_ID(long int,stu*);
    long int ID;
    string name;
    int math_grade;
    int english_grade;
    friend ostream & operator<<(ostream&,const stu&);
    

public:
    stu(long int,string,int,int);
    ~stu();
    stu();
    int average();
    int sum();
    void print_stu_Info();
   

};

stu::stu(long int ID1,string name1,int math,int english):ID(ID1),name(name1),math_grade(math),english_grade(english)
{

}

stu::stu(){}
stu::~stu(){}

int stu::average(){
    return (math_grade+english_grade)/2;
}

int stu::sum(){
    return math_grade+english_grade;
}

ostream & operator<<(ostream& os,const stu& s){

    os<<s.ID
    <<" "<<s.name
    <<" "<<s.math_grade
    <<" "<<s.english_grade<<endl;
}


void search_ID(long int ID,stu* list){
    for(int i=0;i<3;i++)
    {
        if(ID==list[i].ID)
        {
            cout<<list[i]<<endl;
        }
    }
}

void test_stu(){
     stu* stu_list=new stu[3]
     {
        stu(23121122,"aya",90,90),
        stu(23121123,"miku",100,70),
        stu(23121124,"Lolita",80,88),
     };
    
    search_ID(23121122,stu_list);
    delete []stu_list;
}






int main(){
    
    test_stu();
    return 0;
}