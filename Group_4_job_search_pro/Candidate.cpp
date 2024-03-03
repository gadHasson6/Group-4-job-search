//
// Created by LENOVO on 21/02/2024.
//

#include "Candidate.h"
using namespace std;

//Default constructor
Candidate::Candidate() : User() {
    this->resumePath="";
    this->appliedJobs= nullptr;
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
    this->appliedJobs= nullptr;
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
bool Candidate::setSpecialty(const string &inputSpecialty) {
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
    if(other!= nullptr && size>0) {
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
bool Candidate::setPersonalInformation(const string &newPersonalInformation) {
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



//filter by job occupation
Job **Candidate::byJobOccupation(const Job **&allJobs, int size, const std::string &occupation, int &newSize) {
    // Count the number of jobs with the given occupation
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_occupation()== occupation) {
            newSize++;
        }
    }

    // Create a new array to store jobs with the given occupation
    Job **filteredJobs = new Job *[newSize];
    int index = 0;

    // Iterate through all jobs and add matching jobs to the filteredJobs array
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_occupation() == occupation) {
            filteredJobs[index] = new Job(*allJobs[i]);  // Assuming we have a copy constructor in Job class
            index++;
        }
    }

    return filteredJobs;
}


//filter by job scope
Job **Candidate::byJobScope(const Job **&allJobs, int size, const string &name, int &newSize) {   //send newSize=0 to get the new size

    // Count the number of jobs with the given company name
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_name() == name) {
            newSize++;
        }
    }

    // Create a new array to store jobs with the given company name and matching scope
    Job **filteredJobs = new Job *[newSize];
    int index = 0;

    // Iterate through all jobs and add matching jobs to the filteredJobs array
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_name() == name) {
            filteredJobs[index] = new Job(*allJobs[i]);  // Assuming we have a copy constructor in Job class
            index++;
        }
    }

    return filteredJobs;
}



//filter by job resident
Job **Candidate::byJobResident(const Job **&allJobs, int size,const string &resident, int &newSize) {
    // Count the number of jobs with the given company resident
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_location() == resident) {
            newSize++;
        }
    }

    // Create a new array to store jobs with the given company resident
    Job **filteredJobs = new Job *[newSize];
    int index = 0;

    // Iterate through all jobs and add matching jobs to the filteredJobs array
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_location() == resident) {
            filteredJobs[index] = new Job(*allJobs[i]);  // Assuming we have a copy constructor in Job class
            index++;
        }
    }

    return filteredJobs;
}


//filter by job experience
Job **Candidate::byJobExperience(const Job **&allJobs, int size, int experience, int &newSize) {
    // Count the number of jobs with the given company needed experience
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_experience() == experience) {
            newSize++;
        }
    }

    // Create a new array to store jobs with the given company needed experience
    Job **filteredJobs = new Job *[newSize];
    int index = 0;

    // Iterate through all jobs and add matching jobs to the filteredJobs array
    for (int i = 0; i < size; i++) {
        if (allJobs[i]->get_experience()== experience) {
            filteredJobs[index] = new Job(*allJobs[i]);  // Assuming we have a copy constructor in Job class
            index++;
        }
    }

    return filteredJobs;
}


