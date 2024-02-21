//
// Created by LENOVO on 15/02/2024.
//

#ifndef JOB_SEARCH_GROUP_4_EMPLOYER_H
#define JOB_SEARCH_GROUP_4_EMPLOYER_H

#include "Includes.h"

class Employer : public User {
private:
    Job ** E_my_jobs;

public:
    Employer();
    Employer(int id, string name, string mail, string pass, int phone_num);
    virtual ~Employer();
    virtual void print_user() const;
    void print_jobs() const;
    void add_job();
    void edit_job();
};


#endif //JOB_SEARCH_GROUP_4_EMPLOYER_H
