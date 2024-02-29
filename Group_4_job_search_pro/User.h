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
//    string residence;
    int rating;
    string feedback;
    // int age; TODO: to add only if both will have
    // string gender; TODO: to add only if both will have

public:
    User(); // Constructor without parameters
    // Constructor with parameters, TODO: add int and gender if need
    User(const string& inputName, const long inputId, const string& inputPassword, const string& inputEmail,
         const string& inputPhoneNumber, const string& inputrResidence, int inputRating,
         const string& inputFeedback);
    User(const User& other); // Copy constructor
    ~User(); // Destructor, TODO: how to deallocate what was allocated in constructor, maybe not needed.

    // Setters
    void setName(const string& inputName);
    void setId(long inputId);
    void setEmail(const string& inputEmail);
    void setPassword(const string& inputPassword);
    void setPhoneNumber(const string& inputPhoneNumber);
    void setResidence(const string& inputrResidence);
    void setRating(int inputRating);
    bool setFeedback(const string& inputFeedback);
    // TODO: add setAge & setGender if needed

    // Getters
    string getName() const;
    long getId() const;
    string getEmail() const;
    string getPassword() const;
    string getPhoneNumber() const;
    string getResidence() const;
    int getRating() const;
    string getFeedback() const;
    // TODO: add getAge & getGender if needed

    // Validators
    bool isIdValid(long inputId) const;
    bool isEmailValid(string& inputEmail) const;
    bool isPasswordValid(string& inputPassword) const;
    bool isPhoneNumValid(string& inputPoneNum) const;
    bool isRatingValid(int inputRating) const;


    // Helpers
    // TODO: add isAgeValid & isGenderValid if needed
    bool isStringBetween(const string& inputString, int min, int max) const;
    bool isBigLetters(const string& inputString) const;
    bool isSmallLetters(const string& inputString) const;
    bool isDigits(const string& inputString) const;
};


#endif //GROUP_4_JOB_SEARCH_PRO_USER_H
