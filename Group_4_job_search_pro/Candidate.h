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
#include <algorithm>  // Include for swap

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

    //destructor
    ~Candidate();

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
    bool setPersonalInformation(const string &newPersonalInformation);
    bool setAge(int inputAge);
    bool setGender(char inputGender);
    bool setResidence();
    bool setWorkExperience(float inputWorkExperience);
    bool setSpecialty(const string &inputSpecialty);
    bool setAppliedJobs(Apply** other, int size);

    //Additional functions
    void printThisCandidateInfo() const;
    void addApply(Apply* addMe);
    void cancelApply( Apply* deleteMe);
    void printTipsForResume();
    float calculateSalary();
    void viewSubmissions();
    void submitResume(string resumePathToSubmit);

    //functions for "choose order to see jobs"
    [[nodiscard]]  Apply** sortFromNewToOldByDate() const ;  //[[nodiscard]] would indicate that the returned array should be used and not ignored.
    void chooseOrderToSeeSubmissions() const;

    //functions for "look for jobs"
    void lookForJobs(const Job** &allJobs, int size);
    Job** byJobScope(const Job **&allJobs, int size, const string &name, int &newSize);
    Job** byJobResident(const Job **&allJobs, int size,const string &resident, int &newSize);
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