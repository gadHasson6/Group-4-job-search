//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_JOB_H
#define GROUP_4_JOB_SEARCH_PRO_JOB_H

#include <cstring>
#include <cctype>
#include "iostream"
#include <limits>

enum Job_scope {full_time = 0,part_time=1};
using namespace std;

class Apply;

class Job {
public:
    Job();
    ~Job();
    Job(const int& job_id,const string& occuption,const string& company_name,const string& company_location,const string& company_number,const string& requirements,const Job_scope& scope,const int& experience);
    Job(const Job& other) : m_job_id(other.m_job_id) , m_occupation(other.m_occupation) ,m_company_name(other.m_company_name) ,m_copmany_location(other.m_copmany_location) , m_phone_number(other.m_phone_number),
                            m_requirements(other.m_requirements) , m_scope(other.m_scope) , m_experience_needed(other.m_experience_needed) {};
    void print_job () const;
    bool set_occupation(const string& occupation);
    bool set_name(const string& name);
    bool set_location() ;
    bool set_number(const string& number);
    bool set_requirements(const string& requirements);
    bool set_scope(const Job_scope& scope);
    bool set_experience();
    bool set_job_name(const string& job_name);
    void set_applies(Apply** , int );
    bool set_status(const bool status);
    const string& get_occupation() const { return m_occupation; }
    const string& get_name() const { return m_company_name; }
    const string& get_number() const { return m_phone_number; }
    const string& get_location() const { return m_copmany_location; }
    const string& get_requirements() const { return m_requirements; }
    const string& get_job_name() const { return m_job_name; }
    const Job_scope& get_scope() const { return m_scope; }
    const int& get_experience() const { return m_experience_needed; }
    const int& get_job_id() const { return m_job_id; }
    const bool get_status () const {return m_posting_status; }
    bool isExactly10Digits(const string& );
    bool Checkdigit(const string& );

    void Add_Apply(Apply* apply);
private:
    bool m_posting_status;
    int m_job_id;
    string m_occupation;
    string m_company_name;
    string m_copmany_location;
    string m_phone_number;
    string m_requirements;
    string m_job_name;
    int m_experience_needed;
    Job_scope m_scope;
    Apply** m_Applies;
    int m_applies_size;
};


#endif //GROUP_4_JOB_SEARCH_PRO_JOB_H
