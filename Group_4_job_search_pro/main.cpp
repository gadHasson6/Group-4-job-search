#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
using namespace std;

#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"


int main() {
    const char  * fff = DATA_BASE_PATH;
    sqlite3 * db = openSQLiteFile(fff);
    closeSQLiteFile(db);
    return 0;
}
