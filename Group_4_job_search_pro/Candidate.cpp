//
// Created by LENOVO on 21/02/2024.
//

#include "Candidate.h"

//Default constructor
Candidate::Candidate() : User() {
    this->resumePath="";
    this->appliedJobs={};
    this->personalInformation="";
}

//Constructor
Candidate::Candidate(string inputName, long inputId, int inputPassword, string inputFeedback, string inputResumePath,
                     vector<Job> inputAppliedJobs, string inputPersonalInformation)
                     : User(inputName,inputId,inputPassword,inputFeedback), resumePath(inputResumePath),
                       appliedJobs(inputAppliedJobs),
                       personalInformation(inputPersonalInformation){

}

//Copy constructor
Candidate::Candidate(const Candidate &other) : User(other), resumePath(other.resumePath),
                                               appliedJobs(other.appliedJobs),
                                               personalInformation(other.personalInformation)  {

}


//set resume path
void Candidate::setResumeFilePath(string newResumePath) {
    this->resumePath = newResumePath;
}


//set applied job
void Candidate::setAppliedJobs(const vector<Job> &newAppliedJobs) {
    appliedJobs = newAppliedJobs;
}


//set personal information
void Candidate::setPersonalInformation(string newPersonalInformation) {
    personalInformation=newPersonalInformation;
}


//add job application
void Candidate::addJobApplication(Job newJobApplication) {
    appliedJobs.push_back(newJobApplication);   //adds the new job application to the end of the appliedJobs vector
}


//delete job
void Candidate::deleteJobApplication(int indexToDelete) {
    if (indexToDelete >= 0 && indexToDelete < appliedJobs.size()) {
        appliedJobs.erase(appliedJobs.begin() + indexToDelete); //removes the job application at the specified index.
    } else {
        cout << "Invalid index to delete." << endl;
    }
}

