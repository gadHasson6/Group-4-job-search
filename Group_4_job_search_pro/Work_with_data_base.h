//
// Created by LENOVO on 22/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H
#define GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#endif //GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#include "sqlite3.h"
#include <iostream>
#include <vector>
using namespace std;


// Define a structure to hold employer information
struct EmployerInfo {
    long employer_id;
    string employer_name;
    string employer_email;
    string employer_phone_number;
    string password;
};
// Define a structure to hold candidate information
struct CandidateInfo {
    long candidate_id;
    string candidate_name;
    int candidate_age;
    char candidate_gender;
    string candidate_phone_number;
    string candidate_email;
    string candidate_living_area;
    float candidate_experience;
    string candidate_specialty;
    string password;
    string candidate_free_text;
    string resumePath;
};
// Define a structure to hold Apply information
struct ApplyInfo {
    long candidateID;
    int jobID;
    int submissionDay;
    int submissionMonth;
    int submissionYear;
    int applyID;
    string submissionStatus;
    string jobName;
    string companyName;
};
// Define a structure to hold Job information
struct JobInfo {
    int jobID;
    long employerID;
    string location;
    string profession;
    int job_type;
    int experience;
    string name;
    string company_name ;
    string contact;
    bool posting_status;
    int num_of_submmissions;
    int posting_day;
    int posting_month;
    int posting_year;
};
// Define a structure to hold candidate ids
struct CandidateId {
    long candidate_id;///
};
// Define a structure to hold employer ids
struct EmployerId {
    long employer_id;///
};


////////////////////////////opening a file
sqlite3 *openSQLiteFile(const char *filename);

////////////////////////////closing a file
void closeSQLiteFile(sqlite3 *db);

////////////////////////////Count the number of employers
int countRowsInEmployersTable(sqlite3* db);

////////////////////////////Count the number of candidates
int countRowsInCandidatesTable(sqlite3* db);

////////////////////////////Count the number of submissions
int countRowsInApplyTable(sqlite3* db);

////////////////////////////Count the number of jobs
int countRowsInJobTable(sqlite3* db);

////////////////////////////Counts employer jobs by ID
int countRowsByCreatorID(sqlite3* db, int idToSearch);

////////////////////////////Count submissions of a candidate by ID
int countRowsByApplyingID(sqlite3* db, long idToSearch);

////////////////////////////Counts job application submissions by ID
int countRowsByJobID(sqlite3* db, int idToSearch);

////////////////////////////Function to retrieve employer information from the employer table
vector<EmployerInfo> getEmployerInfo(sqlite3* db);

////////////////////////////Function to retrieve candidates information from the candidate table
vector<CandidateInfo> getCandidateInfo(sqlite3* db);

////////////////////////////Function to retrieve candidate id from the candidate table
vector<CandidateId> getCandidateId(sqlite3* db);

////////////////////////////Function to retrieve employer id from the employer table
vector<EmployerId> getEmployerId(sqlite3* db);

////////////////////////////Function to retrieve candidate information from the candidate table by ID
CandidateInfo getCandidateByID(sqlite3* db, long candidateID);

////////////////////////////Function to retrieve apply list information from the apply table
vector<ApplyInfo> getAllApplies(sqlite3* db);

////////////////////////////Function to retrieve jobs list information from the job table
vector<JobInfo> getAllJobs(sqlite3* db);

////////////////////////////Function to retrieve apply list information by candidateID from the apply table
vector<ApplyInfo> getSubmissionsForApplicant(sqlite3* db, long applicantID);

////////////////////////////Function to retrieve jobs list information by jobID from the job table
vector<JobInfo> getJobsByID(sqlite3* db, long jobID);