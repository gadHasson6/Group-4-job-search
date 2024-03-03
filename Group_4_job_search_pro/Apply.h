//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_APPLY_H
#define GROUP_4_JOB_SEARCH_PRO_APPLY_H

// Include necessary headers
#include "Date.h"
//#include "Job.h"
//#include "Candidate.h"
#include <string>
#include <iostream>

class Job;
class Candidate;

class Apply {

private:

    int numberOfSubmission;
    int candidateID;
    int jobID;
    Date submissionDate;
    string submissionStatus;
    string jobName;
    string companyName;

public:

    //constructors:
    Apply(); //Default constructor
    Apply(int numberOfSubmission, int candidateID, int jobID, Date submissionDate,string submissionStatus , string jobName,  string companyName); //Parameter constructor
    Apply(const Apply& other);  //Copy constructor


    //set functions:
    void setNumberOfSubmission(int o_numberOfSubmission);
    void setCandidateID(int o_candidateID);
    void setJobID(int o_jobID);
    void setSubmissionDate(const Date& o_submissionDate);
    void setSubmissionStatus(const string& o_submissionStatus);
    void setJobName(string o_jobName);
    void setCompanyName(string o_companyName);


    //get functions:
    int getNumberOfSubmission() const;
    int getCandidateID() const;
    int getJobID() const;
    Date getSubmissionDate() const;
    string getSubmissionStatus() const;
    string getJobName() const;
    string getCompanyName() const;

    //other functions:
    bool operator==(const Apply& other) const; // == operator

    // Print functions:
    void printEmployer() const;
    void printCandidate() const;

    //destructor:
    ~Apply();

};


#endif //GROUP_4_JOB_SEARCH_PRO_APPLY_H