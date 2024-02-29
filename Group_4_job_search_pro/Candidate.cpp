//
// Created by LENOVO on 21/02/2024.
//

#include "Candidate.h"
using namespace std;

//Default constructor
Candidate::Candidate() : User() {
    this->resumePath="";
    this->appliedJobs=NULL;
    this->appliedJobSize=0;
    this->personalInformation="";
    this->age=0;
    this->residence="";
    this->gender='M';
    this->workExperience=0;
    this->specialty="";
}

//Constructor
Candidate::Candidate(string inputName, long inputId, string inputEmail, string inputPassword,
                     string inputPhoneNumber, int inputRating, string inputFeedback,
                     string inputResumePath, string inputPersonalInformation, int inputAge, char inputGender,
                     float inputWorkExperience, string inputSpecialty)
                     : User(inputName,inputId,inputPassword,inputEmail,inputPhoneNumber,inputRating,inputFeedback){
    this->appliedJobs=NULL;
    this->appliedJobSize=0;

    if (!setResumeFilePath(inputResumePath)){
        this->resumePath="";
    }
    if(!setPersonalInformation(inputPersonalInformation)){
        this->personalInformation="";
    }
    if(!setAge(inputAge)){
        this->age=0;
    }
    if (!setGender(inputGender)){
        this->gender='M';
    }
    if(!setResidence()){
        this->residence="";
    }
    if(!setWorkExperience(inputWorkExperience)){
        this->workExperience=0;
    }
    if(!setSpecialty(inputSpecialty)){
        this->specialty="";
    }
}

//Copy constructor
Candidate::Candidate(const Candidate &other) : User(other), resumePath(other.resumePath),
                                               appliedJobs(other.appliedJobs),
                                               personalInformation(other.personalInformation),
                                               age(other.age),
                                               gender(other.gender),
                                               residence(other.residence),
                                               workExperience(other.workExperience),
                                               specialty(other.specialty),
                                               appliedJobSize(other.appliedJobSize){

}

//get resume path
string Candidate::getResumePath() const {
    return this->resumePath;
}


//get personal information
string Candidate::getPersonalInformation() const{
    return this->personalInformation;
}


//get applied jobs
Apply **Candidate::getAppliedJob() const {
    return this->appliedJobs;
}


//get age
int Candidate::getAge() const {
    return this->age;
}


//get gender
char Candidate::getGender() const {
    return this->gender;
}


//get residence
string Candidate::getResidence() const {
    return this->residence;
}



//get work experience
float Candidate::getWorkExperience() const {
    return this->workExperience;
}


//get specialty
string Candidate::getSpecialty() const {
    return this->specialty;
}



//get applied job size
int Candidate::getAppliedJobSize() const {
    return this->appliedJobSize;
}

//set specialty
bool Candidate::setSpecialty(string inputSpecialty) {
    if(inputSpecialty.length()>=2 && inputSpecialty.length()<=25){
        this->specialty=inputSpecialty;
        return true;
    } else{
        return false;
    }
}

//set work experience
bool Candidate::setWorkExperience(float inputWorkExperience) {
    if (inputWorkExperience>=0 && inputWorkExperience<=100){
        this->workExperience=inputWorkExperience;
        return true;
    } else{
        return false;
    }
}


//set applied jobs
bool Candidate::setAppliedJobs(Apply **other, int size) {
    if(other!=NULL && size>0) {
        this->appliedJobSize=size;
        this->appliedJobs = new Apply *[size];
        for (int i = 0; i < size; i++) {
            appliedJobs[i] = other[i];
        }
        return true;
    }
    else{
        return false;
    }
}


