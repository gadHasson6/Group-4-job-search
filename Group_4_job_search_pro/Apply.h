//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_APPLY_H
#define GROUP_4_JOB_SEARCH_PRO_APPLY_H

// Include necessary headers
#include "Date.h"
#include "Job.h"
#include "Candidate.h"
#include <string>
#include <iostream>

class Apply {
private:

    long numberOfSubmission;
    long candidateID;
    long jobID;
    Job* job;
    Candidate* candidate;
    Date submissionDate;
    string submissionStatus;

public:

    //constructors:
    Apply(); //Default constructor
    Apply(long numberOfSubmission, long candidateID, long jobID,Job* job,
          Candidate* candidate, Date submissionDate, string submissionStatus); //Parameter constructor
    Apply(const Apply& other);  //Copy constructor


    //set functions:
    void setNumberOfSubmission(long numberOfSubmission);
    void setCandidateID(long candidateID);
    void setJobID(long jobID);
    void setJob(Job* job);
    void setCandidate( Candidate* candidate);
    void setSubmissionDate(const Date& submissionDate);
    void setSubmissionStatus(const string& submissionStatus);


    //get functions:
    long getNumberOfSubmission() const;
    long getCandidateID() const;
    long getJobID() const;
    const Job* getJob() const;
    const Candidate* getCandidate() const;
    Date getSubmissionDate() const;
    string getSubmissionStatus() const;

    //other functions:
    bool operator==(const Apply& other) const; // == operator

    // Print functions:
    void printEmployer() const;
    void printCandidate() const;

    //destructor:
    ~Apply();

};


#endif //GROUP_4_JOB_SEARCH_PRO_APPLY_H
