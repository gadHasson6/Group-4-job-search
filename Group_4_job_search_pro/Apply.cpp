//
// Created by LENOVO on 21/02/2024.
//
/*
Reminder : the fields of Apply class are:
    1.long numberOfSubmission;
    2.long candidateID;
    3.long jobID;
    4.Job* job;
    5.Candidate* candidate;
    6.Date submissionDate;
    7.string submissionStatus
*/
#include "Apply.h"

//Default constructor:
Apply::Apply() {

    this -> numberOfSubmission = 0;
    this -> candidateID = 0;
    this -> jobID = 0;
//    this -> job = nullptr;
//    this -> candidate = nullptr;
    this->submissionDate = Date();
    this -> submissionStatus = "In progress";

}


//Parameter constructor:
//******************************* note: check is missing parameters for the submissionDate.Date() ******///

Apply::Apply(int numberOfSubmission, long candidateID, int jobID, Date submissionDate, const string& submissionStatus) {

    this -> numberOfSubmission = numberOfSubmission;
    this -> candidateID = candidateID;
    this -> jobID = jobID;
//    this -> job = job;
//    this -> candidate = candidate;
    this -> submissionDate = Date(submissionDate.getDay(),submissionDate.getMonth(), submissionDate.getYear());
    this -> submissionStatus = submissionStatus;

}

// Copy constructor:
//******************************* note: check the copy constructor for deep copy *************************//

Apply::Apply(const Apply& other)
        : numberOfSubmission(other.numberOfSubmission),
          candidateID(other.candidateID),
          jobID(other.jobID),
//          job(nullptr),
//          candidate(nullptr),
          submissionDate(other.submissionDate),
          submissionStatus(other.submissionStatus) {

}
//  == operator :
bool Apply::operator==(const Apply& other) const {
    return (
            numberOfSubmission == other.numberOfSubmission
//            &&
//            candidateID == other.candidateID &&
//            jobID == other.jobID &&
//            ((job == nullptr && other.job == nullptr) || (*job == *(other.job))) &&
//            ((candidate == nullptr && other.candidate == nullptr) || (*candidate == *(other.candidate))) &&
//            submissionDate == other.submissionDate &&
//            submissionStatus == other.submissionStatus
    );
}



// Print function for employer with candidateID:
void Apply::printEmployer() const {
//    cout << "Employer Information:" << endl;
    if (candidate) { //if candidate is not nullptr
//        cout << "Candidate ID: " << candidateID << endl;
        cout << "Candidate Information:" << endl;
        candidate->printThisCandidateInfo();
    }
    cout << "Submission Number: " << numberOfSubmission << endl;
    cout << "Submission Date: " ; this -> submissionDate.printDate();
    cout << "Submission Status: " << submissionStatus << endl;
/*  Reminder : the fields that should be printed are:
                   1.numberOfSubmission;
                   2.long candidateID;
                   5.Candidate* candidate;
                   6.submissionDate;
                   7.submissionStatus                       */
//    cout << "These are all of the employer details." << endl;

}

// Print function for candidate (with jobID)
void Apply::printCandidate() const {
//    cout << "Candidate Information:" << endl;
    cout << "Number of Submission: " << numberOfSubmission << endl;
//    cout << "Job ID: " << jobID << endl;
    // Call print_job method from Job class if job is not nullptr
    if (job) {
        job->print_job();
    }
    cout << "Submission Date: " ; this -> submissionDate.printDate();
    cout << "Submission Status: " << submissionStatus << endl;
    /*  Reminder : the fields that should be printed are:
                   1.numberOfSubmission;
                   2.long candidateID;
                   3.long jobID;
                   4.Job* job;
                   6.submissionDate;
                   7.submissionStatus                       */
//    cout << "These are all of the candidate details." << endl;
}


//SET FUNCTIONS:
void Apply::setNumberOfSubmission(int o_numberOfSubmission) {
    this ->  numberOfSubmission = o_numberOfSubmission;}
void Apply::setCandidateID(long o_candidateID) {
    this ->  candidateID = o_candidateID;}
void Apply::setJobID(int o_jobID) {
    this ->  jobID = o_jobID;}
void Apply::setJob(Job* o_job) {
    this->job = o_job;}
void Apply::setCandidate(Candidate* o_candidate) {
    this->candidate = o_candidate;}
void Apply::setSubmissionDate(const Date& o_submissionDate) {
    this->submissionDate = o_submissionDate;}
void Apply::setSubmissionStatus(const std::string& o_submissionStatus) {
    this->submissionStatus = o_submissionStatus;}




//GET FUNCTIONS:
int Apply::getNumberOfSubmission() const {
    return this -> numberOfSubmission;}
long Apply::getCandidateID() const {
    return this -> candidateID;}
int Apply::getJobID() const {
    return this -> jobID;}
Date Apply::getSubmissionDate() const {
    return this-> submissionDate;}
const Job* Apply::getJob() const {
    return this-> job;}
const Candidate* Apply::getCandidate() const {
    return this-> candidate;}
string Apply::getSubmissionStatus() const {
    return this-> submissionStatus;}

//DESTRUCTOR
Apply::~Apply() {
    // Release dynamic memory if allocated
    delete job;
    delete candidate;
}