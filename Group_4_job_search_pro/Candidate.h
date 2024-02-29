//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
#define GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
using namespace std;
#include "iostream"
# include "User.h"
# include "Apply.h"
#include <string>
#include <limits>
#include <filesystem>

class Candidate : public User {
private:
    string resumePath;
    Apply* appliedJobs;
    string personalInformation;

public:
    Candidate();
    Candidate(string inputName, long inputId, string inputPassword,
              string inputFeedback, string inputResumePath, string inputPersonalInformation);
    Candidate(const Candidate &other);
    string getResumePath();
    string getPersonalInformation();
    bool setResumeFilePath(const string& newResumePath);
    bool setPersonalInformation(string newPersonalInformation);
    void editProfile();
    float calculateSalary();
    void viewSubmissions();
    void submitResume(string resumePathToSubmit);
    void editName();
    void editId();
    void editPassword();
    void editFeedback();
    void editResumePath();
    void editPersonalInformation();


};


#endif //GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
