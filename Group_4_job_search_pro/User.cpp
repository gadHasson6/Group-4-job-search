//
// Created by LENOVO on 21/02/2024.
//

#include "User.h"

// Default constructor
User::User() : id(0), rating(0) {}

// Constructor with parameters
User::User(const string &inputName, long inputId, const string &inputPassword, const string &inputEmail,
           const string &inputPhoneNumber, const string &inputResidence, int inputRating,
           const string &inputFeedback)
        : name(inputName), id(inputId), password(inputPassword), email(inputEmail),
          phoneNumber(inputPhoneNumber), residence(inputResidence), rating(inputRating),
          feedback(inputFeedback) {}

// Copy constructor
User::User(const User &other)
        : name(other.name), id(other.id), password(other.password), email(other.email),
          phoneNumber(other.phoneNumber), residence(other.residence), rating(other.rating),
          feedback(other.feedback) {}

// Destructor
User::~User() {}

// Setters
void User::setName(const string &inputName) {
    this->name = inputName;
}

void User::setId(long inputId) {
    this->id = inputId;
}

void User::setEmail(const string &inputEmail) {
    this->email = inputEmail;
}

void User::setPassword(const string &inputPassword) {
    this->password = inputPassword;
}

void User::setPhoneNumber(const string &inputPhoneNumber) {
    this->phoneNumber = inputPhoneNumber;
}

void User::setResidence(const string &inputResidence) {
    this->residence = inputResidence;
}

void User::setRating(int inputRating) {
    this->rating = inputRating;
}

bool User::setFeedback(const string &inputFeedback) {
    if(isStringBetween(inputFeedback, 3, 50)){
        this->feedback = inputFeedback;
        cout << "The feedback was successfully saved, thank you very much!\n";
        return true;
    } else {
        cout << "Your feedback is not the appropriate length\n";
        return false;
    }
}

// Getters
long User::getId() const {
    return this->id;
}

string User::getName() const {
    return this->name;
}

string User::getEmail() const {
    return this->email;
}

string User::getPassword() const {
    return this->password;
}

string User::getPhoneNumber() const {
    return this->phoneNumber;
}

string User::getResidence() const {
    return this->residence;
}

int User::getRating() const {
    return this->rating;
}

string User::getFeedback() const {
    return this->feedback;
}

// Validators
bool User::isIdValid(long inputId) const {
    string idString = to_string(inputId);
    if (idString.length() != 9) {
        return false;
    }
    for (size_t i = 0; i < idString.length(); ++i) {
        char c = idString[i];
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool User::isEmailValid(string &inputEmail) const {
    size_t atSymbolPosition = inputEmail.find('@');
    // Check if "@" exists
    if (atSymbolPosition == string::npos) {
        return false;
    }
    // Check if "@" is not the first character and not the last character
    if (atSymbolPosition == 0 || atSymbolPosition == inputEmail.length() - 1) {
        return false;
    }
    if (!isStringBetween(inputEmail, 3, 50)){
        return false;
    }
    return true;
}

bool User::isPasswordValid(string &inputPassword) const {
    if (isStringBetween(inputPassword, 6, 12)) {
        return (isBigLetters(inputPassword) && isSmallLetters(inputPassword) && isDigits(inputPassword));
    }
    return false;
}

bool User::isRatingValid(int inputRating) const {
    if (inputRating >= 1 && inputRating <= 5)
        return true;
    else
        return false;
}

// Helpers
bool User::isStringBetween(const string &inputString, int min, int max) const {
    int length = inputString.length();
    return (length >= min && length <= max);
}

bool User::isBigLetters(const string &inputString) const {
    for (size_t i = 0; i < inputString.length(); ++i) {
        char c = inputString[i];
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
    }
    return false;
}

bool User::isSmallLetters(const string &inputString) const {
    for (size_t i = 0; i < inputString.length(); ++i) {
        char c = inputString[i];
        if (c >= 'a' && c <= 'z') {
            return true;
        }
    }
    return false;
}

bool User::isDigits(const string &inputString) const {
    for (size_t i = 0; i < inputString.length(); ++i) {
        char c = inputString[i];
        if (c >= '0' && c <= '9') {
            return true;
        }
    }
    return false;
}

bool User::isPhoneNumValid(std::string &inputPoneNum) const {
    if (isStringBetween(inputPoneNum, 10, 10) && isDigits(inputPoneNum))
        return true;
    else return false;
}}