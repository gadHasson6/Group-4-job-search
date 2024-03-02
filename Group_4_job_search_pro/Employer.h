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
#include <limits>


class Employer :public User{
private:
    Job** my_job;
    int num_of_jobs;
public:
    Employer():User(){my_job= nullptr; num_of_jobs = 0;}
    Employer(const string& inputName, const long inputId, const string& inputPassword, const string& inputEmail,
             const string& inputPhoneNumber, int inputRating,
             const string& inputFeedback);
    void set(Job**item, int size);
    void Employer_Print_Job();
    void Edit_Job();
    void Delete_Job();
    void Publish_Job(Job& job);


};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H