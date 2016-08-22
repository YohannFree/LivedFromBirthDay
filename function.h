//
// Created by Administrator on 2016/7/15.
//

#ifndef LIVEDFROMBIRTHDAY_FUNCTION_H
#define LIVEDFROMBIRTHDAY_FUNCTION_H

#endif //LIVEDFROMBIRTHDAY_FUNCTION_H

#include <iostream>
#include <ctime>

using namespace std;
struct Data {
    int year;
    int month;
    int day;
};

//闰年
bool Isleap(struct Data data) {
    return (data.year % 4 == 0 && data.year % 100 != 0 || data.year % 400 == 0);
}

//闰年2
bool Isleap2(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

//计算到指定时间过了多少天
int SumDay(struct Data data) {
    int sum = 0;
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Isleap(data)) {
        month[1] = 29;
        for (int count = 1; count < data.month; count++) {
            sum = sum + month[count];
        }
    }
    else {
        month[1] = 28;
        for (int count = 1; count < data.month; count++) {
            sum = sum + month[count];
        }
    }

    return sum + data.day;

}

//计算这一年剩多少天
int LastDays(struct Data data) {
    int allDays = 0;
    int lasDays = 0;
    if (Isleap(data)) {
        allDays = 366;
    }
    else
        allDays = 365;
    lasDays = (allDays - SumDay(data));
    return lasDays;
}

//除了首尾之外的时间总和
int SumAge(struct Data data1, struct Data data2) {
    int alldata = 0;
    int temp1 = data1.year + 1;
    int temp2 = data2.year;
    while (temp1 < temp2) {
        if (Isleap2(temp1))
            alldata += 366;
        else
            alldata += 365;
        temp1++;
    }
    return alldata;
}

int function() {
    time_t timer;
    time(&timer);
    tm *t_tm = localtime(&timer);


    int year1 = t_tm->tm_year + 1900;
    int month1 = t_tm->tm_mon + 1;
    int day1 = t_tm->tm_mday;


    struct Data data1 = {year1, month1, day1};//将当前时间（年月日）存入结构体
    struct Data data2;
    int n;
    cout << "please enter your birthday's year" << endl;
    while (cin >> n) {
        if (n < 0 || n > year1) {
            cout << "The computer can't know you enter ,please enter again:" << endl;

        } else {
            data2.year = n;
            break;
        }

    }
    cout << "please enter your birthday's month" << endl;
    while (cin >> n) {
        if (n < 0 || n > 12) {
            cout << "The computer can't know you enter ,please enter again:" << endl;
        } else {
            data2.month = n;
            break;
        }
    }
    cout << "please enter your birthday's day" << endl;
    while (cin >> n) {
        if (n < 0 || n > 31) {
            cout << "The computer can't know you enter ,please enter again:" << endl;
        } else {
            data2.day = n;
            break;
        }
    }

    int sumdays = 0;
    if (data2.year < data1.year)
        sumdays = LastDays(data2) + SumDay(data1) + SumAge(data2, data1);
    else
        sumdays = SumDay(data1) - SumDay(data2);
    cout << "you have alive " << sumdays << " days!" << endl;
    getchar();
    getchar();

    return sumdays;
}