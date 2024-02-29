//
// Created by LENOVO on 21/02/2024.
//

#include "Employer.h"

Employer::Employer(string full_name, long id, string password, string email, long phone_num, int rating,
                   string feedback) : User(full_name, id, password, email, phone_num, rating, feedback) {
    my_job = nullptr;
}

void Employer::Employer_Print_Job() {
    for (int i = 0; i < num_of_jobs; i++) {
        cout << my_job[i].print_job << endl;
    }
}

void Employer::set(Job **item, int size) {
    num_of_jobs = size;
    my_job = new Job *[num_of_jobs];
    for (int i = 0; i < num_of_jobs; ++i) {
        my_job[i] = item[i];
    }
}

void Employer::edit_job() {
    int numofjob = 0;
    E_Print_Job();
    cout << "which job do you want to edit? " << endl;
    cin >> numofjob;
    int num;
    bool flag = false;
    for (int i = 0; i < num_of_jobs; i++) {
        if (my_job[i].GetIdJob == numofjob) {
            cout
                    << "tap 1 for edit your company name, 2 for edit your salary, 3 for edit your location, 4 for edit your profession, 5 for edit your job type, 6 for your experience, 7 for your posting status, 8 for your contact number, 9 for cancel \n";
            switch (num) {
                case 1:
                    my_job[numofjob].set_name;
                case 2:
                    my_job[numofjob].setSalary;
                case 3:
                    my_job[numofjob].set_location;
                case 4:
                    my_job[numofjob].set_occupation;
                case 5:
                    my_job[numofjob].setJobType;
                case 6:
                    my_job[numofjob].setExperience;
                case 7:
                    my_job[numofjob].setPostingStatus;
                case 8:
                    my_job[numofjob].set_number;
                case 9: {
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
        cout << "the job you search is not found " << endl;
}

void Employer::delete_job() {
    int idnumofjob = 0;
    bool flag = false;
    E_Print_Job();
    cout << "which job do you want to delete? " << endl;
    cin >> idnumofjob;
    for (int i = 0; i < num_of_jobs; i++) {
        if (my_job[i].GetJobId() == idnumofjob) {
            my_job[i].SetPostingStatus("delete");
            i = num_of_jobs;
            flag = true;
        }
    }
    if (!flag)
        cout << "the job you search is not found " << endl;
}

void Employer::publish_job() {

}