#include <iostream>
using namespace std;
// 日期类
class Date {
private:
    int year, month, day;
    static const int daysInMonth[13];

public:
    // 构造函数
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // 判断是否是闰年
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // 计算该日期是该年的第几天
    int dayOfYear() const {
        int totalDays = day;
        for (int i = 1; i < month; i++) {
            totalDays += daysInMonth[i];
            if (i == 2 && isLeapYear(year)) {
                totalDays++;  // 如果是闰年，2月多一天
            }
        }
        
        return totalDays;
    }

    int operator-(const Date &day) const;           //计算两个输入日期相差的天数
    friend void  operator<<(ostream &os,Date &day); //打印日期
   
    void comm_day() const;                //某个日期距离纪念日还差天数


    ~Date(){};

};

int Date::operator-(const Date &day)const{
    int minus_day;
    minus_day=this->dayOfYear()-day.dayOfYear();
    
    return abs((day.year-year)*365+day.dayOfYear()-dayOfYear());
    
     
}

void operator<<(ostream &os,Date &day){
    os << "The date " <<day.year << "/" << day.month << "/" << day.day << " is the " << day.dayOfYear() << "th day of the year " << day.year << ".\n";
    return;

}



void Date::comm_day()const{
    int day,month;
    cout<<"please enter your comm day:"<<endl;
    cin>>month>>day;
    
    Date comm_day(0,month,day);
    if(this->dayOfYear()>comm_day.dayOfYear())//说明今年的纪念日已经过了
    {
       Date day_count(this->year+1,month,day);
       cout<<"This year's comm day has passed.."
           <<*this-day_count<<" days left till your comm_day..."<<endl;
    }
    else{ //今年的纪念日还没过
       Date day_count2(this->year,month,day);
       cout<<"This year's comm day ticking:"
       <<*this-day_count2<<" days..."<<endl;
    }

    //cout<<*this-comm_day<<" day left till your comm_day";

} 


const int Date::daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void test_count_days(){
    /*
    1.测试  friend void  operator<<(ostream &os,Date &day); 打印日期
    2.测试  int operator-(const Date &day) const;           计算两个输入日期相差的天数
    3.测试  int comm_day(const Date&) const;                距离距离纪念日还差几天
    */

   Date day1(2023,7,15);
   cout<<day1;          //测试1
   Date day2(2024,7,15);
   cout<<day2;

   cout<<"The 2 day minus is:"<<day2-day1<<endl;//测试2
   
   //测试3 测试某个日期(e.g 2023.7.15)与纪念日所差天数 判断今年还是明年 并判断剩下天数
   day1.comm_day();
   
  

    
}




int main() {
    test_count_days();
    

    return 0;
}
