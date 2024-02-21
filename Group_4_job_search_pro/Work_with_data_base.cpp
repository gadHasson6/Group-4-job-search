//
// Created by LENOVO on 22/02/2024.
//

#include "Work_with_data_base.h"


////////////////////////////
sqlite3 *openSQLiteFile(const char *filename){
    sqlite3 *db;
    int rc = sqlite3_open(filename, &db);

    if (rc != SQLITE_OK) {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return nullptr; // Return nullptr to indicate failure
    }

    cout << "Opened database successfully" << endl;
    return db;
}


////////////////////////////
void closeSQLiteFile(sqlite3 *db) {
    if (db != nullptr) {
        int rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            cerr << "Error closing database: " << sqlite3_errmsg(db) << endl;
        } else {
            cout << "Database closed successfully" << endl;
        }
    } else {
        cerr << "Invalid database pointer" << endl;
    }
}
