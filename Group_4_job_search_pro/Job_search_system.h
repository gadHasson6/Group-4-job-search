//
// Created by LENOVO on 28/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H
#define GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H

#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
#include "Candidate.h"
#include "Apply.h"
#include "Employer.h"
#include "Job.h"

using namespace std;

#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"
#define START_INDEX 0


class Job_search_system {
private:
    int num_of_candidates, num_of_employers, num_of_jobs, num_of_submissions;
    Employer ** employers_list;
    Candidate ** candidates_list;
    Job ** jobs_list;
    Apply ** submissions_list;
public:
    Job_search_system();
    ~Job_search_system();
    Job ** Initializing_jobs(Employer * new_employer);
};


#endif //GROUP_4_JOB_SEARCH_PRO_JOB_SEARCH_SYSTEM_H
