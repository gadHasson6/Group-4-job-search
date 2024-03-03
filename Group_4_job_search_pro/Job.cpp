//
// Created by LENOVO on 21/02/2024.
//
#include "Job.h"


//default constructor
Job::Job() {
    m_posting_status=false;
    m_job_id=0;
    m_occupation="Unknown";
    m_company_name="Unknown";
    m_company_location="Unknown";
    m_phone_number="Unknown";
    m_job_name="Unknown";
    m_experience_needed=0;
    m_scope=0;
    m_Applies= nullptr;
    m_applies_size=0;
    m_posting_date=Date();
}


//destructor
Job::~Job() {
    if (m_Applies != nullptr) {
        for (int i = 0; i < m_applies_size; ++i) {
            delete m_Applies[i];
        }
        delete[] m_Applies;
    }
}



//constructor
Job::Job(bool posting_status,int job_id,string occuption,string company_name,string company_location,string company_phone_number,string job_name,
         int scope, Date posting_date){
    set_experience();
    m_Applies= nullptr;
    m_applies_size=0;

    if(!set_status(posting_status)){
        this->m_posting_status= false;
    }
    if(!set_job_id(job_id)){
        this->m_job_id=0;
    }
    if (!set_occupation(occuption)){
        this->m_occupation="unknown";
    }
    if(!set_company_name(company_name)){
        this->m_company_name="unknown";
    }
    if(!set_location()){
        m_company_location="Unknown";
    }
    if(!set_phone_number(company_phone_number)){
        m_phone_number="Unknown";
    }
    if(!set_job_name(job_name)){
        m_job_name="Unknown";
    }
    if(!set_scope(scope)){
        m_scope=0;
    }
    if(!set_posting_date(posting_date)){
        m_posting_date=Date();
    }
}


//copy constructor
Job::Job(const Job& other)
        : m_posting_status(other.m_posting_status),
          m_job_id(other.m_job_id),
          m_occupation(other.m_occupation),
          m_company_name(other.m_company_name),
          m_company_location(other.m_company_location),
          m_phone_number(other.m_phone_number),
          m_job_name(other.m_job_name),
          m_experience_needed(other.m_experience_needed),
          m_scope(other.m_scope),
          m_posting_date(other.m_posting_date),
          m_applies_size(other.m_applies_size),
          m_Applies(nullptr) {

    // Check if other's applies array is not empty
    if (other.m_Applies != nullptr && other.m_applies_size > 0) {
        // Allocate memory for applies array
        m_Applies = new Apply*[m_applies_size];

        // Copy the applies
        for (int i = 0; i < m_applies_size; ++i) {
            m_Applies[i] = new Apply(*(other.m_Applies[i]));  // Assuming Apply has a copy constructor
        }
    }
}

//print job
void Job::print_job() const{
    cout << "Job status: ";
    if(m_posting_status){
        cout << "active" << endl;
    }
    else{
        cout << "closed" << endl;
    }
    cout << "Job id: " << m_job_id << endl;
    cout << "Job posting date: ";
    m_posting_date.printDate();
    cout << endl;
    cout << "Job application number: "<< m_applies_size << endl;
    cout << "Job name: " << m_job_name << endl;
    cout << "Jobs Occupation: " << m_occupation << endl;
    cout << "Company name: " << m_company_name << endl;
    cout << "Company location: " << m_company_location << endl;
    cout << "Company phone number: " << m_phone_number << endl;
    if (m_scope==0) {
        cout << "Full time job" << endl;
    }
    else {
        cout << "Part time job" << endl;
    }
    cout << m_experience_needed << " of experience needed!" << endl;
}


//add apply
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


//set applies
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



//set status
bool Job::set_status(const bool status) {
    if (status == true|| status == false) {
        m_posting_status = status;
        return true;
    } else {
        cout << "Status can be only active or inactive " << endl;
        return false;
    }
}


//set occupation
bool Job::set_occupation(const string& occupation) {
    if(Checkdigit(occupation))
    {
        m_occupation=occupation;
        return true;
    }
    else
        return false;
}


//set job name
bool Job::set_job_name(const string& job_name) {
    if (Checkdigit(job_name)) {
        m_job_name = job_name;
        return true;
    } else {
        return false;
    }
}


//set company name
bool Job::set_company_name(const string& company_name) {
    if (Checkdigit(company_name)) {
        m_company_name = company_name;
        return true;
    } else {
        return false;
    }
}



//set location
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


//set phone number
bool Job::set_phone_number(const string& phoneNumber) {
    if (isExactly10Digits(phoneNumber)) {
        m_phone_number = phoneNumber;
        return true;
    } else {
        cout << "Invalid phone number" << endl;
        return false;
    }
}


//set scope
bool Job::set_scope(const int& scope) {
    if(scope== 0 || scope == 1)
    {
        m_scope = scope;
        return true;
    }
    else {
        cout << "Invalid input" << endl;
        return false;
    }
}


//set experience
bool Job::set_experience() {
    const int maxAttempts = 3;
    int attempts = 0;

    while (attempts < maxAttempts) {
        cout << "Please enter new experience: ";
        int experience;
        cin >> experience;

        if (cin.fail()) {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            m_experience_needed = experience;
            return true;
        }

        attempts++;
    }

    cout << "Maximum number of attempts reached. Exiting." << endl;
    return false;
}


//set posting date
bool Job::set_posting_date(Date date ) {
    if(date.isCorrectDay(date.getDay()) && date.isCorrectMonth(date.getMonth()) && date.isCorrectYear(date.getYear())){
        m_posting_date=date;
        return true;
    }
    else{
        cout<<"Status has not changed, invalid date"<<endl;
        return false;
    }
}


//set job id
bool Job::set_job_id(const int &jobId) {
    this->m_job_id=jobId;
}

//is exactly 10 digit
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


//check digit
bool Job::Checkdigit(const string& input) {
    for (char ch : input) {
        if (isdigit(ch)) {
            cout << "Only letters are allowed." << endl;
            return false;
        }
    }
    return true;
}
