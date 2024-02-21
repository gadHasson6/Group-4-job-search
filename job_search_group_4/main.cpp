#include "Includes.h"



int main()
{
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);

    return 0;
}

//
//#include <iostream>
//#include "sqlite3.h"
//
//int main() {
//    sqlite3 *db;
//    int rc = sqlite3_open("C:/Users/LENOVO/לא לגיבוי- תכנות/sqlite-tools-win-x64-3450100/search_job.db", &db);
//    if (rc != SQLITE_OK) {
//        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
//        sqlite3_close(db);
//        return 1;
//    }
//
//    const char *sql = "SELECT Id FROM job"; // Replace with your query
//    sqlite3_stmt *stmt;
//    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
//    if (rc != SQLITE_OK) {
//        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
//        sqlite3_close(db);
//        return 1;
//    }
//
//    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//        // Assuming the column is of type TEXT
//        const unsigned char *columnValue = sqlite3_column_text(stmt, 0); // Assuming the column index is 0
//        if (columnValue) {
//            std::cout << columnValue << std::endl;
//        }
//    }
//
//    if (rc != SQLITE_DONE) {
//        std::cerr << "Error fetching results: " << sqlite3_errmsg(db) << std::endl;
//    }
//    sqlite3_finalize(stmt);
//    sqlite3_close(db);
//    return 0;
//}

