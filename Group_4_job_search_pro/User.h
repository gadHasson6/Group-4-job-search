#ifndef GROUP_4_JOB_SEARCH_PRO_USER_H
#define GROUP_4_JOB_SEARCH_PRO_USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
private:
    char typeOfUser;
    string name;
    long id;
    string password;
    string feedback;
    int rating;

    // Additional variables for employer
    string companyName;
    string employerEmail;
    string contactPhoneNumber;

    // Additional variables for candidate
    string candidateEmail;
    string candidatePhoneNumber;
    int age;
    string gender;
    string workExperience;
    string residence;
    string specialization;
    string description;
public:
    User(); // Constructor without parameters
    User(char inputTypeOfUser, const string& inputName, long inputId, const string& inputPassword, const string& inputFeedback); // Constructor with parameters
    User(const User& other); // Copy constructor
    ~User(); // Destructor

    // Setters
    void setUserData(char inputTypeOfUser, const string& inputName, long inputId, const string& inputPassword, const string& inputFeedback);
    void setFeedback(const string& inputFeedback);
    void setRating(int inputRating);

    // Getters
    char getTypeOfUser() const;
    long getId() const;
    const string& getPassword() const;
    const string& getName() const;
    const string& getFeedback() const;
    int getRating() const;

    // Employer-specific functions
    void employerRegistration();
    void employerLogin();

    // Candidate-specific functions
    void candidateRegistration();
    void candidateLogin();

    bool isLoginValid(long enteredId, const string& enteredPassword) const;
    void limitFeedbackLength(int maxLength);
    void rateSystem();
};


#endif //GROUP_4_JOB_SEARCH_PRO_USER_H
