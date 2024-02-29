//
// Created by LENOVO on 21/02/2024.
//

#include "Employer.h"

Employer::Employer(int full_name, long id, int password, int email, long phone_num, int residence, int rating,int feedback)
{
    my_job=User( full_name, id, password, email, phone_num  residence, rating, feedback)
}

void Employer::E_Print_Job() {
    for (int i=0; i<len(my_job);i++) {
        cout<<my_job.print_job[i]<<endl;
    }
}

void Employer::set(Job *item) {
    {my_job=item;}
}

void Employer::edit_job() {
    numofjob= nullptr;
    E_Print_Job();
    cout<<"which job do you want to edit? "<<endl;
    cin>>numofjob>>endl;
    int num;
    cout<<"tap 1 for edit your full name, 2 for edit your id, 3 for edit your password, 4 for edit your email, 5 for edit your phone number, 6 for edit your residence"
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
        case 6:
            my_job[numofjob].setResidence;
    }

}

