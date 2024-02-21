//
// Created by LENOVO on 15/02/2024.
//

#ifndef JOB_SEARCH_GROUP_4_JOB_H
#define JOB_SEARCH_GROUP_4_JOB_H

#include "Includes.h"

class Job {
private:
    int job_id;
    int j_creator_id;
    string j_location;
    string j_pro;
    string j_type;
    int j_experience;
    string j_name;
    int j_salary;
    string j_comp_name;
    int j_contact;
    string j_status;
    Candidate ** j_candidate_list;
public:
    Job();
    Job(int id, int creator_id, string location, string pro, string type, int experience, string name, int salary, string comp_name, int contact, string status);
    ~Job();
    void job_print() const;
    void job_edit();
};


#endif //JOB_SEARCH_GROUP_4_JOB_H
