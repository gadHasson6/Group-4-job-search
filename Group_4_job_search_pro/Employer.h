//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
#define GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H

#include "sqlite3.h"
#include <iostream>
#include <vector>
#include "Job.h"

using namespace std;


class Employer {
private:
    long employer_id;
    string employer_name;
    string company_name;
    string employer_email;
    long employer_phone_number;
    string password;
    Job ** my_jobs;
public:
    Employer();
    Employer(long input_id, string input_employer_name, string input_company_name, string input_employer_email
             , long input_employer_phone_number, string input_password);
};


#endif //GROUP_4_JOB_SEARCH_PRO_EMPLOYER_H
