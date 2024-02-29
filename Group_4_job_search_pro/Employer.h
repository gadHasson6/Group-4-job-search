//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
#define GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
using namespace std;
#include "Job.h"
#include "User.h"
#include <string>


class Employer :public User{
private:
    Job* my_job;
public:
    Employer(){my_job= nullptr;}
    Employer(string full_name,lond id,string password,string email,long phone_num,string residence,int rating,string feedback );
    void set(Job*item);
    void E_Print_Job();
    void edit_job();


};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
