//
// Created by LENOVO on 28/02/2024.
//

#include "Job_search_system.h"

Job_search_system::Job_search_system() {
    num_of_jobs = 0;
    num_of_submissions = 0;
    num_of_candidates = 0;
    num_of_employers = 0;
    num_of_all_submissions = 0;
    current_candidate = nullptr;
    current_employer = nullptr;
    employers_list = nullptr;
    candidates_list = nullptr;
    jobs_list = nullptr;
    submissions_list = nullptr;
}

void Job_search_system::employer_candidate_menu() {
    bool flag = true;
    while (flag){
        cout << "Please enter whether you identify yourself as an employer or a job candidate\n"
                "1) Employer\n"
                "2) Candidate\n"
                "3) Cancel\n";
        int choice = 0;
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue; // Go to the next iteration of the loop
        }
        switch (choice) {
            case 1: {
                employer_login_registration_menu();
                flag = false;
                break;
            }
            case 2: {
                candidate_login_registration_menu();
                flag = false;
                break;
            }
            case 3: {
                flag = false;
                break;
            }
            default: {
                cout << "Invalid input. Please enter a valid integer.\n";
                break;
            }

        }
    }
    cout << "Thanks! See you next time!\n";
}


void Job_search_system::employer_login_registration_menu() {
    bool flag = true;
    while (flag){
        cout << "Please enter whether you are an existing user or a new user\n"
                "1) Login\n"
                "2) Register\n"
                "3) Cancel\n";
        int choice = 0;
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue; // Go to the next iteration of the loop
        }
        switch (choice) {
            case 1: {
                flag = employer_login();
                break;
            }
            case 2: {
//                flag = employer_registration();
                break;
            }
            case 3: {
                flag = false;
                break;
            }
            default: {
                cout << "Invalid input. Please enter a valid integer.\n";
                break;
            }

        }
    }
    cout << "Moves to the previous menu\n";
}


void Job_search_system::candidate_login_registration_menu() {
    bool flag = true;
    while (flag){
        cout << "Please enter whether you are an existing user or a new user\n"
                "1) Login\n"
                "2) Register\n"
                "3) Cancel\n";
        int choice = 0;
        cin >> choice;

        // Validate input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a valid integer." << endl;
            continue; // Go to the next iteration of the loop
        }
        switch (choice) {
            case 1: {
                flag = candidate_login();
                if (current_candidate){
                    candidate_main_menu();
                    updateForCandidate_login();
                    delete [] current_candidate;
                    for (int i = 0; i < num_of_jobs; ++i) {
                        delete jobs_list[i];
                    }
                    delete [] jobs_list;
//                    delete [] submissions_list;
                }
                break;
            }
            case 2: {
                flag = candidate_registration();
                break;
            }
            case 3: {
                flag = false;
                break;
            }
            default: {
                cout << "Invalid input. Please enter a valid integer.\n";
                break;
            }

        }
    }
    cout << "Moves to the previous menu\n";
}


