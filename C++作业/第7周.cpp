#include  <iostream>
#include <ctime>
using namespace std;

const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Tdate{

    
    friend ostream& operator<<( ostream &,const Tdate &);
    int year,month,day;
public:
    Tdate(int,int,int);
    Tdate();
    Tdate(const Tdate &);
    ~Tdate();
    int count_days() const;
    int isLeapYear()const;
    
    int operator-(const Tdate &);
    Tdate Findate(Tdate *p,int);
};




Tdate::Tdate(){}

Tdate::Tdate(int m,int d,int year=0)
{
    this->month=m;
    this->day=d;
    this->year=year;
}

Tdate::~Tdate(){

}

Tdate::Tdate(const Tdate &t){
    year=t.year;
    month=t.month;
    day=t.day;

}

int Tdate::count_days()const{
    int sum_days=0;
    for(int i=0;i<month;i++){
        sum_days+=days[i];
    }
    if(isLeapYear()&&month>=3){
        sum_days++;
    }
    sum_days+=day;
    //cout<<endl<<"sum_days are"<<sum_days<<endl;
    //cout<<"This day is the "<<sum_days<<"th day of current year"<<endl;
    return sum_days;
    
    
}

ostream& operator<<(ostream &os,const Tdate &t){
    os<<t.year<<"_"<<t.month<<"_"<<t.day<<endl;
    return os;

}

int Tdate::isLeapYear()const{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}


// int Tdate::operator-(Tdate &t){

    
//     return abs((year-t.year)*365+ count_days()-t.count_days());
// }

int Tdate::operator-(const Tdate &t){
    
    if(count_days()<t.count_days())
    {return abs(count_days()-t.count_days());}
    return abs(365-(count_days()-t.count_days()));
    

}

/*---------------------------------------------------------*/

Tdate Tdate::Findate(Tdate *p,int n){
    int min=9999;
    int index=0;
    for(int i=0;i<n;i++){
        int minus=this->operator-(*(p+i)) ;
        //cout<<"p["<<i<<"]:"<<minus<<endl;
        if(minus<min){
            min=minus;
            index=i;
        }

    }
    return *(p+index);
    

}


void test_findate(){
    //初始化纪念日对象数组
    Tdate *comm_day = new Tdate[3];


    for(int i=0;i<3;i++){
        int m,n;
        cout<<"please enter in month and day"<<endl;
        cin>>m>>n;
        comm_day[i]=Tdate(m,n);
    }
    

    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int now_month = 1 + ltm->tm_mon;     
    int now_day = ltm->tm_mday;
    Tdate currentDate( now_month, now_day);
    
    Tdate closest_day=currentDate.Findate(comm_day,3);
    
   

    cout<<"the closese day is:"<<closest_day<<"having "<<currentDate-currentDate.Findate(comm_day,3)<<"days left";
    
    delete []comm_day;
     
}




int main(){
    //test_day();
   
    test_findate();
    

    return 0;
}