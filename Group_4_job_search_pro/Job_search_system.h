//
// Created by LENOVO on 28/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H
#define GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H

#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
#include "Job.h"
#include "User.h"
#include "Employer.h"
#include "Candidate.h"
#include "Apply.h"

using namespace std;

#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"
#define START_INDEX 0


class Job_search_system {
private:
    int num_of_candidates, num_of_employers, num_of_jobs, num_of_submissions;
    Candidate * current_candidate;
    Employer * current_employer;
    Employer ** employers_list;
    Candidate ** candidates_list;
    Job ** jobs_list;
    Apply ** submissions_list;
public:
    Job_search_system();/////V
    ~Job_search_system();
    void employer_candidate_menu();/////V
    void candidate_login_registration_menu();
    void employer_login_registration_menu();
    bool candidate_login();
    bool employer_login();
    bool candidate_registration(); ////V
    bool employer_registration();
    void candidate_main_menu();
    void employer_main_menu();
    Job ** Initializing_jobs(Employer * new_employer);
};


#endif //GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H
