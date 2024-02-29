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
    Employer(long id, string full_name,string mail,long phone_num,string password);
    void edit_job();
    void set(Job*item){my_job=item;}
    void publish_job();
    void view_job();


};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
