//
// Created by LENOVO on 21/02/2024.
//
include <Date.h>
#ifndef GROUP_4_JOB_SEARCH_PRO_APPLY_H
#define GROUP_4_JOB_SEARCH_PRO_APPLY_H


class Apply {

private:

    //THE FIELDS OF APPLY CLASS:
    long numberOfSubmission;
    long candidateID;
    long jobID;
    Job* job;
    Candidate* candidate;
    Date dateOfSubmission;
    string statusOfSubmission;

public:

    Apply();
    Apply(long numberOfSubmission , long candidateID , long jobI , job* job , candidate* candidate , date dateOfSubmission ,string statusOfSubmission);


};


#endif //GROUP_4_JOB_SEARCH_PRO_APPLY_H
