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
    m_company_location="Unknown";
    m_phone_number="Unknown";
    m_requirements="Unknown";
    m_job_name="Unknown";
    m_scope=full_time;
    m_experience_needed=0;
}
Job::Job(const string& name,const int& job_id ,const string& occuption,const string& company_name,const string& company_location,const string& company_number,const string& requirements,const Job_scope& scope ,const int& experience){
    m_job_id=job_id;
    m_occupation=occuption;
    m_company_name=company_name;
    m_company_location=company_location;
    m_phone_number=company_number;
    m_requirements=requirements;
    m_scope=scope;
    m_experience_needed=experience;
    m_job_name=name;
}

void Job::print_job() const{
    cout << "Job id: " << m_job_id << endl;
    cout << "Jobs Occupation: " << m_occupation << endl;
    cout << "Company name: " << m_company_name << endl;
    cout << "Company location: " << m_company_location << endl;
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

Job::~Job() {
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

bool Job::set_status(const bool status) {
    if (status == 1 || status == 0) {
        m_posting_status = status;
        return true;
    } else {
        cout << "Status can be only active or inactive " << endl;
        return false;
    }
}

bool Job::set_occupation(const string& occupation) {
    if(Checkdigit(occupation))
    {
        m_occupation=occupation;
        return true;
    }
    else
        return false;
}
bool Job::set_job_name(const string& job_name) {
    if (Checkdigit(job_name)) {
        m_job_name = job_name;
        return true;
    } else {
        return false;
    }
}

bool Job::set_company_name(const string& company_name) {
    if (Checkdigit(company_name)) {
        m_company_name = company_name;
        return true;
    } else {
        return false;
    }
}

bool Job::set_location() {
    cout<<"please choose your residence: "<<endl;
    int choice=0;
    cout<<"1. Northern District"<<endl;
    cout<<"2. Haifa District"<<endl;
    cout<<"3. Tel Aviv District"<<endl;
    cout<<"4. Central District"<<endl;
    cout<<"5. Jerusalem District"<<endl;
    cout<<"6. Southern District"<<endl;
    cin>>choice;
    if (!cin.fail() && choice >= 1 && choice <= 6){
        switch (choice) {
            case 1:{
                this->m_company_location="Northern District";
                break;
            }
            case 2: {
                this->m_company_location="Haifa District";
                break;
            }
            case 3: {
                this->m_company_location="Tel Aviv District";
                break;
            }
            case 4: {
                this->m_company_location="Central District";
                break;
            }
            case 5: {
                this->m_company_location="Jerusalem District";
                break;
            }
            case 6: {
                this->m_company_location="Southern District";
                break;
            }
        }
        return true;
    }
    else {
        // Clear the error flag
        cin.clear();
        // Discard invalid input from the input buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
}
bool Job::set_number(const string& number) {
    if (isExactly10Digits(number)) {
        m_phone_number = number;
        return true;
    } else {
        cout << "Invalid phone number" << endl;
        return false;
    }
}

bool Job::set_requirements(const string& requirements) {
    m_requirements = requirements;
    return true;
}

bool Job::set_scope(const Job_scope& scope) {
    if(scope== full_time || scope == part_time)
    {
        m_scope = scope;
        return true;
    }
    else
        cout << "Invalid input" << endl;
}

bool Job::set_experience() {
    cout << "Please enter new experience: ";
    int experience;
    cin >> experience;
    if (cin.fail()) {
        cout << "Invalid input. Please enter an integer." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    } else {
        m_experience_needed = experience;
        return true;
    }
}

bool Job::isExactly10Digits(const string& number) {
    int digitCount = 0;
    for (char ch : number) {
        if (isdigit(ch)) {
            digitCount++;
        } else {
            // If a non-digit character is encountered, return false
            return false;
        }
    }
    // Return true only if exactly 10 digits are encountered
    return (digitCount == 10);
}


bool Job::Checkdigit(const string& input) {
    for (char ch : input) {
        if (isdigit(ch)) {
            cout << "Only letters are allowed." << endl;
            return false;
        }
    }
    return true;
}