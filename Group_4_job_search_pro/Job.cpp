//
// Created by LENOVO on 21/02/2024.
//
#include "Job.h"
Job::Job(const string& occuption,const string& company_name,const string& company_location,const string& company_number,const string& requirements,const Job_scope& scope ,const int& experience){
    m_occupation=occuption;
    m_company_name=company_name;
    m_copmany_location=company_location;
    m_phone_number=company_number;
    m_requirements=requirements;
    m_scope=scope;
    m_experience_needed=experience;
}

void Job::print_job() const{
    cout << "Jobs Occupation: " << m_occupation << endl;
    cout << "Company name: " << m_company_name << endl;
    cout << "Company location: " << m_copmany_location << endl;
    cout << "Company phone number: " << m_phone_number << endl;
    if (m_scope==0)
        cout << "Full time job" << endl;
    else
        cout << "Part time job" << endl;
    cout << "Requirements: " << m_requirements << endl;
    cout << m_experience_needed << " of experience needed!" << endl;
}