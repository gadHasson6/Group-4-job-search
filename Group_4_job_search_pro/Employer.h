//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
#define GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
using namespace std;
#include "Job.h"
#include "User.h"
#include <string>
#include <iostream>


class Employer :public User{
private:
    Job** my_job;
    int num_of_jobs;
public:
    Employer(){my_job= nullptr; num_of_jobs = 0;}
    Employer(string full_name,long id,string password,string email,long phone_num ,int rating,string feedback );
    void set(Job**item, int size);
    void E_Print_Job();
    void edit_job();


};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
