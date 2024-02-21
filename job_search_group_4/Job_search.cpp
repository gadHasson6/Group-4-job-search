//
// Created by LENOVO on 15/02/2024.
//

#include "Includes.h"


////////////////////////////
void Job_search::js_menu() {
    enum user_type {im_candidate = RESET_VAL_IN_OPTION_ENUM, im_employer, exit_menu};
    int user_type = DEFAULT_VAL;
    while (user_type != EXIT_OPTION)
    {
        cout << "Please choose one of the following options:\n" // Display options to user
                "==================================================================\n"
                "1 ) I am a candidate .\n"
                "2 ) I am an employer .\n"
                "3 ) Exit .\n"
                " ==================================================================" << endl;
        cin >> user_type;
        switch (user_type) {
            case im_candidate: {
                jb_im_candidate();
                break;
            }
            case im_employer: {
                jb_im_employer();
                break;

            }
            case exit_menu: {
                cout << "Thank you and goodbye!!\n";
                user_type = EXIT_OPTION;
                break;
            }
            default: {
                cout << "wrong input, try again!" << endl;
                break;
            }
        }
    }
}

////////////////////////////
void Job_search::jb_im_candidate() {
    enum option {register_ = RESET_VAL_IN_OPTION_ENUM, log_in, exit_menu};
    int option = DEFAULT_VAL;
    while (option != EXIT_OPTION)
    {
        cout << "Please choose one of the following options:\n" // Display options to user
                "==================================================================\n"
                "1 ) Register as a new candidate .\n"
                "2 ) Log in to an existing user .\n"
                "3 ) Exit .\n"
                " ==================================================================" << endl;
        cin >> option;
        switch (option) {
            case register_: {

                break;
            }
            case log_in: {

                break;

            }
            case exit_menu: {
                cout << "Thank you and goodbye!!\n";
                option = EXIT_OPTION;
                break;
            }
            default: {
                cout << "wrong input, try again!" << endl;
                break;
            }
        }
    }
}

////////////////////////////
vector<id_num> Job_search::js_read_id_from_db() {
    vector<id_num> id_numbers;

    sqlite3* db;
    char * zErrMsg = 0;
    int rc;


    rc = sqlite3_open(databasePath.c_str(), &db);

    if (rc) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return id_numbers;
    }else {
        cout << "Opened database successfully" << endl;
    }

    const char* sql = "SELECT candidateID FROM candidate";
    rc = sqlite3_exec(db, sql, js_callback, &id_numbers, &zErrMsg);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Operation done successfully" << endl;
    }

    sqlite3_close(db);

    return id_numbers;
}

////////////////////////////
int Job_search::js_callback(void *data, int argc, char **argv, char **azColName) {
    vector<id_num>* numbers = reinterpret_cast<vector<id_num>*>(data);
    id_num number;
    number.id = stoi(argv[0]); // Assuming ID is the first column

    numbers->push_back(number);
    return 0;
}