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
};

const int Date::daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// int main() {
//     int year, month, day;
//     std::cout << "Enter year (e.g. 2023): ";
//     std::cin >> year;

//     std::cout << "Enter month (1-12): ";
//     std::cin >> month;

//     std::cout << "Enter day (1-31): ";
//     std::cin >> day;

//     Date date(year, month, day);
//     std::cout << "The date " << year << "-" << month << "-" << day << " is the " << date.dayOfYear() << "th day of the year " << year << ".\n";

//     return 0;
// }

class elevator;

class person{
	friend class elevator;
	int weight;
	elevator* current_ele;
public:
	person(int,elevator);
	void go_into_ele();
	~person();
	
};

class elevator{
	
	int current_weight;
	int current_floor;
	int target_floor;
	int total_floor;
	int overweight;//限重
	int max_num_person;//限定人数
public:
	//friend person::go_into_ele();
	elevator(int max,int,int,int);
	~elevator();
	void go_upstairs(int);
	void go_downstairs(int);
	void show_current_floor();
	void choose_TargetFloor(int target);	
	
};

elevator::elevator(int total_floor,int max_weight,int max_people_num,int basement){
	this->max_num_person=max_people_num;
	this->overweight=max_weight;
	this->total_floor=total_floor;
	this->current_floor=basement;
	cout<<"当前电梯基本信息："<<endl
	<<"限重(kg)："<<this->overweight<<"  "
	<<"限员(人):"<<this->max_num_person<<"  "
	<<"电梯提供服务总楼层数(层):"<<this->total_floor<<endl;
	current_weight=0;
	
}

void elevator::choose_TargetFloor(int target){
	//判断电梯上下行 target：目标楼层
	cout<<"当前楼层为:"<<this->current_floor<<endl;
	if(target==0){
			cout<<"出电梯"<<endl;
		}
	if(target<0||target>this->total_floor){cout<<"楼层选择错误";return;}
    if (target<this->current_floor){
		this->go_downstairs(target);
	}
	
	else{
		this->go_upstairs(target);
	}	
}

elevator::~elevator(){};


void elevator::go_upstairs(int target){
	cout<<"电梯上行..."<<endl;
	this->current_floor=target;
	
}

void elevator::go_downstairs(int target){
	cout<<"电梯下行..."<<endl;
	this->current_floor=target;
	
}

void test_elevator(){
	elevator ele(6,200,10,1);
	int flag=1;
	while(flag){
	cout<<"你希望去的楼层是:"<<endl;
	int target;
	cin>>target;
	switch (target) {
		case 0:
			cout<<"出电梯"<<endl;
			flag=0;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			ele.choose_TargetFloor(target);
			break;
		default:
			
			break;
	}
	ele.show_current_floor();
	}

}

void elevator::show_current_floor(){
	cout<<"arriving at  "<<this->current_floor<<"  floor"<<endl;
}




person::person(int weight,elevator elevator1){
	current_ele=new elevator(elevator1);
	this->weight=weight;	
}

person::~person(){
	if(this->current_ele!=NULL){
		delete this->current_ele;
		this->current_ele=NULL;
	}
}

void person::go_into_ele(){
	
}



void test_day(){
    int year, month, day;
    std::cout << "Enter year (e.g. 2023): ";
    std::cin >> year;

    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    std::cout << "Enter day (1-31): ";
    std::cin >> day;

    Date date(year, month, day);
    std::cout << "The date " << year << "-" << month << "-" << day << " is the " << date.dayOfYear() << "th day of the year " << year << ".\n";
}

int main(){

	test_elevator();
    test_day();
	
		
	
	return 0;
}
