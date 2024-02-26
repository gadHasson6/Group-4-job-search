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


////////////////////////////
int countRowsInEmployersTable(sqlite3* db){
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the employers table
    const char* sql = "SELECT COUNT(*) FROM employer";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return -1; // Return -1 to indicate error
    }

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        // Retrieve the count of rows from the result
        rowCount = sqlite3_column_int(stmt, 0);
    } else {
        cerr << "No rows returned" << endl;
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return rowCount;
}


////////////////////////////
int countRowsInCandidatesTable(sqlite3* db) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the candidates table
    const char* sql = "SELECT COUNT(*) FROM candidate";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return -1; // Return -1 to indicate error
    }

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        // Retrieve the count of rows from the result
        rowCount = sqlite3_column_int(stmt, 0);
    } else {
        cerr << "No rows returned" << endl;
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return rowCount;
}


////////////////////////////
int countRowsByCreatorID(sqlite3* db, int idToSearch) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the job table where creator_id matches the given ID
    const char* sql = "SELECT COUNT(*) FROM job WHERE creatorID = ?";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return -1; // Return -1 to indicate error
    }

    // Bind the integer parameter to the prepared statement
    sqlite3_bind_int(stmt, 1, idToSearch);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        // Retrieve the count of rows from the result
        rowCount = sqlite3_column_int(stmt, 0);
    } else {
        cerr << "No rows returned" << endl;
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return rowCount;
}


////////////////////////////
int countRowsByApplyingID(sqlite3* db, int idToSearch) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the apply table where applyingID matches the given ID
    const char* sql = "SELECT COUNT(*) FROM apply WHERE applyingID = ?";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return -1; // Return -1 to indicate error
    }

    // Bind the integer parameter to the prepared statement
    sqlite3_bind_int(stmt, 1, idToSearch);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        // Retrieve the count of rows from the result
        rowCount = sqlite3_column_int(stmt, 0);
    } else {
        cerr << "No rows returned" << endl;
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return rowCount;
}


////////////////////////////
int countRowsByJobID(sqlite3* db, int idToSearch) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the apply table where jobID matches the given ID
    const char* sql = "SELECT COUNT(*) FROM apply WHERE jobID = ?";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return -1; // Return -1 to indicate error
    }

    // Bind the integer parameter to the prepared statement
    sqlite3_bind_int(stmt, 1, idToSearch);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        // Retrieve the count of rows from the result
        rowCount = sqlite3_column_int(stmt, 0);
    } else {
        cerr << "No rows returned" << endl;
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return rowCount;
}