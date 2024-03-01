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

    Apply(); //Default constructor
    Apply(long numberOfSubmission, long candidateID, long jobID,Job* job,
          Candidate* candidate, Date submissionDate, string submissionStatus); //Parameter constructor
    Apply(long numberOfSubmission, long candidateID, long jobID, const Job* job,
          const Candidate* candidate, Date submissionDate, string submissionStatus)  //Copy constructor


    //set functions:
    void setNumberOfSubmission(long numberOfSubmission);
    void setCandidateID(long candidateID);
    void setJobID(long jobID);
    void setJob(Job* job);
    void setCandidate(Candidate* candidate);
    void setSubmissionDate(const Date& submissionDate);
    void setSubmissionStatus(const std::string& submissionStatus);

    //get functions:
    long const getNumberOfSubmission();
    long const getCandidateID();
    long const getJobID();
    Job* getJob () const;
    Date getSubmissionDate() const;
};



#endif //GROUP_4_JOB_SEARCH_PRO_APPLY_H
.

