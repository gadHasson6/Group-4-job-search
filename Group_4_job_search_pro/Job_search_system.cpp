//
// Created by LENOVO on 28/02/2024.
//

#include "Job_search_system.h"

Job_search_system::Job_search_system() {
    num_of_jobs = 0;
    num_of_submissions = 0;
    num_of_candidates = 0;
    num_of_employers = 0;
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
                flag = employer_registration();
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