bool Job_search_system::candidate_registration() {
    current_candidate = new Candidate();
    string newName = "";
    bool flag = true;
    while (flag) {
        cout << "Enter the new name (no longer than 20 letters): " << endl;
        getline(cin, newName); // read the entire line
        flag = !(current_candidate->setName(newName));

        if (!flag) {
            cout << "Name updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try again\n";
        }
    }
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);
    vector<CandidateId> c_id_list = getCandidateId(db);
    int size = countRowsInCandidatesTable(db);
    closeSQLiteFile(db);
    flag = true;
    long newId = 0;
    while (flag) {
        cout << "Enter new id (no longer than 9 numbers): " << endl;
        cin >> newId;
        if (cin.fail() || to_string(newId).length() > 9) {
            // Invalid input (not an integer or longer than 9)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            bool already_exists = false;
            for (int i = 0; i < size; ++i) {
                if (newId == c_id_list[i].candidate_id){
                    cout << "ID already exists in the system, please choose another ID\n";
                    i = size;
                    already_exists = true;
                    int choice = 0;
                    while (choice != 1){
                        cout << "This ID already exists in the system, would you like to continue the registration process?\n"
                                "1) Yes, I got my ID number wrong.\n"
                                "2) No, I already have a user.\n";
                        cin >> choice;
                        if (cin.fail() || choice < 1 || choice > 2) {
                            // Invalid input (not a char)
                            cin.clear(); // Clear the error flag
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            cout << "Invalid input. try again\n";
                        }
                        if (choice == 2){
                            delete [] current_candidate;
                            return true;
                        }
                    }

                }
            }
            if (!already_exists)
                flag = !(current_candidate->setId(newId));
            if (!flag){
                cout << "ID updated successfully!" << endl;
            }
        }
    }
    string newEmail = "";
    flag = true;
    while (flag) {
        cout << "Enter the new Email (must include the character @): " << endl;
        getline(cin, newEmail); // read the entire line
        flag = !(current_candidate->setEmail(newEmail));

        if (!flag) {
            cout << "Email updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try again\n";
        }
    }
    string inputPassword = "";
    flag = true;
    while (flag) {
        cout << "Enter the new Password (must contain lowercase letters, uppercase letters and numbers): " << endl;
        getline(cin, inputPassword); // read the entire line
        flag = !(current_candidate->setPassword(inputPassword));

        if (!flag) {
            cout << "Password updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try again\n";
        }
    }
    string inputPhoneNumber = "";
    flag = true;
    while (flag) {
        cout << "Enter the new Phone Number (must contain only digits (10 characters)): " << endl;
        getline(cin, inputPhoneNumber); // read the entire line
        flag = !(current_candidate->setPhoneNumber(inputPhoneNumber));

        if (!flag) {
            cout << "Phone Number updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try again\n";
        }
    }
    string newResumePath = "";
    flag = true;
    while (flag) {
        cout << "Please enter the path of your resume file: " << endl;
        getline(cin, newResumePath); // read the entire line
        flag = !(current_candidate->setResumeFilePath(newResumePath));

        if (flag) {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please try again\n";
        }
    }
    string newPersonalInformation = "";
    flag = true;
    while (flag) {
        cout << "Enter new personal information (no longer than 50 chars):  " << endl;
        getline(cin, newResumePath); // read the entire line
        flag = !(current_candidate->setPersonalInformation(newPersonalInformation));

        if (flag) {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please try again\n";
        } else {
            cout << "Personal information updated successfully!" << endl;
        }
    }
    flag = true;
    while (flag){
        flag = !current_candidate->setResidence();
        if (flag) {
            cout << "Please try again\n";
        } else {
            cout << "Residence updated successfully!" << endl;
        }
    }
    char gender = 'm';
    flag = true;
    while (flag) {
        cout << "Please enter your gender: M if you are a man or W if you are a woman: " << endl;
        cin >> gender;
        if (cin.fail() ) {
            // Invalid input (not a char)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            flag = !(current_candidate->setGender(gender));
            if (!flag){
                cout << "Gender updated successfully!" << endl;
            } else{
                cout << "Invalid input. try again\n" ;
            }
        }
    }
    int Age = 0;
    flag = true;
    while (flag) {
        cout << "Please enter your age (age must be a integer number in range 1-120): " << endl;
        cin >> Age;
        if (cin.fail() ) {
            // Invalid input (not a char)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            flag = !(current_candidate->setAge(Age));
            if (!flag){
                cout << "Age updated successfully!" << endl;
            } else{
                cout << "Invalid input. try again\n" ;
            }
        }
    }
    float workExperience;
    flag = true;
    while (flag) {
        cout << "Please enter your experience in years (a number in the range 0-100): " << endl;
        cin >> workExperience;
        if (cin.fail() || workExperience < 0 || workExperience > 100) {
            // Invalid input (not a char)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            flag = !(current_candidate->setWorkExperience(workExperience));
            if (!flag){
                cout << "Experience updated successfully!" << endl;
            } else{
                cout << "Invalid input. try again\n" ;
            }
        }
    }
    string specialty = "";
    flag = true;
    while (flag) {
        cout << "Enter your new Specialty (no longer than 25 characters): " << endl;
        getline(cin, specialty); // read the entire line
        flag = !(current_candidate->setSpecialty(specialty));

        if (!flag) {
            cout << "Specialty Number updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try again\n";
        }
    }
    cout << "A new user has been created!\n"
            "Welcome and good luck!\n";
    CandidateInfo cc;
    cc.candidate_id = current_candidate->getId();
    cc.candidate_name = current_candidate->getName();
    cc.candidate_age = current_candidate->getAge();
    cc.candidate_gender = current_candidate->getGender();
    cc.candidate_phone_number = current_candidate->getPhoneNumber();
    cc.candidate_email = current_candidate->getEmail();
    cc.candidate_living_area = current_candidate->getResidence();
    cc.candidate_experience = current_candidate->getWorkExperience();
    cc.candidate_specialty = current_candidate->getSpecialty();
    cc.password = current_candidate->getPassword();
    cc.candidate_free_text = current_candidate->getPersonalInformation();
    cc.resumePath = current_candidate->getResumePath();
    sqlite3 * db3 = openSQLiteFile(fff);
    insertCandidateData(db3, cc);
    closeSQLiteFile(db3);
    delete current_candidate;
    return true;
}


