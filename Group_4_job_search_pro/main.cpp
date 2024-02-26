#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
using namespace std;

#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"


int main() {
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);
    cout <<"employers: " << countRowsInEmployersTable(db) << '\n';
    cout <<"candidates: " << countRowsInCandidatesTable(db) << '\n';
    cout <<"employer 12 have : " << countRowsByCreatorID(db, 12) << " jobs\n";
    cout <<"employer 14 have : " << countRowsByCreatorID(db, 14) << " jobs\n";
    closeSQLiteFile(db);
    return 0;
}
