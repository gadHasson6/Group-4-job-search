//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_JOB_H
#define GROUP_4_JOB_SEARCH_PRO_JOB_H

#include <cstring>
#include "iostream"
enum Job_scope {full_time = 0,part_time=1};
using namespace std;

class Job {
public:
    Job();
    ~Job();
    Job(const string& occuption,const string& company_name,const string& company_location,const string& company_number,const string& requirements,const Job_scope& scope);
    Job(const Job& other) : m_occupation(other.m_occupation) ,m_company_name(other.m_company_name) ,m_copmany_location(other.m_copmany_location) , m_phone_number(other.m_phone_number),
                            m_requirements(other.m_requirements) , m_scope(other.m_scope) {};
    void print_job () const;
    void set_occupation(const string& occupation) { m_occupation = occupation; }
    void set_name(const string& name) { m_company_name = name; }
    void set_location(const string& location) { m_copmany_location = location; }
    void set_number(const string& number) { m_phone_number = number; }
    void set_requirements(const string& requirements) { m_requirements = requirements; }
    void set_scope(const Job_scope& scope) { m_scope = scope; }
    const string& get_occupation() const { return m_occupation; }
    const string& get_name() const { return m_company_name; }
    const string& get_number() const { return m_phone_number; }
    const string& get_location() const { return m_copmany_location; }
    const string& get_requirements() const { return m_requirements; }
    const Job_scope& get_scope() const { return m_scope; }
private:
    string m_occupation;
    string m_company_name;
    string m_copmany_location;
    string m_phone_number;
    string m_requirements;
    Job_scope m_scope;
};


#endif //GROUP_4_JOB_SEARCH_PRO_JOB_H
