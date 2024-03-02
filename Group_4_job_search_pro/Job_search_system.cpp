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
        flag = current_candidate->setName(newName);

        if (flag) {
            cout << "Name updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    flag = true;
    long newId = 0;
    while (flag) {
        cout << "Enter new id (no longer than 9 numbers): " << endl;
        cin >> newId;
        if (cin.fail() || to_string(newId).length() > 9) {
            // Invalid input (not an integer or longer than 9)
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            int choice = 0;
            cout << "Invalid input. Please choose:" << endl;
            cout << "1. Choose a new ID" << endl;
            cout << "2. Stay with the existing ID" << endl;
            cin >> choice;

            if (choice == 2) {
                break;
            } else {
                // Clear the input buffer before taking a new choice
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            setId(newId);
            cout << "ID updated successfully!" << endl;
            break; // Exit the loop if a valid ID is provided
        }
        flag = current_candidate->setName(newName);

        if (flag) {
            cout << "Name updated successfully!" << endl;
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            // Clear the input buffer before taking a new choice
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
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