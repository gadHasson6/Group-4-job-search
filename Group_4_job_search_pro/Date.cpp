//
// Created by LENOVO on 29/02/2024.
//

#include "Date.h"


//default constructor:
Date::Date(){
    std::time_t rawtime;
    std::tm* timeinfo;
    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}

//constructor:
Date::Date(int inputDay, int inputMonth, int inputYear) {
    if (isCorrectMonth(inputMonth)){
        month=inputMonth;
    }
    else {
        cout<<"Error! The month entered is not in the range"<<endl;
    }
    if (isCorrectDay(inputDay)){
        day=inputDay;
    }
    else {
        cout<<"Error! The day entered is not in the range"<<endl;
    }
    if (isCorrectYear(inputYear)){
        year=inputYear;
    }
    else {
        cout<<"Error! The year entered is not in the range"<<endl;
    }
}

//get day:
int Date::getDay() {
    return day;
}

//get month:
int Date::getMonth() {
    return month;
}

//get year:
int Date::getYear() {
    return year;
}

//This function check if the year entered is correct
bool Date::isCorrectYear(int inputYear) {
    if (inputYear<=2023){
        return true;
    }
    else {
        return false;
    }
}

//This function check if the month entered is correct
bool Date::isCorrectMonth(int inputMonth) {
    if (inputMonth<=12 && inputMonth>=1){
        return true;
    }
    else {
        return false;
    }
}

//This function check if the day entered is correct
bool Date::isCorrectDay(int inputDay) {
    switch (month) {
        case 1:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 2:
            if (inputDay >= 1 && inputDay <= 28) {
                return true;
            }
            break;
        case 3:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 4:
            if (inputDay >= 1 && inputDay <= 30) {
                return true;
            }
            break;
        case 5:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 6:
            if (inputDay >= 1 && inputDay <= 30) {
                return true;
            }
            break;
        case 7:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 8:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 9:
            if (inputDay >= 1 && inputDay <= 30) {
                return true;
            }
            break;
        case 10:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        case 11:
            if (inputDay>= 1 && inputDay <= 30) {
                return true;
            }
            break;
        case 12:
            if (inputDay >= 1 && inputDay <= 31) {
                return true;
            }
            break;
        default:
            return false;
    }
    return false;
}

// This function redefines a day
void Date::setDay(int inputDay) {
    if(isCorrectDay(inputDay)) {
        day = inputDay;
    }
    else {
        cout<<"Error! The day entered is not in the range"<<endl;
    }
}

// This function redefines a month
void Date::setMonth(int inputMonth) {
    if(isCorrectMonth(inputMonth)){
        month=inputMonth;
    }
    else {
        cout<<"Error! The month entered is not in the range"<<endl;
    }
}

// This function redefines a year
void Date::setYear(int inputYear) {
    if(isCorrectYear(inputYear)){
        year=inputYear;
    }
    else {
        cout<<"Error! The year entered is not in the range"<<endl;
    }
}


//This function prints the date in the form dd/mm/yyyy
void Date::printDate() const{
    if(day>=1 && day<=9){
        cout<<"0"<<day<<"/";
    }
    else {
        cout<<day<<"/";
    }
    if(month>=1 && month<=9){
        cout<<"0"<<month<<"/";
    }
    else {
        cout<<month<<"/";
    }
    cout<<year<<endl;
}

//This function prints the name of the month entered
void Date::printNameOfMonth() {
    cout<<"your month is: "<<endl;
    switch (month) {
        case 1:
            cout<<"January"<<endl;
            break;
        case 2:
            cout<<"February"<<endl;
            break;
        case 3:
            cout<<"March"<<endl;
            break;
        case 4:
            cout<<"April"<<endl;
            break;
        case 5:
            cout<<"May"<<endl;
            break;
        case 6:
            cout<<"June"<<endl;
            break;
        case 7:
            cout<<"July"<<endl;
            break;
        case 8:
            cout<<"August"<<endl;
            break;
        case 9:
            cout<<"September"<<endl;
            break;
        case 10:
            cout<<"October"<<endl;
            break;
        case 11:
            cout<<"November"<<endl;
            break;
        case 12:
            cout<<"December"<<endl;
            break;
    }
}

//This function checks if it is a leap year
bool Date::checkIfLeapYear() {
    if (year%4==0){
        if(year%100==0){
            if(year%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else {
        return false;
    }
}

//This function returns the number of days in the month
int Date::daysInMonth() {
    switch (month) {
        case 1:
            return 31;
            break;
        case 2:
            if(checkIfLeapYear()){
                return 29;
            }
            return 28;
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
    }
}

//This function will calculate the next day
void Date::theNextDay() {
    if (day==daysInMonth()) {
        day=1;
        if(month==12){
            month=1;
            year++;
        }
        else{
            month++;
        }
    }
    else {
        day++;
    }
}

Date::~Date(){

};
#include "Date.h"

//operator ==
bool Date::operator==(const Date& other) const {
    return (day == other.day) && (month == other.month) && (year == other.year);
}

//operator <
bool Date::operator<(const Date &other) const {
    // Compare years
    if (year > other.year) {
        return true;
    } else if (year < other.year) {
        return false;
    }

    // If years are equal, compare months
    if (month > other.month) {
        return true;
    } else if (month < other.month) {
        return false;
    }

    // If years and months are equal, compare days
    return day > other.day;
}


//operator >
bool Date::operator>(const Date& other) const {
    // Compare years
    if (year > other.year) {
        return true;
    } else if (year < other.year) {
        return false;
    }

    // If years are equal, compare months
    if (month > other.month) {
        return true;
    } else if (month < other.month) {
        return false;
    }

    // If months are equal, compare days
    return day > other.day;
}