//look for jobs
void Candidate::lookForJobs(const Job **&allJobs, int size) {
    while (true){
        int choice = 0;
        cout << "Please choose how you would like to filter the jobs:" << endl;
        cout << "1. By Name" << endl;
        cout << "2. By Resident" << endl;
        cout << "3. By Experience" << endl;
        cout << "4. By occupation" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Go back to the beginning of the loop
        }

        if (choice == 5) {
            cout << "Exiting the job search." << endl;
            break; // Exit the loop if the user chooses to quit
        }

        switch (choice) {
            case 1: {
                int newSize = 0;
                string nameToLook;
                int maxAttempts = 3; // Set a maximum number of attempts

                for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
                    cout << "Please enter name of job: " << endl;
                    getline(cin, nameToLook);

                    // Check if the input is empty or contains only whitespaces
                    if (nameToLook.find_first_not_of(' ') != string::npos) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid job name." << endl;
                    }

                    // Check if reached the maximum number of attempts
                    if (attempt == maxAttempts) {
                        cout << "Maximum attempts reached. " << endl;
                        return;
                    }
                }

                Job** newArr = byJobScope(allJobs, size, nameToLook, newSize);

                if (newSize == 0) {
                    cout << "No matching jobs found for the specified job name." << endl;
                } else {
                    for (int i = 0; i < newSize; i++) {
                        newArr[i]->print_job();
                        cout<<endl;
                    }

                    // free the memory allocated for newArr
                    for (int i = 0; i < newSize; i++) {
                        delete newArr[i];
                    }
                    delete[] newArr;
                }
                break;
            }
            case 2:  {
                int newSize = 0;
                string residentToLook;
                int maxAttempts = 3; // Set a maximum number of attempts

                for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
                    cout << "Please enter resident: " << endl;
                    getline(cin, residentToLook);

                    // Check if the input is empty or contains only whitespaces
                    if (residentToLook.find_first_not_of(' ') != string::npos) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid resident." << endl;
                    }

                    // Check if reached the maximum number of attempts
                    if (attempt == maxAttempts) {
                        cout << "Maximum attempts reached. " << endl;
                        return;
                    }
                }

                Job** newArr = byJobResident(allJobs, size, residentToLook, newSize);

                if (newSize == 0) {
                    cout << "No matching jobs found for the specified resident." << endl;
                } else {
                    for (int i = 0; i < newSize; i++) {
                        newArr[i]->print_job();
                        cout<<endl;
                    }

                    // free the memory allocated for newArr
                    for (int i = 0; i < newSize; i++) {
                        delete newArr[i];
                    }
                    delete[] newArr;
                }
                break;
            }
            case 3: {
                int newSize = 0;
                int experienceToLook;
                int maxAttempts = 3; // Set a maximum number of attempts

                for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
                    cout << "Please enter experience: " << endl;
                    cin>>experienceToLook;

                    // Check if the input is empty or contains only whitespaces
                    if (experienceToLook>=0 && experienceToLook<=100) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid experience." << endl;
                    }

                    // Check if reached the maximum number of attempts
                    if (attempt == maxAttempts) {
                        cout << "Maximum attempts reached. " << endl;
                        return;
                    }
                }

                Job** newArr = byJobExperience(allJobs, size, experienceToLook, newSize);

                if (newSize == 0) {
                    cout << "No matching jobs found for the specified experience." << endl;
                } else {
                    for (int i = 0; i < newSize; i++) {
                        newArr[i]->print_job();
                        cout<<endl;
                    }

                    // free the memory allocated for newArr
                    for (int i = 0; i < newSize; i++) {
                        delete newArr[i];
                    }
                    delete[] newArr;
                }
                break;
            }
            case 4: {
                int newSize = 0;
                string occupationToLook;
                int maxAttempts = 3; // Set a maximum number of attempts

                for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
                    cout << "Please enter occupation: " << endl;
                    getline(cin, occupationToLook);

                    // Check if the input is empty or contains only whitespaces
                    if (occupationToLook.find_first_not_of(' ') != string::npos) {
                        break;
                    } else {
                        cout << "Invalid input. Please enter a valid occupation." << endl;
                    }

                    // Check if reached the maximum number of attempts
                    if (attempt == maxAttempts) {
                        cout << "Maximum attempts reached. " << endl;
                        return;
                    }
                }

                Job** newArr = byJobOccupation(allJobs, size, occupationToLook, newSize);

                if (newSize == 0) {
                    cout << "No matching jobs found for the specified occupation." << endl;
                } else {
                    for (int i = 0; i < newSize; i++) {
                        newArr[i]->print_job();
                        cout<<endl;
                    }

                    // free the memory allocated for newArr
                    for (int i = 0; i < newSize; i++) {
                        delete newArr[i];
                    }
                    delete[] newArr;
                }
                break;
            }

        }
    }
}


//add apply
void Candidate::addApply(Apply* addMe) {
    // Check if the input pointer is valid
    if (addMe == nullptr) {
        cout << "Error: Cannot add a null pointer to appliedJobs." << endl;
        return;
    }

    // Check if appliedJobs array needs resizing
    if (appliedJobSize == 0) {
        appliedJobs = new Apply*[1];
    } else {
        // Create a new array with increased size
        Apply** newAppliedJobs = new Apply*[appliedJobSize + 1];

        // Copy existing elements to the new array
        for (int i = 0; i < appliedJobSize; ++i) {
            newAppliedJobs[i] = appliedJobs[i];
        }

        // Free the memory of the old array
        delete[] appliedJobs;

        // Point appliedJobs to the new array
        appliedJobs = newAppliedJobs;
    }

    // Add the new Apply object to the array
    appliedJobs[appliedJobSize] = addMe;

    // Increment the size counter
    ++appliedJobSize;

    cout << "Apply added successfully!" << endl;
}


