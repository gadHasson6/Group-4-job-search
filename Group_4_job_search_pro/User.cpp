#include "User.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor without parameters
User::User() : typeOfUser('\0'), name(""), id(0), password(""), feedback(""), rating(0) {}

// Constructor with parameters
User::User(char inputTypeOfUser, const string &inputName, long inputId, const string &inputPassword,
           const string &inputFeedback)
        : typeOfUser(inputTypeOfUser), name(inputName), id(inputId), password(inputPassword), feedback(inputFeedback),
          rating(0) {}

// Copy constructor
User::User(const User &other)
        : typeOfUser(other.typeOfUser), name(other.name), id(other.id), password(other.password),
          feedback(other.feedback), rating(other.rating) {}

// Destructor
User::~User() {}

// Setters
void User::setUserData(char inputTypeOfUser, const string &inputName, long inputId, const string &inputPassword,
                       const string &inputFeedback) {
    typeOfUser = inputTypeOfUser;
    name = inputName;
    id = inputId;
    password = inputPassword;
    feedback = inputFeedback;
    rating = 0;
}

void User::setRating(int inputRating) {
    rating = inputRating;
}

void User::setFeedback(const string &inputFeedback) {
    feedback = inputFeedback;
}

char User::getTypeOfUser() const {
    return this->typeOfUser;
}

long User::getId() const {
    return this->id;
}

const string &User::getPassword() const {
    return this->password;
}

const string &User::getName() const {
    return this->name;
}

const string &User::getFeedback() const {
    return this->feedback;
}

int User::getRating() const {
    return this->rating;
}

void User::employerRegistration() {
    cout << "Employer Registration:" << endl;
    // Input details
    string firstName, lastName;
    string company, inputEmail, phone;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Company Name: ";
    cin.ignore();
    getline(cin, company);
    cout << "Enter Email: ";
    cin >> inputEmail;
    cout << "Enter Contact Phone Number: ";
    cin >> phone;
    // Validate input and handle incorrect input
    while (inputEmail.find('@') == string::npos) {
        cout << "Invalid email format. Please enter a valid email: ";
        cin >> inputEmail;
    }
    // Set user data
    setUserData('E', firstName + " " + lastName, id, password, "");
    this->companyName = company;
    this->employerEmail = inputEmail;
    this->contactPhoneNumber = phone;
    rating = 0;
}


void User::employerLogin() {
    cout << "Employer Login: " << endl;
    // Input ID and password
    long enteredId;
    string enteredPassword;
    cout << "Enter ID: ";
    cin >> enteredId;
    cout << "Enter Password: ";
    cin >> enteredPassword;
    // Validate login credentials and handle incorrect input
    while (!isLoginValid(enteredId, enteredPassword)) {
        cout << "Invalid login credentials. Please try again." << endl;
        cout << "Enter ID: ";
        cin >> enteredId;
        cout << "Enter Password: ";
        cin >> enteredPassword;
    }
    cout << "Employer logged in successfully!" << endl;
}


void User::candidateRegistration() {
    cout << "Candidate Registration:" << endl;
    // Input details
    string inputCandidateEmail, inputCandidatePhone, inputResidence, inputSpecialization, inputDescription;
    int inputAge;
    char inputGender;
    cout << "Enter Email: ";
    cin >> inputCandidateEmail;
    cout << "Enter Contact Phone Number: ";
    cin >> inputCandidatePhone;
    cout << "Enter Age: ";
    cin >> inputAge;
    cout << "Enter Gender (M/F): ";
    cin >> inputGender;
    cout << "Enter Place of Residence: ";
    cin.ignore();
    getline(cin, inputResidence);
    cout << "Enter Specialization: ";
    getline(cin, inputSpecialization);
    cout << "Enter description (up to 200 characters): ";
    getline(cin, inputDescription);
    // Validate input and handle incorrect input
    while (inputCandidateEmail.find('@') == string::npos) {
        cout << "Invalid email format. Please enter a valid email: ";
        cin >> inputCandidateEmail;
    }
    // Set user data
    setUserData('C', name, id, password, "");
    this->candidateEmail = inputCandidateEmail;
    candidatePhoneNumber = inputCandidatePhone;
    this->age = inputAge;
    gender = (toupper(inputGender) == 'M') ? "Male" : "Female";
    this->residence = inputResidence;
    this->specialization = inputSpecialization;
    // Limiting narrative to 200 characters
    if (inputDescription.length() <= 200) {
        this->description = inputDescription;
    } else {
        cout << "Description exceeds the limit of 200 characters. Truncating." << endl;
        this->description = inputDescription.substr(0, 200);
    }
    rating = 0;
}


void User::candidateLogin() {
    cout << "Candidate Login:" << endl;
    // Input ID and password
    long enteredId;
    string enteredPassword;
    cout << "Enter ID: ";
    cin >> enteredId;
    cout << "Enter Password: ";
    cin >> enteredPassword;
    // Validate login credentials and handle incorrect input
    while (!isLoginValid(enteredId, enteredPassword)) {
        cout << "Invalid login credentials. Please try again." << endl;
        cout << "Enter ID: ";
        cin >> enteredId;
        cout << "Enter Password: ";
        cin >> enteredPassword;
    }
    cout << "Candidate logged in successfully!" << endl;
}


bool User::isLoginValid(long enteredId, const string &enteredPassword) const {
    return (enteredId == id && enteredPassword == password);
}

void User::limitFeedbackLength(int maxLength = 500) {
    if (feedback.length() > maxLength) {
        cout << "Feedback length exceeds the limit. Truncating." << endl;
        feedback = feedback.substr(0, maxLength);
    }
}

void User::rateSystem() {
    cout << "Please rate the system from 1 to 5:" << endl;
    cout << "1 - Excellent" << endl;
    cout << "2 - Very Good" << endl;
    cout << "3 - Good" << endl;
    cout << "4 - Requires Improvement" << endl;
    cout << "5 - Bad" << endl;

    do {
        cout << "Enter your rating: ";
        cin >> rating;

        if (rating < 1 || rating > 5) {
            cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
        }

    } while (rating < 1 || rating > 5);
}