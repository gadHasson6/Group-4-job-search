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

// Created by User on 29/02/2024.

#include "Apply.h"


//Default constructor:
Apply::Apply() {

    this -> numberOfSubmission = 0;
    this -> candidateID = 0;
    this -> jobID = 0;
    this -> job = nullptr;
    this -> candidate = nullptr;
    this -> submissionDate = submissionDate.Date(0,0,0);
    this -> submissionStatus = "no submissions found";

}


//Parameter constructor:
//******************************* note: still missing parameters for the submissionDate.Date() ******///

Apply::Apply(long numberOfSubmission, long candidateID, long jobID,Job* job,
             Candidate* candidate, Date submissionDate, string submissionStatus) {

    this -> numberOfSubmission = numberOfSubmission;
    this -> candidateID = candidateID;
    this -> jobID = jobID;
    this -> job = &job;
    this -> candidate = &candidate;
    this -> submissionDate = submissionDate.Date();
    this -> submissionStatus = submissionStatus;

}

// Copy constructor:
//*********************************** should check the copy constructor for deep copy *************************//

Apply::Apply(const Apply& other)
        : numberOfSubmission(other.numberOfSubmission),
          candidateID(other.candidateID),
          jobID(other.jobID),
          job(nullptr),
          candidate(nullptr),
          submissionDate(other.submissionDate),
          submissionStatus(other.submissionStatus) {
    // Copy job if not nullptr
    if (other.job) {
        job = new Job(*other.job);
    }

    // Copy candidate if not nullptr
    if (other.candidate) {
        candidate = new Candidate(*other.candidate);
    }
}


//SET FUNCTIONS:
void Apply::setNumberOfSubmission(long numberOfSubmission) {
    this ->  numberOfSubmission = numberOfSubmission;}
void Apply::setCandidateID(long candidateID) {
    this ->  candidateID = candidateID;}
void Apply::setJobID(long jobID) {
    this ->  jobID = jobID;}





//GET FUNCTIONS:
long const Apply::getNumberOfSubmission() {
    return this -> numberOfSubmission;}
long const Apply::getCandidateID() {
    return this -> candidateID;}
long const Apply::getJobID() {
    return this -> jobID;}
Date Apply::getSubmissionDate() const {
    return this->submissionDate;
}



Job *Apply::getJob() const {
    return this->job;
}

string Apply::getSubmissionStatus() const {
    return this->submissionStatus;
}


