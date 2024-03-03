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

    long candidateID;
    long jobID;
//    Job* job;
//    Candidate* candidate;
    Date submissionDate;
    long numberOfSubmission;
    string submissionStatus;// should have 3 options: - 1.. 2.
    string jobName;
    string companyName;

public:
 //להוסיף אופציה רביעית שיהיה להשאיר אתז ה בתהליך  פונקציה שמבצעת עריכה לסטטוס -מתודה שמופעלת על אובייקט APPLY אבל היא לא מקבלת סטרינג או מספר ברגע שעשיתי
    //constructors:
    Apply(); //Default constructor
    Apply(long numberOfSubmission, long candidateID, long jobID,Job* job,
          Candidate* candidate, Date submissionDate, const string& submissionStatus); //Parameter constructor
    Apply(const Apply& other);  //Copy constructor


    //set functions:
    void setNumberOfSubmission(long o_numberOfSubmission);
    void setCandidateID(long o_candidateID);
    void setJobID(long o_jobID);
    void setJob(Job* o_job);
    void setCandidate( Candidate* o_candidate);
    void setSubmissionDate(const Date& o_submissionDate);
    void setSubmissionStatus(const string& o_submissionStatus);


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