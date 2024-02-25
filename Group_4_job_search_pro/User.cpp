//
// Created by LENOVO on 21/02/2024.
//

#include "User.h"

long User::getId() {
    return this->id;
}

 string User::getName() {
    return this->name;
}

int User::getPassword() {
    return this-> password;
}

string User::getFeedback() {
    return this-> feedback;
}


void User::changeFeedback(string newFeedback) {
    this->feedback=newFeedback;
}


void User::changePassword(int newPassword) {
    this->password=newPassword;
}

void User::setName(string newName) {
    this->name=newName;
}

void User::setId(int newId) {
    this->id=newId;
}

void User::setPassword(int newPassword) {
    this->password=newPassword;
}

void User::setFeedback(std::string newFeedback) {
    this->feedback=newFeedback;
}