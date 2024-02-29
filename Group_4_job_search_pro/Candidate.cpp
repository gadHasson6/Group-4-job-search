//
// Created by LENOVO on 21/02/2024.
//

#include "Candidate.h"

//Default constructor
Candidate::Candidate() : User() {
    this->resumePath="";
    this->appliedJobs={};
    this->personalInformation="";
}

//Constructor
Candidate::Candidate(string inputName, long inputId, string inputPassword,
                     string inputFeedback, string inputResumePath, string inputPersonalInformation)
        :User(){

}


//Copy constructor
Candidate::Candidate(const Candidate &other) : User(other), resumePath(other.resumePath),
                                               appliedJobs(other.appliedJobs),
                                               personalInformation(other.personalInformation)  {

}

//get resume path
string Candidate::getResumePath() {
    return this->resumePath;
}


//get personal information
string Candidate::getPersonalInformation() {
    return this->personalInformation;
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