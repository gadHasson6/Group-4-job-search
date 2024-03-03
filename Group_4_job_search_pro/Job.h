//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_JOB_H
#define GROUP_4_JOB_SEARCH_PRO_JOB_H
enum Job_scope {full_time = 0,part_time =1};
#include <cstring>
#include "iostream"
#include "Apply.h"
#include <cctype>
using namespace std;

class Job {
private:
    bool m_posting_status;
    int m_job_id;
    string m_occupation;
    string m_company_name;
    string m_company_location;
    string m_phone_number;
    string m_job_name;
    int m_experience_needed;
    Job_scope m_scope;
    Apply** m_Applies;
    int m_applies_size;
    Date m_posting_date;
public:
    Job();
    ~Job();
    Job(bool posting_status,int job_id,string occuption,string company_name,string company_location,string company_phone_number,string job_name,
        Job_scope scope, Date posting_date);
    Job(const Job& other);
    void print_job () const;

    //sets
    bool set_occupation(const string& occupation);
    bool set_company_name(const string& company_name);
    bool set_location() ; //V
    bool set_phone_number(const string& phoneNumber);
    bool set_scope(const Job_scope& scope);
    bool set_experience();
    bool set_job_name(const string& job_name);
    void set_applies(Apply** appliesArray , int size );
    bool set_status(const bool status);
    bool set_posting_date(Date other);
    bool set_job_id(const int &jobId);


    //gets
    string get_occupation() const { return this->m_occupation; }
    string get_company_name() const { return this->m_company_name; }
    string get_phone_number() const { return this->m_phone_number; }
    string get_location() const { return this->m_company_location; }
    string get_job_name() const { return this->m_job_name; }
    Job_scope get_scope() const { return this->m_scope; }
    int get_experience() const { return this->m_experience_needed; }
    int get_job_id() const { return this->m_job_id; }
    bool get_status () const {return this->m_posting_status; }
    Apply** get_applies() const {return this->m_Applies;}
    int get_applies_size() const {return  this->m_applies_size;}
    Date get_posting_date() const {return this->m_posting_date;}

    void Add_Apply(Apply* apply);
    bool isExactly10Digits(const string& number);
    bool Checkdigit(const string& input);

};



#endif //GROUP_4_JOB_SEARCH_PRO_JOB_H