//cancel apply
void Candidate::cancelApply(Apply* deleteMe) {
    // Check if the input pointer is valid
    if (deleteMe == nullptr) {
        cout << "Error: Cannot cancel a null pointer in appliedJobs." << endl;
        return;
    }

    // Check if appliedJobs array is empty
    if (appliedJobSize == 0) {
        cout << "Error: appliedJobs array is empty. Cannot cancel." << endl;
        return;
    }

    // Find the index of the Apply object to be canceled
    int indexToDelete = -1;
    for (int i = 0; i < appliedJobSize; ++i) {
        if (appliedJobs[i] == deleteMe) {
            indexToDelete = i;
            break;
        }
    }

    // Check if the Apply object was found
    if (indexToDelete == -1) {
        cout << "Error: Apply object not found in appliedJobs. Cannot cancel." << std::endl;
        return;
    }

    // Create a new array with reduced size
    Apply** newAppliedJobs = new Apply*[appliedJobSize - 1];

    // Copy elements before the deleted one
    for (int i = 0; i < indexToDelete; ++i) {
        newAppliedJobs[i] = appliedJobs[i];
    }

    // Copy elements after the deleted one
    for (int i = indexToDelete + 1; i < appliedJobSize; ++i) {
        newAppliedJobs[i - 1] = appliedJobs[i];
    }

    // Free the memory of the old array
    delete[] appliedJobs;

    // Point appliedJobs to the new array
    appliedJobs = newAppliedJobs;

    // Decrement the size counter
    --appliedJobSize;

    cout << "Apply canceled successfully!" << endl;
}


//sort applied jobs from new to old by date
Apply** Candidate::sortFromNewToOldByDate() const {
    // Create a new array to store a copy of appliedJobs
    Apply **sortedArray = new Apply *[appliedJobSize];

    // Copy elements from appliedJobs to sortedArray
    for (int i = 0; i < appliedJobSize; ++i) {
        sortedArray[i] = appliedJobs[i];
    }

    // Use sort to sort the array based on submission date
    sort(sortedArray, sortedArray + appliedJobSize, [](const Apply *a, const Apply *b) {
        return a->getSubmissionDate() > b->getSubmissionDate();
    });

    // Return the sorted array
    return sortedArray;
}


// choose order to see submissions
void Candidate::chooseOrderToSeeSubmissions() const {
    int attempts = 0;

    while (attempts < 3) {
        int choice = 0;

        cout << "Please choose order to see your submissions: " << endl;
        cout << "1. New to old" << endl;
        cout << "2. Old to new" << endl;
        cin >> choice;

        if (!cin.fail() && (choice == 1 || choice == 2)) {
            Apply** sorted = sortFromNewToOldByDate();

            if (choice == 1) {
                for (int i = 0; i < appliedJobSize; i++) {
                    sorted[i]->getJob()->print_job();
                    cout << endl;
                }
            } else { // choice == 2
                for (int i = appliedJobSize - 1; i >= 0; i--) {
                    sorted[i]->getJob()->print_job();
                    cout << endl;
                }
            }

            // Free the memory allocated for the sorted array
            for (int i = 0; i < appliedJobSize; i++) {
                delete sorted[i];
            }
            delete[] sorted;

            return;  // exit the function after successful input
        } else {
            cout << "Invalid input. Choice can be only 1 or 2. Please enter a valid choice." << endl;
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            attempts++;
        }
    }

    cout << "Maximum attempts reached. Exiting." << endl;
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
            if (choice != 1 && choice != 2) {
                cout << "Invalid choice. Please enter either 1 or 2." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Go back to the beginning of the loop
            }

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
            if (choice != 1 && choice != 2) {
                cout << "Invalid choice. Please enter either 1 or 2." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Go back to the beginning of the loop
            }

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
            if (choice != 1 && choice != 2) {
                cout << "Invalid choice. Please enter either 1 or 2." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Go back to the beginning of the loop
            }

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
            if (choice != 1 && choice != 2) {
                cout << "Invalid choice. Please enter either 1 or 2." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue; // Go back to the beginning of the loop
            }

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
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

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
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

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


//edit email
void Candidate::editEmail() {
    string newEmail;
    cout << "Your current email is: " << this->getEmail() << endl;

    bool editEmailLoop = true;
    while (editEmailLoop) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Enter a new Email" << endl;
        cout << "2. Stay with the existing Email" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        if (choice == 2) {
            editEmailLoop = false;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter your new email address (no longer than 50 characters): " << endl;
            getline(cin, newEmail);

            if (setEmail(newEmail)) {
                cout << "Email updated successfully!" << endl;
                editEmailLoop = false;
            }
        }
    }
}


//edit experience
void Candidate::editExperience() {
    float newWorkExperience;
    cout << "Your current experience is: " << this->getWorkExperience() << endl;

    bool editExperienceLoop = true;
    while (editExperienceLoop) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Enter a new experience" << endl;
        cout << "2. Stay with the existing experience" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        if (choice == 2) {
            editExperienceLoop = false;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter your new experience (between 0 to 100): " << endl;
            cin>>newWorkExperience;

            if (setWorkExperience(newWorkExperience)) {
                cout << "Work experience updated successfully!" << endl;
                editExperienceLoop = false;
            }
        }
    }
}


