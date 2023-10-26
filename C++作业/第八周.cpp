#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;
#define count 10


class stu{
    int grade_eng;
    int grade_math;
    int grade_ie;
    int id;
    int grade_sum;
    int grade_avg;
    static int stu_num;
    static int  max_totalscore;
    static int total_avg;
    
    friend ostream & operator<<(ostream &,stu &);
    friend int get_reg_num(stu&);
    friend void test();
    friend void set_stu_inf(int);

public:
    stu(int,int,int,int);
    stu();
    ~stu();
    int sum();
    int avg();
    int& get_reg_num();
   
};

int stu::stu_num=0;
int stu::max_totalscore=0;
int stu::total_avg=0;

stu::stu(){}

stu::stu(int id,int eng,int math,int ie):id(id),grade_eng(eng),grade_math(math),grade_ie(ie)
{   
    grade_sum=sum();
    grade_avg=avg();
    stu_num++;
    
}

stu::~stu(){
    stu_num--;
}

int stu::sum(){

    return grade_eng+grade_ie+grade_math;
}

int stu::avg(){
    return (sum()/3);
}
 
void set_stu_inf(int id){
    cout<<"which stu you want to perform"<<endl;

}




ostream & operator<<(ostream & os,stu &st){
        os<<st.id<<" "
        // <<"student's grade:"<<endl
        <<"|"<<st.grade_math<<" "
        <<"|"<<st.grade_eng<<" "
        <<"|"<<st.grade_ie<<" "
        <<"|"<<st.sum()<<" "
        <<"|"<<st.avg()<<" "<<endl;

     return os;
}//print student's info





int & stu::get_reg_num(){
    return  id;
}

int get_reg_num(stu &st){
    return st.id;
}



void show_info(stu *p){
    for(int i=0;i<count;i++)
    {
        cout<<p[i]<<endl;
    }
    
}

void show(){
    cout<<"1.show the Info"<<endl
        <<"2.modify the Info"<<endl
        <<"0.exit"<<endl;

}

void show2(){
    
    cout<<"which you wanna modify"<<endl
        <<"1.math"<<endl
        <<"2.english"<<endl
        <<"3.IT"<<endl;
}

void test(){
    
    
    int sum1=0;
    srand((unsigned)time(NULL));
    stu * p_st=new stu[count];
    for(int i=0;i<count;i++){
        p_st[i]. id=23121100+i;
        p_st[i]. grade_eng=rand()%60+40;
        p_st[i].grade_ie=rand()%60+40;
        p_st[i]. grade_math=rand()%60+40;
        sum1+=p_st[i].avg();
        if(p_st[i].sum()>stu::max_totalscore){
        stu::max_totalscore=p_st[i].sum();
         
    }
        cout<<p_st[i]<<endl;
    }
    stu::total_avg=sum1/count;
    
   
    cout<<"max_total_grade:"<<p_st[1].max_totalscore<<endl;
    cout<<"class's average score: "<<stu::total_avg<<endl;
    

    int id;
    cout<<"which stu you want to perform"<<endl;
    cin>>id;
    for(int i=0;i<count;i++){
        if(p_st[i].get_reg_num()==id){
            cout<<p_st[i];
            break;
        }
    }
    
    int flag=1;
    show();
    cout<<"what you wanna do"<<endl;

    cin>>flag;
    while(flag){
        switch (flag)
        {
        case 1:
            show_info(p_st);
            break;
        case 2:
            cout<<"who you wanna modify,enter his/her ID"<<endl;
            int ID;
            cin>>ID;
            int index;
            for(int i=0;i<count;i++){
                if(p_st[i].id==ID){
                    index=i;
                    break;
                }
            }//search the guy;
            show2();
            int flag2;
            cin>>flag2;
            switch (flag2)
            {
            /*
            void show2(){
            cout<<"which you wanna modify"<<endl
                <<"1.math"<<endl
                <<"2.english"<<endl
                <<"3.IT"<<endl;
            }*/
            case 1:
                cout<<"please enter the score:"<<endl;
                int new_grade;
                cin>>new_grade;

                p_st[index].grade_math=new_grade;
                break;
            case 2:
                cout<<"please enter the score:"<<endl;
                int new_grade1;
                cin>>new_grade1;

                p_st[index].grade_eng=new_grade1;
                break;
            
            case 3:
                cout<<"please enter the score:"<<endl;
                int new_grade2;
                cin>>new_grade2;

                p_st[index].grade_ie=new_grade2;
                break;
        
            default:
                break;
            }

            /* modify the Info */
            break;
        
        case 0:
            /* exit */
            break;
        default:
            break;
        }
        show();
        cin>>flag;
    }

    delete []p_st;


    

}







int main(){
   
    test();
    
}