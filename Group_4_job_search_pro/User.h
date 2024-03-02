//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_USER_H
#define GROUP_4_JOB_SEARCH_PRO_USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string name;
    long id;
    string email;
    string password;
    string phoneNumber;
    int rating;
    string feedback;

public:
    User(); // Constructor without parameters
    // Constructor with parameters
    User(const string& inputName, const long inputId, const string& inputPassword, const string& inputEmail,
         const string& inputPhoneNumber, int inputRating,
         const string& inputFeedback);
    User(const User& other); // Copy constructor
    ~User(); // Destructor, TODO: how to deallocate what was allocated in constructor, maybe not needed.

    // Setters
    bool setName(const string& inputName);
    bool setId(long inputId);
    bool setEmail(const string& inputEmail);
    bool setPassword(const string& inputPassword);
    bool setPhoneNumber(const string& inputPhoneNumber);
    bool setRating(int inputRating);
    bool setFeedback(const string& inputFeedback);

    // Getters
    string getName() const;
    long getId() const;
    string getEmail() const;
    string getPassword() const;
    string getPhoneNumber() const;
    int getRating() const;
    string getFeedback() const;


    // Validators
    bool isIdValid(long inputId) const;
    bool isEmailValid(string& inputEmail) const;
    bool isPasswordValid(string& inputPassword) const;
    bool isPhoneNumValid(string& inputPoneNum) const;
    bool isRatingValid(int inputRating) const;


    // Helpers
    bool isStringBetween(const string& inputString, int min, int max) const;
    bool isBigLetters(const string& inputString) const;
    bool isSmallLetters(const string& inputString) const;
    bool isDigits(const string& inputString) const;
};


#endif //GROUP_4_JOB_SEARCH_PRO_USER_H