bool Job_search_system::candidate_login() {
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);
    vector<CandidateId> c_id_list = getCandidateId(db);
    int size = countRowsInCandidatesTable(db);
    closeSQLiteFile(db);
    bool flag = true;
    long newId = 0;
    while (flag) {
        cout << "Enter your id (no longer than 9 numbers): " << endl;
        cin >> newId;
        if (cin.fail() || to_string(newId).length() > 9) {
            // Invalid input (not an integer or longer than 9)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            for (int i = 0; i < size; ++i) {
                if (newId == c_id_list[i].candidate_id) {
                    i = size;
                    flag = false;
                }
            }
        }
        if (flag){
            int choice = 0;
            while (choice != 1){
                cout << "The ID number you registered does not appear in the system, would you like to continue the registration process?\n"
                        "1) Yes, I must have got my ID number wrong.\n"
                        "2) No, I want to register.\n";
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 2) {
                    // Invalid input (not a char)
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. try again\n";
                }
                if (choice == 2){
                    return true;
                }
            }
        }
    }
    sqlite3 * db1 = openSQLiteFile(fff);
    CandidateInfo c_candidate = getCandidateByID(db1,newId);
    closeSQLiteFile(db1);
    string password = " ";
    flag = true;
    while (flag){
        cout << "Please enter your password:\n";
        getline(cin, password);
        if (password == c_candidate.password){
            flag = false;
            current_candidate = new Candidate(c_candidate.candidate_name, c_candidate.candidate_id,
                                              c_candidate.candidate_email, c_candidate.password, c_candidate.candidate_phone_number,
                                              0, "null", c_candidate.resumePath, c_candidate.candidate_free_text,
                                              c_candidate.candidate_age, c_candidate.candidate_gender, c_candidate.candidate_experience,
                                              c_candidate.candidate_specialty);
        } else{
            int choice = 0;
            while (choice != 1){
                cout << "Incorrect password, would you like to continue the login process?\n"
                        "1) Yes, I must have been wrong.\n"
                        "2) No, exit the login page.\n";
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 2) {
                    // Invalid input (not a char)
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. try again\n";
                }
                if (choice == 2){
                    return true;
                }
            }
        }
    }
    sqlite3 * db2 = openSQLiteFile(fff);
    int size4 = countRowsByApplyingID(db2,newId);
//    num_of_all_submissions = countRowsInApplyTable(db2);
    Apply ** submissions = new Apply * [size4];
    vector <ApplyInfo> apply_list = getSubmissionsForApplicant(db2, newId);
    for (int i = 0; i < size4; ++i) {
        Date t_date (apply_list[i].submissionDay, apply_list[i].submissionMonth, apply_list[i].submissionYear);
        submissions[i] = new Apply(apply_list[i].applyID, apply_list[i].candidateID, apply_list[i].jobID, t_date, apply_list[i].submissionStatus, apply_list[i].jobName, apply_list[i].companyName);
    }
    current_candidate->setAppliedJobs(submissions, size4);
    for (int i = 0; i < size4; ++i) {
        delete submissions[i];
    }
    delete[] submissions;
    num_of_jobs = countRowsInJobTable(db2);
    vector<JobInfo> job_list = getAllJobs(db2);
    jobs_list = new Job * [num_of_jobs];
    int num_of_applys = 0;
    for (int i = 0; i < num_of_jobs; ++i) {
        Date t_date(job_list[i].posting_day, job_list[i].posting_month, job_list[i].posting_year);
        jobs_list[i] = new Job(job_list[i].posting_status, job_list[i].jobID, job_list[i].profession, job_list[i].company_name, job_list[i].location, job_list[i].contact, job_list[i].name, job_list[i].job_type, t_date);
        num_of_applys = countRowsByJobID(db2,job_list[i].jobID);
        jobs_list[i]->set_applies(num_of_applys);
    }
    closeSQLiteFile(db2);
