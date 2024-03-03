//
// Created by LENOVO on 29/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_DATE_H
#define GROUP_4_JOB_SEARCH_PRO_DATE_H
#include <ctime>
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date ();
    Date(int inputDay, int inputMonth, int inputYear);
    bool isCorrectDay (int inputDay);
    bool isCorrectMonth(int inputMonth);
    bool isCorrectYear(int inputYear);
    int getDay () const;
    int getMonth() const;
    int getYear() const;
    void setDay(int inputDay);
    void setMonth(int inputMonth);
    void setYear(int inputYear);
    void printDate() const;
    void printNameOfMonth();
    bool checkIfLeapYear();
    int daysInMonth();
    void theNextDay();
    ~Date();
    bool operator <(const Date& other) const;
    bool operator >(const Date& other)const;
    Date& operator = (const Date& other);
};



#endif //GROUP_4_JOB_SEARCH_PRO_DATE_H
