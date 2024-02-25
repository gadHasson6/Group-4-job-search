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


void User::changeFeedback(int newFeedback) {
    this->feedback=newFeedback;
}

void User::changeName(int newName) {
    this->name=newName;
}


void User::changePassword(int newPassword) {
    this->password=newPassword;
}