//
// Created by LENOVO on 21/02/2024.
//

#include "Job.h"
Job::Job() {
    m_posting_status=false;
    m_Applies= nullptr;
    m_applies_size=0;
    m_job_id=0;
    m_occupation="Unknown";
    m_company_name="Unknown";
    m_copmany_location="Unknown";
    m_phone_number="Unknown";
    m_requirements="Unknown";
    m_scope= full_time;
    m_experience_needed=0;
}
Job::Job(const int& job_id ,const string& occuption,const string& company_name,const string& company_location
        ,const string& company_number,const string& requirements,const Job_scope& scope ,const int& experience){
    m_job_id=job_id;
    m_occupation=occuption;
    m_company_name=company_name;
    m_copmany_location=company_location;
    m_phone_number=company_number;
    m_requirements=requirements;
    m_scope=scope;
    m_experience_needed=experience;
}

void Job::print_job() const{

    cout << "Job id: " << m_job_id << endl;
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
void Job::set_applies(Apply** appliesArray, int size) {
    // Release previously allocated memory
    if (m_Applies != nullptr) {
        for (int i = 0; i < m_applies_size; ++i) {
            delete m_Applies[i];
        }
        delete[] m_Applies;
    }

    // Allocate new memory and copy the applies
    m_applies_size = size;
    m_Applies = new Apply*[size];
    for (int i = 0; i < size; ++i) {
        m_Applies[i] = appliesArray[i];
    }
}

Job::~Job(){
    if (m_Applies != nullptr) {
        for (int i = 0; i < m_applies_size; ++i) {
            delete m_Applies[i];
        }
        delete[] m_Applies;
    }
}

void Job::Add_Apply(Apply* apply) {
    m_applies_size++;
    Apply** temp = new Apply*[m_applies_size];

    // Copy existing applies to temp array
    for(int i = 0; i < m_applies_size - 1; i++) {
        temp[i] = m_Applies[i];
    }

    // Add the new apply
    temp[m_applies_size - 1] = apply;

    // Delete the old array and update with the new one
    delete[] m_Applies;
    m_Applies = temp;

    cout << "Apply added successfully" << endl;
}