//    candidate_main_menu();////////////////////////////////////////////////////////////////////
//    CandidateInfo cc;
//    cc.candidate_id = current_candidate->getId();
//    cc.candidate_name = current_candidate->getName();
//    cc.candidate_age = current_candidate->getAge();
//    cc.candidate_gender = current_candidate->getGender();
//    cc.candidate_phone_number = current_candidate->getPhoneNumber();
//    cc.candidate_email = current_candidate->getEmail();
//    cc.candidate_living_area = current_candidate->getResidence();
//    cc.candidate_experience = current_candidate->getWorkExperience();
//    cc.candidate_specialty = current_candidate->getSpecialty();
//    cc.password = current_candidate->getPassword();
//    cc.candidate_free_text = current_candidate->getPersonalInformation();
//    cc.resumePath = current_candidate->getResumePath();
//    for (int i = 0; i < num_of_jobs; ++i) {
//        JobInfo jj;
//        jj.jobID = jobs_list[i]->get_job_id();
//        jj.location = jobs_list[i]->get_location();
//        jj.profession = jobs_list[i]->get_occupation();
//        jj.job_type = jobs_list[i]->get_scope();
//        jj.experience = jobs_list[i]->get_experience();
//        jj.name = jobs_list[i]->get_job_name();
//        jj.company_name = jobs_list[i]->get_company_name();
//        jj.contact = jobs_list[i]->get_phone_number();
//        jj.posting_status = jobs_list[i]->get_status();
//        jj.posting_day = jobs_list[i]->get_posting_date().getDay();
//        jj.posting_month = jobs_list[i]->get_posting_date().getMonth();
//        jj.posting_year = jobs_list[i]->get_posting_date().getYear();
//        updateJobData(db2, jj);
//    }
//    for (int i = 0; i < current_candidate->getAppliedJobSize(); ++i) {
//        ApplyInfo aa;
//        aa.candidateID = current_candidate->getAppliedJob()[i]->getCandidateID();
//        aa.jobID = current_candidate->getAppliedJob()[i]->getJobID();
//        aa.submissionDay = current_candidate->getAppliedJob()[i]->getSubmissionDate().getDay();
//        aa.submissionMonth = current_candidate->getAppliedJob()[i]->getSubmissionDate().getMonth();
//        aa.submissionYear = current_candidate->getAppliedJob()[i]->getSubmissionDate().getYear();
//        aa.applyID = current_candidate->getAppliedJob()[i]->getNumberOfSubmission();
//        aa.submissionStatus = current_candidate->getAppliedJob()[i]->getSubmissionStatus();
//        aa.jobName = current_candidate->getAppliedJob()[i]->getJobName();
//        aa.companyName = current_candidate->getAppliedJob()[i]->getCompanyName();
//        updateApplyData(db2, aa);
//    }
//    sqlite3 * db5 = openSQLiteFile(fff);
//    updateCandidateData(db5,cc);
    return true;
}


