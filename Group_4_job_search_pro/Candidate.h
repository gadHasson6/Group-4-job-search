//
// Created by LENOVO on 21/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
#define GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H
using namespace std;
#include "iostream"
# include "User.h"
# include "Apply.h"
#include "Job.h"
#include <string>
#include <limits>
#include <filesystem>

class Candidate : public User {
private:
    string resumePath;
    Apply** appliedJobs;
    int appliedJobSize;
    string personalInformation;
    int age;
    char gender;  //W for women, M for men
    string residence;
    float workExperience;
    string specialty;


public:

    //constructors
    Candidate();
    Candidate(string inputName, long inputId, string inputEmail, string inputPassword, string inputPhoneNumber, int inputRating, string inputFeedback,
              string inputResumePath, string inputPersonalInformation, int inputAge, char inputGender,
              float inputWorkExperience, string inputSpecialty);
    Candidate(const Candidate &other);

    //get
    string getResumePath() const;
    string getPersonalInformation() const;
    Apply** getAppliedJob() const;
    int getAge() const;
    char getGender() const;
    string getResidence() const;
    float getWorkExperience() const;
    string getSpecialty() const;
    int getAppliedJobSize() const;

    //set
    bool setResumeFilePath(const string& newResumePath);
    bool setPersonalInformation(string newPersonalInformation);
    bool setAge(int inputAge);
    bool setGender(char inputGender);
    bool setResidence();
    bool setWorkExperience(float inputWorkExperience);
    bool setSpecialty(string inputSpecialty);
    bool setAppliedJobs(Apply** other, int size);

    //Additional functions
    void printThisCandidateInfo() const;
    void addApply(const Apply* &addMe);  //need to finish this function
    void cancelApply(const Apply* &deleteMe);  //need to finish this function
    Apply* SortFromNewToOldByDate(Apply* sortMe); //need to finish this function
    void printTipsForResume();
    float calculateSalary();
    void viewSubmissions();
    void submitResume(string resumePathToSubmit);

    //functions for "look for jobs"
    void lookForJobs(const Job** &allJobs, int size);
    Job** byJobScope(const Job** &allJobs, int size, string name, int &newSize);
    Job** byJobResident(const Job **&allJobs, int size, string resident, int &newSIze);
    Job** byJobExperience(const Job **&allJobs, int size, int experience, int &newSize);

    //functions for "edit profile"
    void editName();
    void editId();
    void editPassword();
    void editFeedback();
    void editResumePath();
    void editPersonalInformation();
    void editProfile();

};


#endif //GROUP_4_JOB_SEARCH_PRO_CANDIDATE_H