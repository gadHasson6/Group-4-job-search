
//  Reminder : the fields of Apply class are:
//   1. int numberOfSubmission;
//   2. int candidateID;
//   3. int jobID;
//   4. Date submissionDate;
//   5. string submissionStatus;
//   6. string jobName;
//   7. string companyName;



#include <limits>
#include "Apply.h"

//Default constructor:

Apply::Apply() {

    this -> numberOfSubmission = 0;
    this -> candidateID = 0;
    this -> jobID = 0;
    this -> submissionDate = Date();
    this -> submissionStatus = "In progress";
    this -> jobName = "None";
    this -> companyName = "None";
}


//Parameter constructor:

Apply::Apply(int numberOfSubmission, int candidateID, int jobID, Date submissionDate,string submissionStatus , string jobName,  string companyName) {

    this -> numberOfSubmission = numberOfSubmission;
    this -> candidateID = candidateID;
    this -> jobID = jobID;
    this -> submissionDate = Date(submissionDate.getDay(),submissionDate.getMonth(), submissionDate.getYear());
    this -> submissionStatus = submissionStatus;
    this -> jobName = jobName;
    this -> companyName = companyName;

}

// Copy constructor:
Apply::Apply(const Apply& other)
        : numberOfSubmission(other.numberOfSubmission),
          candidateID(other.candidateID),
          jobID(other.jobID),
          submissionDate(other.submissionDate),
          submissionStatus(other.submissionStatus),
          jobName(other.jobName),
          companyName(other.companyName){}


//  == operator :
bool Apply::operator==(const Apply& other) const {
    return (  //if every field is equal then the operator returns true.
            numberOfSubmission == other.numberOfSubmission &&
            candidateID == other.candidateID &&
            jobID == other.jobID &&
            submissionDate == other.submissionDate &&
            submissionStatus == other.submissionStatus &&
            jobName == other.jobName &&
            companyName == other.companyName
    );
}



// Print function for employer with candidateID:
void Apply::printEmployer() const {

    cout << "Number of submission: " << numberOfSubmission << endl;
    cout << "Submission Date: " ; this -> submissionDate.printDate();
    cout << "Submission Status: " << submissionStatus << endl;
    cout << "job name: " << jobName << endl;
    cout << "jobID: " << jobID << endl;
    cout << "company name: " << companyName << endl;


}

// Print function for candidate (with jobID)
void Apply::printCandidate() const {

    cout << "job name: " << jobName << endl;
    cout << "jobID: " << jobID << endl;
    cout << "company name: " << companyName << endl;
    cout << "Submission date: " ; this -> submissionDate.printDate();
    cout << "Submission status: " << submissionStatus << endl;
    cout << "Number of submission: " << numberOfSubmission << endl;

}


//SET FUNCTIONS:
void Apply::setNumberOfSubmission(int o_numberOfSubmission) {
    this -> numberOfSubmission = o_numberOfSubmission;}
void Apply::setCandidateID(int o_candidateID) {
    this -> candidateID = o_candidateID;}
void Apply::setJobID(int o_jobID) {
    this -> jobID = o_jobID;}
void Apply::setSubmissionDate(const Date& o_submissionDate) {
    this -> submissionDate = o_submissionDate;}
void Apply::setSubmissionStatus(const std::string& o_submissionStatus) {
    this -> submissionStatus = o_submissionStatus;}
void Apply::setJobName(string o_jobName) {
    this -> jobName = o_jobName;}
void Apply::setCompanyName(string o_companyName) {
    this -> companyName =o_companyName;}




//GET FUNCTIONS:
int Apply::getNumberOfSubmission() const {
    return this -> numberOfSubmission;}
int Apply::getCandidateID() const {
    return this -> candidateID;}
int Apply::getJobID() const {
    return this -> jobID;}
Date Apply::getSubmissionDate() const {
    return this-> submissionDate;}
string Apply::getSubmissionStatus() const {
    return this-> submissionStatus;}
string Apply::getJobName() const {
    return this-> jobName;}
string Apply::getCompanyName() const {
    return this-> companyName;}

//DESTRUCTOR
Apply::~Apply() {

}

void Apply::editStatus(Apply &other) {

    cout<<"please choose the status: "<<endl;
    int choice=0;
    cout<<"1. not relevant"<<endl;
    cout<<"2. invited to a job interview"<<endl;
    cout<<"3. accepted"<<endl;
    cout<<"4. In progress"<<endl;
    cin>>choice;
    if (!cin.fail() && choice >= 1 && choice <= 4){
        switch (choice) {
            case 1:{
                this-> submissionStatus = "not relevant";
                break;
            }
            case 2: {
                this-> submissionStatus = "invited to a job interview";
                break;
            }
            case 3: {
                this-> submissionStatus = "accepted";
                break;
            }
            case 4: {
                this-> submissionStatus = "In progress";
                break;
            }
        }
    }
    else {
        // Clear the error flag
        cin.clear();
        // Discard invalid input from the input buffer
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
}










