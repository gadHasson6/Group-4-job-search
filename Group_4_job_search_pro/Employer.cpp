//
// Created by LENOVO on 21/02/2024.
//

#include "Employer.h"

Employer::Employer(string full_name,long id,string password,string email,long phone_num ,int rating,string feedback ) :User(full_name, id, password, email, phone_num ,rating, feedback){
    my_job= nullptr;
}

void Employer::E_Print_Job() {
    for (int i=0; i<num_of_jobs;i++) {
        cout<<my_job[i].print_job<<endl;
    }
}

void Employer::set(Job **item, int size) {
    num_of_jobs = size;
    my_job = new Job * [num_of_jobs];
    for (int i = 0; i < num_of_jobs; ++i) {
        my_job[i] = item[i];
    }
}

void Employer::edit_job() {
    int numofjob = 0;
    E_Print_Job();
    cout<<"which job do you want to edit? "<<endl;
    cin>>numofjob;
    int num;
    cout<<"tap 1 for edit your full name, 2 for edit your id, 3 for edit your password, 4 for edit your email, 5 for edit your phone number\n";
    switch (num) {
        case 1:
            my_job[numofjob].setName;
        case 2:
            my_job[numofjob].setId;
        case 3:
            my_job[numofjob].setPassword;
        case 4:
            my_job[numofjob].setEmail;
        case 5:
            my_job[numofjob].setPhoneNumber;
    }

}