void Job_search_system::candidate_main_menu() {
    bool flag = true;
    while (flag){
        cout << "Please enter the action you want to perform:\n"
                "1) Look for a job.\n"
                "2) Get tips for writing a resume.\n"
                "3) View my submission history.\n"
                "4) Edit my profile.\n"
                "5) Salary calculator.\n"
                "6) Submit feedback on the system.\n"
                "7) Disconnect.\n";
        int choice = 0;
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 7) {
            // Invalid input (not a char)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. try again\n";
        }
        if (choice == 7){
            return ;
        }
        switch (choice) {
            case 1: {
                vector<JobId> ids_list = current_candidate->lookForJobs(jobs_list, num_of_jobs);
                cout << "Please enter the job ID number for which you would like to apply and send your resume to:\n";
                int job_to_apply = 0;
                cin >> job_to_apply;
                if (cin.fail()) {
                    // Invalid input (not a char)
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. try again\n";
                } else{
                    bool flag5 = true;
                    for (const auto &job : ids_list) {
                        if (job.job_id == job_to_apply){
                            for (int i = 0; i < num_of_jobs; ++i) {
                                if (jobs_list[i]->get_job_id() == job_to_apply){
                                    Apply toAdd;
                                    toAdd.setCandidateID(current_candidate->getId());
                                    toAdd.setCompanyName(jobs_list[i]->get_company_name());
                                    toAdd.setNumberOfSubmission(num_of_all_submissions+1);
                                    toAdd.setJobID(job_to_apply);
                                    toAdd.setJobName(jobs_list[i]->get_job_name());
                                    current_candidate->addApply(&toAdd);
                                    int size7 = jobs_list[i]->get_applies_size();
                                    jobs_list[i]->set_applies(size7+1);
                                    i = num_of_jobs;
                                    flag5 = false;
                                }
                            }
                        }
                    }
                    if (!flag5)
                        break;
                    cout << "The number was entered does not exist in the list, you can try again through the main menu\n";
                }
                break;
            }
            case 2: {
                current_candidate->printTipsForResume();
                break;
            }
            case 3: {
                current_candidate->viewSubmissions();
                cout << "Enter the submission number you wish to cancel:\n";
                int apply_to_delete = 0;
                cin >> apply_to_delete;
                if (cin.fail()) {
                    // Invalid input (not a char)
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. try again\n"
                            "You can try again through the main menu\n";
                    break;
                }
                for (int i = 0; i < current_candidate->getAppliedJobSize(); ++i) {
                    if (apply_to_delete == current_candidate->getAppliedJob()[i]->getNumberOfSubmission()){
                        Apply toDelete;
                        toDelete.setCandidateID(current_candidate->getId());
                        toDelete.setCompanyName(jobs_list[i]->get_company_name());
                        toDelete.setNumberOfSubmission(apply_to_delete);
                        toDelete.setJobID(current_candidate->getAppliedJob()[i]->getJobID());
                        toDelete.setJobName(jobs_list[i]->get_job_name());
                        toDelete.setSubmissionDate(current_candidate->getAppliedJob()[i]->getSubmissionDate());
                        current_candidate->cancelApply(&toDelete);
                        for (int j = 0; j < num_of_jobs; ++j) {
                            if (jobs_list[j]->get_job_id() == current_candidate->getAppliedJob()[i]->getJobID())
                            {
                                int size7 = jobs_list[i]->get_applies_size();
                                jobs_list[i]->set_applies(size7-1);
                            }
                        }
                        break;
                    }
                }
                cout << "The number was entered does not exist in the list, you can try again through the main menu\n";
                break;
            }
            case 4: {
                current_candidate->editProfile();
                break;
            }
            case 5: {
                current_candidate->editFeedback();
                while (true){
                    int r = 0;
                    cout<<"Enter a number 1-5 that represents your rating:\n";
                    cin >> r;
                    if (cin.fail()|| r>5 || r<1) {
                        // Invalid input (not a char)
                        cin.clear(); // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "Invalid input. try again\n";
                    } else{
                        current_candidate->setRating(r);
                        break;
                    }
                }
                break;
            }
            case 6: {
                cout << "Logout operation\n";
                break;
            }
        }

    }
}

bool Job_search_system::employer_login() {
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);
    vector<EmployerId> e_id_list = getEmployerId(db);
    int size = countRowsInCandidatesTable(db);
    closeSQLiteFile(db);
    bool flag = true;
    long newId = 0;
    while (flag) {
        cout << "Enter your id (no longer than 9 numbers): " << endl;
        cin >> newId;
        if (cin.fail() || to_string(newId).length() > 9) {
            // Invalid input (not an integer or longer than 9)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            cout << "Invalid input. try again\n" ;

        } else {
            for (int i = 0; i < size; ++i) {
                if (newId == e_id_list[i].employer_id) {
                    i = size;
                    flag = false;
                }
            }
        }
        if (flag){
            int choice = 0;
            while (choice != 1){
                cout << "The ID number you registered does not appear in the system, would you like to continue the registration process?\n"
                        "1) Yes, I must have got my ID number wrong.\n"
                        "2) No, I want to register.\n";
                cin >> choice;
                if (cin.fail() || choice < 1 || choice > 2) {
                    // Invalid input (not a char)
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. try again\n";
                }
                if (choice == 2){
                    return true;
                }
            }
        }
    }

}


