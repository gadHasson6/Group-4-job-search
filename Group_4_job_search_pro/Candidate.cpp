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
Candidate::Candidate(char inputTypeOfUser, string inputName, long inputId, int inputPassword, string inputFeedback, string inputResumePath,
                     vector<Job> inputAppliedJobs, string inputPersonalInformation)
                     : User(inputTypeOfUser,inputName,inputId,inputPassword,inputFeedback), resumePath(inputResumePath),
                       appliedJobs(inputAppliedJobs),
                       personalInformation(inputPersonalInformation){

}

//Copy constructor
Candidate::Candidate(const Candidate &other) : User(other), resumePath(other.resumePath),
                                               appliedJobs(other.appliedJobs),
                                               personalInformation(other.personalInformation)  {

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

//set applied job
void Candidate::setAppliedJobs(const vector<Job> &newAppliedJobs) {
    appliedJobs = newAppliedJobs;
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


//add job application
void Candidate::addJobApplication(Job newJobApplication) {
    appliedJobs.push_back(newJobApplication);   //adds the new job application to the end of the appliedJobs vector
}


//delete job
void Candidate::deleteJobApplication(int indexToDelete) {
    if (indexToDelete >= 0 && indexToDelete < appliedJobs.size()) {
        appliedJobs.erase(appliedJobs.begin() + indexToDelete); //removes the job application at the specified index.
    } else {
        cout << "Invalid index to delete." << endl;
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
                string newName = "";
                cout << "Enter the new name (no longer than 20 letters): " << endl;
                getline(cin, newName); // read the entire line
                if (newName.length() > 20) {
                    std::cout << "Name cannot be longer than 20 letters. Please enter again." << std::endl;
                } else {
                    setName(newName);
                    std::cout << "Name updated successfully!" << std::endl;
                    break; // Exit the loop if a valid name is provided
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                while (true); // Continue the loop until a valid name is entered


            }
            case 2: {
                long newId = 0;
                do {
                    cout << "Enter new id (no longer than 9 numbers): " << endl;
                    cin >> newId;

                    // Convert the integer to a string
                    string numString = to_string(newId);
                    // Get the length of the string
                    int length = numString.length();


                    if (cin.fail()) {
                        // Invalid input (not an integer)
                        cin.clear(); // Clear the error flag
                        cin.ignore(); // Discard invalid input
                        cout << "Invalid input. Please enter a valid integer." << endl;
                    } else if (length > 9) {
                        // Invalid input - longer than 9
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input - longer than 9 numbers" << endl;
                    } else {
                        setId(newId);
                        cout << "Id updated successfully!" << endl;
                        break; // Exit the loop if a valid id is provided
                    }
                } while (true); // Continue the loop until a valid id is entered
                break; // break out of the switch statement
            }
            case 3: {
                int newPassword = 0;
                do {
                    cout << "Enter new password (no longer than 10 numbers): " << endl;
                    cin >> newPassword;

                    // Convert the integer to a string
                    string numString = to_string(newPassword);
                    // Get the length of the string
                    int length = numString.length();


                    if (cin.fail()) {
                        // Invalid input (not an integer)
                        cin.clear(); // Clear the error flag
                        cin.ignore(); // Discard invalid input
                        cout << "Invalid input. Please enter a valid integer." << endl;
                    } else if (length > 10) {
                        // Invalid input - longer than 10
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input - longer than 10 numbers" << endl;
                    } else {
                        setPassword(newPassword);
                        cout << "Password updated successfully!" << endl;
                        break; // Exit the loop if a valid id is provided
                    }
                } while (true); // Continue the loop until a valid id is entered
                break; // break out of the switch statement
            }
            case 4: {
                string newFeedback;
                do {
                    cout << "Enter new feedback (no longer than 50 chars): " << endl;
                    getline(cin, newFeedback); // read the entire line

                    if (newFeedback.length() > 50) {
                        // Invalid input - more than 50 chars
                        cout << "Invalid input." << endl;
                    } else {
                        setFeedback(newFeedback);
                        cout << "Feedback updated successfully!" << endl;
                        break; // Exit the loop if a valid feedback is provided
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                } while (true); // Continue the loop until valid feedback is entered
                break; // break out of the switch statement
            }
            case 5: {
                string newResumePath;
                do {
                    cout << "Enter new resume path: " << endl;
                    getline(cin, newResumePath); // read the entire line
                    if (setResumeFilePath(newResumePath)) {
                        // setResumeFilePath returns true if the path is valid
                        cout << "Resume file path updated successfully!" << endl;
                        break;  // Exit the loop if a valid resume path is provided
                    }
                } while (true); // Continue the loop until a valid resume path is entered
                break; // break out of the switch statement
            }
            case 6: {
                string newPersonalInformation;
                do {
                    cout << "Enter new personal information (no longer than 50 chars): " << endl;
                    getline(cin, newPersonalInformation); // read the entire line

                    if (setPersonalInformation(newPersonalInformation)) {
                        cout << "personal information updated successfully!" << endl;
                        break; // Exit the loop if a valid feedback is provided
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                } while (true); // Continue the loop until valid feedback is entered
                break; // break out of the switch statement
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


//view submission
void Candidate::viewSubmissions() {

    int i=0;
    // Iterate through each element in the vector using a range-based for loop
    for (const auto& job : appliedJobs) {
        // 'job' is a reference to each element in the vector
        // Perform operations on 'job' as needed

        cout << "job number "<<i+1<<" details:" <<endl;

        i++;
    }

}
