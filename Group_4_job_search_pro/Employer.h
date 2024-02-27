//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
#define GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
using namespace std;
#include "Job.h"


class Employer {
private:
    Job* my_job;
public:
    void set(Job*item){my_job=item;}
    Employer();
    Employer(long id, string full_name,string mail,long phone_num,string paswoord)
    void edit_job();
    void publich_job();
    void view_job();


};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