//edit resident
void Candidate::editResidence() {
    string newResidence;
    cout << "Your current residence is: " << this->getResidence() << endl;

    bool editResidenceLoop = true;
    while (editResidenceLoop) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Enter a new residence" << endl;
        cout << "2. Stay with the existing residence" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        if (choice == 2) {
            editResidenceLoop = false;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            if (setResidence()) {
                cout << "residence updated successfully!" << endl;
                editResidenceLoop = false;
            }
        }
    }
}



//edit specialty
void Candidate::editSpecialty() {
    string newSpecialty;
    cout << "Your current Specialty is: " << this->getSpecialty() << endl;

    bool editSpecialtyLoop = true;
    while (editSpecialtyLoop) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Enter a new Specialty" << endl;
        cout << "2. Stay with the existing Specialty" << endl;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        if (choice == 2) {
            editSpecialtyLoop = false;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter your new Specialty (no longer than 25 characters): " << endl;
            getline(cin, newSpecialty);

            if (setSpecialty(newSpecialty)) {
                cout << "Specialty updated successfully!" << endl;
                editSpecialtyLoop = false;
            }
        }
    }
}

//edit phone number
void Candidate::editPhoneNumber() {
    string newPhoneNumber;
    cout << "Your current phone number is: " << this->getPhoneNumber() << endl;

    bool editPhoneNumberLoop = true;
    while (editPhoneNumberLoop) {
        int choice = 0;
        cout << "Please choose:" << endl;
        cout << "1. Enter a new phone number" << endl;
        cout << "2. Stay with the existing phone number" << endl;
        // Check if the input is a valid float
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid choice (1 or 2)." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }
        else if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter either 1 or 2." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue; // Go back to the beginning of the loop
        }

        if (choice == 2) {
            editPhoneNumberLoop = false;
        } else {
            // Clear the input buffer before taking a new choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter your new phone number (Only numbers and no more than 10): " << endl;
            getline(cin, newPhoneNumber);

            if (setPhoneNumber(newPhoneNumber)) {
                cout << "Phone number updated successfully!" << endl;
                editPhoneNumberLoop = false;
            }
        }
    }
}


//Edit profile
void Candidate::editProfile() {
    while (true) {
        cout << "Please select what you would like to edit in your profile: " << endl;
        cout << "1. name" << endl;
        cout << "2. password" << endl;
        cout << "3. experience" << endl;
        cout << "4. resume path" << endl;
        cout << "5. personal information" << endl;
        cout << "6. specialty" << endl;
        cout << "7. email" << endl;
        cout << "8. phone number" << endl;
        cout << "9. residence" << endl;
        cout << "10. Exit menu" << endl;
        int choice = 0;
        cin >> choice;

        // Validate input
        if (cin.fail() || choice < 1 || choice > 10) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer between 1 and 10." << endl;
            continue; // Go to the next iteration of the loop
        }


        switch (choice) {
            case 1: {
                editName();
                break;
            }
            case 2: {
                editPassword();
                break;
            }
            case 3: {
                editExperience();
                break;
            }
            case 4: {
                editResumePath();
                break;
            }
            case 5: {
                editPersonalInformation();
                break;
            }
            case 6: {
                editSpecialty();
                break;
            }
            case 7: {
                editEmail();
                break;
            }
            case 8: {
                editPhoneNumber();
                break;
            }
            case 9: {
                editResidence();
                break;
            }
            case 10:{
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
    if (appliedJobSize == 0) {
        cout << "You have not submitted any applications." << endl;
    } else {
        cout << "Your submitted applications:" << endl;
        for (int i = 0; i < appliedJobSize; ++i) {
            cout << "Submission " << i + 1 << ":" << endl;
            appliedJobs[i]->getJob()->print_job();
            cout << "Submission Date: ";
            appliedJobs[i]->getSubmissionDate().printDate();
            cout << "Submission Status: " << appliedJobs[i]->getSubmissionStatus() << endl;
            cout << "------------------------" << endl;
        }
    }
}

//submit resume
void Candidate::submitResume(string resumePathToSubmit) {
    // Check if the provided resume path is valid
    if (setResumeFilePath(resumePathToSubmit)) {

        // Display a confirmation message
        cout << "Resume submitted successfully!" << endl;

    }
}

//destructor
Candidate::~Candidate() {
    // Release the memory allocated for appliedJobs array
    for (int i = 0; i < appliedJobSize; ++i) {
        delete appliedJobs[i];
    }
    delete[] appliedJobs;
}