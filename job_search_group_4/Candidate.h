//
// Created by LENOVO on 15/02/2024.
//

#ifndef JOB_SEARCH_GROUP_4_CANDIDATE_H
#define JOB_SEARCH_GROUP_4_CANDIDATE_H

#include "Includes.h"

class Candidate : public User {
private:
    double c_age;
    string c_gander;
    int c_experience;
    string c_living_area;
    string c_pro;
    string c_free_txt;
    Job * c_apply_list;
public:
    Candidate(int id, string name, string mail, string pass, int phone_num, double age, string gander, int experience, string living_area, string pro, string free_txt);
    Candidate();
    virtual ~Candidate();
    virtual void print_user() const;
    void c_print_apply() const;
    void c_add_apply();

};


#endif //JOB_SEARCH_GROUP_4_CANDIDATE_H
