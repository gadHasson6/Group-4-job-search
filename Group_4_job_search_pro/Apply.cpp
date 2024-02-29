    //Reminder of Apply the fields:

//long numberOfSubmission;
//    long candidateID;
//    long jobID;
//    job* job;
//    candidate* candidate;
//    date dateOfSubmission;
//    string statusOfSubmission;
// Created by LENOVO on 21/02/2024.
//

#include "Apply.h"


Aply::Apply(){

    numberOfSubmission = 0;
    candidateID = 000000000;
    jobID = 000000000;
    job =  nullptr;
    candidate =  nullptr;;
    dateOfSubmission = 0 ;
    string statusOfSubmission = "none";

}

Apply::Apply(long numberOfSubmission , long candidateID , long jobI , job* job , candidate* candidate , date dateOfSubmission ,string statusOfSubmission){

    this -> numberOfSubmission = numberOfSubmission;
    this -> candidateID = candidateID;
    this -> jobI = jobI;
    this -> job = &job ;
    this -> candidate = &candidate ;
    this ->  dateOfSubmission  = dateOfSubmission;
    this -> statusOfSubmission = statusOfSubmission;

}