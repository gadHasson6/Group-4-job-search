#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
using namespace std;

#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"


int main() {
    int x =0, y= 2, z=3;
    int * aa[3];
    aa[0] = &x;
    aa[1] = &y;
    aa[2] = &z;
    x=5;
    *aa[1] = 9;
    cout << "x=" << *aa[0] << "y = " << *aa[1] << "\n";
    cout << "x=" << x << "y = " << y << "\n";
//    const char  * fff = DATA_BASE_PATH;
//    sqlite3 * db = openSQLiteFile(fff);
//    cout <<"employers: " << countRowsInEmployersTable(db) << '\n';
//    cout <<"candidates: " << countRowsInCandidatesTable(db) << '\n';
//    cout <<"employer 12 have : " << countRowsByCreatorID(db, 12) << " jobs\n";
//    cout <<"employer 14 have : " << countRowsByCreatorID(db, 14) << " jobs\n";
//    closeSQLiteFile(db);
    return 0;
}
