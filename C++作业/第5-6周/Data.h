
#ifndef DATA_H_
#define DATA_H_
#include <string>
using namespace std;


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


















#endif


#include <iostream>

// 日期类


const int Date::daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year, month, day;
    std::cout << "Enter year (e.g. 2023): ";
    std::cin >> year;

    std::cout << "Enter month (1-12): ";
    std::cin >> month;

    std::cout << "Enter day (1-31): ";
    std::cin >> day;

    Date date(year, month, day);
    std::cout << "The date " << year << "-" << month << "-" << day << " is the " << date.dayOfYear() << "th day of the year " << year << ".\n";

    return 0;
}
