//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
#define GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
using namespace std;
#include "iostream"
# include "User.h"
# include "Job.h"
# include <vector>
#include <string>
#include <limits>
#include <filesystem>

class Candidate : public User {
    private:
    string resumePath;
    vector<Job> appliedJobs;
    string personalInformation;

public:
        Candidate();
        Candidate(char inputTypeOfUser, string inputName, long inputId, int inputPassword,
                  string inputFeedback, string inputResumePath,
                  vector<Job> inputAppliedJobs, string inputPersonalInformation);
        Candidate(const Candidate &other);
       bool setResumeFilePath(const string& newResumePath);
       void setAppliedJobs(const vector<Job> &newAppliedJobs);
       bool setPersonalInformation(string newPersonalInformation);
       void addJobApplication(Job newJobApplication);
       void deleteJobApplication(int indexToDelete);
       void editProfile();
       float calculateSalary();
       void viewSubmissions();
       void submitResume(string resumePathToSubmit);





};


#endif //GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
