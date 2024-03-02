//
// Created by LENOVO on 21/02/2024.
//

#include "Employer.h"

Employer::Employer(const string& inputName, const long inputId, const string& inputPassword, const string& inputEmail,
                   const string& inputPhoneNumber, int inputRating,
                   const string& inputFeedback) : User(inputName, inputId, inputPassword, inputEmail, inputPhoneNumber, inputRating, inputFeedback) {
    my_job = nullptr;
    num_of_jobs = 0;
}

void Employer::Employer_Print_Job() {
    for (int i = 0; i < num_of_jobs; i++) {
        my_job[i]->print_job();
    }
}

void Employer::set(Job **item, int size) {
    num_of_jobs = size;
    my_job = new Job *[num_of_jobs];
    for (int i = 0; i < num_of_jobs; ++i) {
        my_job[i] = item[i];
    }
}

void Employer::Edit_Job() {
    bool flag3 = true;
    int numofjob = 0;
    Employer_Print_Job();
    while (flag3){
        cout << "which job do you want to edit? " << endl;
        cin >> numofjob;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else flag3 = false;
    }
    int num;
    bool flag = false;
    for (int i = 0; i < num_of_jobs; i++) {
        if (my_job[i]->get_job_id() == numofjob) {
            cout
                    << "tap 1 for edit your company name, 2 for edit your requirements, 3 for edit your location, 4 for edit your occupation, 5 for edit your job type, 6 for your experience, 7 for your contact number, 8 for cancel \n";
            switch (num) {
                case 1: {
                    bool flag2 = true;
                    while (flag2){
                        string newName;
                        cout << "Please enter the new company name: " << endl;
                        cin >> newName;
                        flag2 = my_job[i]->set_name(newName);
                    }

                }
                case 2: {
                    string newRequirements;
                    cout << "Please enter the new requirements : " << endl;
                    cin >> newRequirements;
                    my_job[i]->set_requirements(newRequirements);
                }
                case 3: {
                    string newLocation;
                    int choice=0;
                    cout<<"please choose your residence: "<<endl;
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
                                newLocation="Northern District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                            case 2: {
                                newLocation="Haifa District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                            case 3: {
                                newLocation="Tel Aviv District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                            case 4: {
                                newLocation="Central District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                            case 5: {
                                newLocation="Jerusalem District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                            case 6: {
                                newLocation="Southern District";
                                my_job[i]->set_location(newLocation);
                                break;
                            }
                        }
                    }
                    else {
                        // Clear the error flag
                        cin.clear();
                        // Discard invalid input from the input buffer
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                case 4: {
                    string newOccupation;
                    cout << "Please enter the new occupation : " << endl;
                    cin >> newOccupation;
                    if (cin.fail()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input. Please enter a valid integer." << endl;
                        break;
                    }my_job[i]->set_occupation(newOccupation);
                }
                case 5: {
                    int newJobType;
                    cout << "Please enter for full time job 0 and for part time job 1 : " << endl;
                    cin >> newJobType;
                    if (cin.fail()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input. Please enter a valid integer." << endl;
                        break;
                    }
                    auto x = Job_scope(newJobType);
                    my_job[i]->set_scope(x);
                }
                case 6: {
                    int newExperience;
                    cout << "Please enter the new experience : " << endl;
                    cin >> newExperience;
                    if (cin.fail()) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input. Please enter a valid integer." << endl;
                        break;
                    }
                    my_job[i]->set_experience(newExperience);
                }
                case 7: {
                    string newContactNumber;
                    cout << "Please enter the new contact number : " << endl;
                    cin >> newContactNumber;
                    my_job[i]->set_number(newContactNumber);
                }
                case 8: {
                    cout << "cancel successfully\n";
                    return;
                }
                default: {
                    cout << "Invalid input\n please try again\n";
                    i--;
                }
            }
            i = num_of_jobs;
            flag = true;
        }
    }
    if (!flag)
        cout << "The job you search is not found " << endl;
}

void Employer::Delete_Job() {
    int idnumofjob = 0;
    bool flag = false;
    bool flag3 = true;
    Employer_Print_Job();
    while (flag3){
        cout << "Which job do you want to delete? " << endl;
        cin >> idnumofjob;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
        } else flag3 = false;
    }
    for (int i = 0; i < num_of_jobs; i++) {
        if (my_job[i]->get_job_id() == idnumofjob) {
            my_job[i]->set_status(false);
            i = num_of_jobs;
            flag = true;
        }
    }
    if (!flag)
        cout << "The job you search is not found " << endl;
}

void Employer::Publish_Job(Job &job) {
    num_of_jobs++;
    Job **temp = new Job *[num_of_jobs];
    for (int i = 0; i < num_of_jobs - 1; i++) {
        temp[i] = my_job[i];
    }
    temp[num_of_jobs - 1] = &job;
    delete[]my_job;
    my_job = new Job *[num_of_jobs];
    for (int i = 0; i < num_of_jobs; i++) {
        my_job[i] = temp[i];
    }
    cout << "add successfully" << endl;
}