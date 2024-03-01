//
// Created by ariel on 09/07/2023.
//
#include <ctime>
#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H


class Date {
private:
    int day;
    int month;
    int year;
    bool isCorrectDay (int inputDay);
    bool isCorrectMonth(int inputMonth);
    bool isCorrectYear(int inputYear);
public:
    Date ();
    Date(int inputDay, int inputMonth, int inputYear);
    int getDay ();
    int getMonth();
    int getYear();
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
};


#endif //UNTITLED_DATE_H