void Job_search_system::updateForCandidate_login() {
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db5 = openSQLiteFile(fff);
    CandidateInfo cc;
    cc.candidate_id = current_candidate->getId();
    cc.candidate_name = current_candidate->getName();
    cc.candidate_age = current_candidate->getAge();
    cc.candidate_gender = current_candidate->getGender();
    cc.candidate_phone_number = current_candidate->getPhoneNumber();
    cc.candidate_email = current_candidate->getEmail();
    cc.candidate_living_area = current_candidate->getResidence();
    cc.candidate_experience = current_candidate->getWorkExperience();
    cc.candidate_specialty = current_candidate->getSpecialty();
    cc.password = current_candidate->getPassword();
    cc.candidate_free_text = current_candidate->getPersonalInformation();
    cc.resumePath = current_candidate->getResumePath();
//    for (int i = 0; i < num_of_jobs; ++i) {
//        JobInfo jj;
//        jj.jobID = jobs_list[i]->get_job_id();
//        jj.location = jobs_list[i]->get_location();
//        jj.profession = jobs_list[i]->get_occupation();
//        jj.job_type = jobs_list[i]->get_scope();
//        jj.experience = jobs_list[i]->get_experience();
//        jj.name = jobs_list[i]->get_job_name();
//        jj.company_name = jobs_list[i]->get_company_name();
//        jj.contact = jobs_list[i]->get_phone_number();
//        jj.posting_status = jobs_list[i]->get_status();
//        jj.posting_day = jobs_list[i]->get_posting_date().getDay();
//        jj.posting_month = jobs_list[i]->get_posting_date().getMonth();
//        jj.posting_year = jobs_list[i]->get_posting_date().getYear();
//        updateJobData(db5, jj);
//    }
    for (int i = 0; i < current_candidate->getAppliedJobSize(); ++i) {
        ApplyInfo aa;
        aa.candidateID = current_candidate->getAppliedJob()[i]->getCandidateID();
        aa.jobID = current_candidate->getAppliedJob()[i]->getJobID();
        aa.submissionDay = current_candidate->getAppliedJob()[i]->getSubmissionDate().getDay();
        aa.submissionMonth = current_candidate->getAppliedJob()[i]->getSubmissionDate().getMonth();
        aa.submissionYear = current_candidate->getAppliedJob()[i]->getSubmissionDate().getYear();
        aa.applyID = current_candidate->getAppliedJob()[i]->getNumberOfSubmission();
        aa.submissionStatus = current_candidate->getAppliedJob()[i]->getSubmissionStatus();
        aa.jobName = current_candidate->getAppliedJob()[i]->getJobName();
        aa.companyName = current_candidate->getAppliedJob()[i]->getCompanyName();
        updateApplyData(db5, aa);
    }
    updateCandidateData(db5,cc);
    closeSQLiteFile(db5);
}

//Please enter the path of your resume file
//sqlite3 * db = openSQLiteFile(DATA_BASE_PATH);
//num_of_employers = countRowsInEmployersTable(db);
//num_of_candidates = countRowsInCandidatesTable(db);
//num_of_jobs = countRowsInJobTable(db);
//num_of_submissions = countRowsInApplyTable(db);
//
//employers_list = new Employer * [num_of_employers];
//candidates_list = new Candidate * [num_of_candidates];
//jobs_list = new Job * [num_of_jobs];
//submissions_list = new Apply * [num_of_submissions];
//
//vector<EmployerInfo> employers = getEmployerInfo(db);
//for (int i = START_INDEX; i < num_of_employers; ++i) {
//employers_list[i] = new Employer(employers[i].employer_id, employers[i].employer_name,
//employers[i].company_name, employers[i].employer_email,
//employers[i].employer_phone_number, employers[i].password);
//
//
//}