//set residence
bool Candidate::setResidence() {
    cout<<"please choose your residence: "<<endl;
    int choice=0;
    cout<<"1. Northern District"<<endl;
    cout<<"2. Haifa District"<<endl;
    cout<<"3. Tel Aviv District"<<endl;
    cout<<"4. Central District"<<endl;
    cout<<"5. Jerusalem District"<<endl;
    cout<<"6. Southern District"<<endl;
    cin>>choice;
    if (!cin.fail() && choice >= 1 && choice <= 6){
        switch (choice) {
            case 1:{
                this->residence="Northern District";
                break;
            }
            case 2: {
                this->residence="Haifa District";
                break;
            }
            case 3: {
                this->residence="Tel Aviv District";
                break;
            }
            case 4: {
                this->residence="Central District";
                break;
            }
            case 5: {
                this->residence="Jerusalem District";
                break;
            }
            case 6: {
                this->residence="Southern District";
                break;
            }
        }
        return true;
    }
    else {
        // Clear the error flag
        cin.clear();
        // Discard invalid input from the input buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}

//set gender
bool Candidate::setGender(char inputGender) {
    if(inputGender=='W' || inputGender=='w'){
        this->gender='W';
        return true;
    }
    if(inputGender=='M' || inputGender=='m'){
        this->gender='M';
        return true;
    }
    else {
        return false;
    }
}


//set age
bool Candidate::setAge(int inputAge) {
    if(inputAge>=1 && inputAge<=120){
        this->age=inputAge;
        return true;
    } else{
        return false;
    }
}


//set resume path
bool Candidate::setResumeFilePath(const string& newResumePath) {
    try {
        // Basic path validation
        if (std::filesystem::exists(newResumePath) &&
            std::filesystem::is_regular_file(newResumePath) &&
            newResumePath.length() < 255) {
            this->resumePath = newResumePath;
            std::cout << "Resume path updated successfully!" << std::endl;
            return true; // Indicate success
        } else {
            std::cout << "Invalid resume path." << std::endl;
            resumePath="";
            return false; // Indicate failure
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return false; // Indicate failure
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return false; // Indicate failure
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
        return false; // Indicate failure
    }
}


//set personal information
bool Candidate::setPersonalInformation(string newPersonalInformation) {
    if(newPersonalInformation.length()>50){
        cout<<"Personal information can't be more than 50 chars. "<<endl;
        return false;
    }
    else {
        personalInformation = newPersonalInformation;
        return true;
    }
}


//tips for resume
void Candidate::printTipsForResume() {
    cout<<"Here are some tips for writing your resume: "<<endl;
    cout<<"1- Include your full name, phone number, email address..\n"
          "Ensure that your contact information is current and professional."<<endl;
    cout<<"2- Write a concise and targeted objective or summary highlighting your career goals and key qualifications."<<endl;
    cout<<"3- Use reverse chronological order for your work history.\n"
          "Include your job title, company name, location, and dates of employment.\n"
          "Provide a brief description of your responsibilities and achievements in each role."<<endl;
    cout<<"4- Mention your degree, major, school name, graduation date, and any relevant honors or awards."<<endl;
    cout<<"5- Keep your resume concise and ideally limit it to one page."<<endl;
    cout<<"6- Check for typos, grammatical errors, and formatting issues."<<endl;
}


//print
void Candidate::printThisCandidateInfo() const {
    cout<<"Candidate details: "<<endl;
    cout<<"Name: "<<this->getName()<<endl;
    cout<<"Id: "<<this->getId()<<endl;
    cout<<"Email: "<<this->getEmail()<<endl;
    cout<<"Phone number: "<<this->getPhoneNumber()<<endl;
    cout<<"Resume path: "<<this->getResumePath()<<endl;
    cout<<"Age: "<<this->getAge()<<endl;
    cout<<"Gender: "<<this->getGender()<<endl;
    cout<<"Personal information: "<<this->getPersonalInformation()<<endl;
    cout<<"Residence: "<<this->getResidence()<<endl;
    cout<<"Work experience: "<<this->getWorkExperience()<<endl;
    cout<<"Specialty: "<<this->getSpecialty()<<endl;
}


//add apply
void Candidate::addApply(const Apply *&addMe) { //need to finish this function
    for (int i=0; i<appliedJobSize; i++){
    }
}

//edit name
void Candidate::editName() {
    string newName = "";
    cout<<"Your current name is: "<< this->getName()<<endl;
    while (true) {
        cout << "Enter the new name (no longer than 20 letters): " << endl;
        getline(cin, newName); // read the entire line

        if (newName.length() > 20) {
            cout << "Name cannot be longer than 20 letters." << endl;

            int choice = 0;
            cout << "Please choose:" << endl;
            cout << "1. Choose a new name" << endl;
            cout << "2. Stay with the existing name" << endl;
            cin >> choice;

            if (choice == 2) {
                break;
            } else {
                // Clear the input buffer before taking a new choice
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            setName(newName);
            cout << "Name updated successfully!" << endl;
            break; // Exit the loop if a valid name is provided
        }

        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

//edit id
void Candidate::editId() {
    long newId = 0;
    cout<<"Your current id is: "<< this->getId()<<endl;
    while (true) {
        cout << "Enter new id (no longer than 9 numbers): " << endl;
        cin >> newId;

        if (cin.fail() || to_string(newId).length() > 9) {
            // Invalid input (not an integer or longer than 9)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            int choice = 0;
            cout << "Invalid input. Please choose:" << endl;
            cout << "1. Choose a new ID" << endl;
            cout << "2. Stay with the existing ID" << endl;
            cin >> choice;

            if (choice == 2) {
                break;
            } else {
                // Clear the input buffer before taking a new choice
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            setId(newId);
            cout << "ID updated successfully!" << endl;
            break; // Exit the loop if a valid ID is provided
        }
    }
}

//edit password
void Candidate::editPassword() {
    string newPassword = "";
    cout << "Your current password is: " << this->getPassword() << endl;

    while (true) {
        cout << "Enter new password (no longer than 10 chars): " << endl;
        cin >> newPassword;

        int length = newPassword.length();

        if (length > 10) {
            // Invalid input - longer than 10
            cout << "Invalid input - longer than 10 characters." << endl;

            int choice = 0;
            cout << "Please choose:" << endl;
            cout << "1. Choose a new password" << endl;
            cout << "2. Stay with the existing password" << endl;
            cin >> choice;

            if (choice == 2) {
                break;
            } else {
                // Clear the input buffer before taking a new choice
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            setPassword(newPassword);
            cout << "Password updated successfully!" << endl;
            break; // Exit the loop if a valid password is provided
        }
    }
}


//edit feedback
void Candidate::editFeedback() {
    string newFeedback;
    cout << "Your current feedback is: " << this->getFeedback() << endl;

    while (true) {
        cout << "Enter new feedback (no longer than 50 chars): " << endl;
        getline(cin, newFeedback); // read the entire line

        if (newFeedback.length() > 50) {
            // Invalid input - more than 50 chars
            cout << "Invalid input - longer than 50 characters." << endl;

            int choice = 0;
            cout << "Please choose:" << endl;
            cout << "1. Choose a new feedback" << endl;
            cout << "2. Stay with the existing feedback" << endl;
            cin >> choice;

            if (choice == 2) {
                break;
            } else {
                // Clear the input buffer before taking a new choice
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            setFeedback(newFeedback);
            cout << "Feedback updated successfully!" << endl;
            break; // Exit the loop if a valid feedback is provided
        }
    }
}


//edit resume path
void Candidate::editResumePath() {
    string newResumePath;
    cout << "Your current resume path is: " << this->getResumePath() << endl;

    while (true) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Choose a new resume path" << endl;
        cout << "2. Stay with the existing resume path" << endl;
        cin >> choice;

        if (choice == 2) {
            break;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter new resume path: " << endl;
        getline(cin, newResumePath); // read the entire line

        if (setResumeFilePath(newResumePath)) {
            // setResumeFilePath returns true if the path is valid
            cout << "Resume file path updated successfully!" << endl;
            break;  // Exit the loop if a valid resume path is provided
        }
    }
}

//edit personal information
void Candidate::editPersonalInformation() {
    string newPersonalInformation;
    cout << "Your current personal information is: " << this->getPersonalInformation() << endl;

    while (true) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Choose a new personal information" << endl;
        cout << "2. Stay with the existing personal information" << endl;
        cin >> choice;

        if (choice == 2) {
            break;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter new personal information (no longer than 50 chars): " << endl;
        getline(cin, newPersonalInformation); // read the entire line

        if (setPersonalInformation(newPersonalInformation)) {
            cout << "Personal information updated successfully!" << endl;
            break; // Exit the loop if a valid information is provided
        }
    }
}

//Edit profile
void Candidate::editProfile() {
    while (true) {
        cout << "Please select what you would like to edit in your profile: " << endl;
        cout << "1. name" << endl;
        cout << "2. id" << endl;
        cout << "3. password" << endl;
        cout << "4. feedback" << endl;
        cout << "5. resume path" << endl;
        cout << "6. personal information" << endl;
        cout << "7. Exit menu" << endl;
        int choice = 0;
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue; // Go to the next iteration of the loop
        }


        switch (choice) {
            case 1: {
                editName();
                break;
            }
            case 2: {
                editId();
                break;
            }
            case 3: {
                editPassword();
                break;
            }
            case 4: {
                editFeedback();
                break;
            }
            case 5: {
                editResumePath();
                break;
            }
            case 6: {
                editPersonalInformation();
                break;
            }
            case 7:{
                break;  // Exit the loop if the user chooses to exit
            }
        }
    }
}


//calculate salary
float Candidate::calculateSalary() {
    float hourlySalary;
    float monthlyWorkHours;
    float taxPercentage;

    // Input validation for hourly salary
    while (true) {
        cout << "Enter hourly salary: ";
        cin >> hourlySalary;

        if (cin.fail() || hourlySalary < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative float." << endl;
        } else {
            break;
        }
    }

    // Input validation for monthly work hours
    while (true) {
        cout << "Enter monthly work hours: ";
        cin >> monthlyWorkHours;

        if (cin.fail() || monthlyWorkHours < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative float." << endl;
        } else {
            break;
        }
    }

    // Input validation for tax percentage
    while (true) {
        cout << "Enter tax percentage: ";
        cin >> taxPercentage;

        if (cin.fail() || taxPercentage < 0 || taxPercentage > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a percentage between 0 and 100." << endl;
        } else {
            break;
        }
    }

    // Calculate salary
    float grossSalary = hourlySalary * monthlyWorkHours;
    float netSalary = grossSalary * (1.0 - (taxPercentage / 100.0));

    // Print the calculated salary
    cout << "Gross Salary: $" << grossSalary << endl;
    cout << "Net Salary: $" << netSalary << endl;

    return netSalary; // Return the net salary
}


//view submissions
void Candidate::viewSubmissions() {

}

//submit resume
void Candidate::submitResume(string resumePathToSubmit) {

}