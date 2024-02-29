#include <iostream>
#include "sqlite3.h"
#include "Work_with_data_base.h"
//using namespace std;


#define DATA_BASE_PATH "C:/Users/LENOVO/CLionProjects/search_job.db"
int main() {
    int x =0, y= 2, z=3;
    int * h = &y;
    int * k[3];
    k[1] = h;
    k[0] = h;
    k[2] = new int(5);
//    int ** k = &h;
    cout << *h << '\n';
    cout << *k[1] << '\n';
    *h += 7;
    cout << *h << '\n';
    cout << *k[1] << '\n';
    for (const auto& employer : k) {
        cout << *employer <<'\n';
    }
//    const char  * fff = DATA_BASE_PATH;
//    sqlite3 * db = openSQLiteFile(fff);
//    cout <<"employers: " << countRowsInEmployersTable(db) << '\n';
//    cout <<"candidates: " << countRowsInCandidatesTable(db) << '\n';
//    cout <<"employer 12 have : " << countRowsByCreatorID(db, 12) << " jobs\n";
//    cout <<"employer 14 have : " << countRowsByCreatorID(db, 14) << " jobs\n";
//    closeSQLiteFile(db);
    return 0;
}



//int main() {
//    const char  * fff = DATA_BASE_PATH;
//    sqlite3 * db = openSQLiteFile(fff);
//
//    // Call the function to retrieve employer information
//    vector<EmployerInfo> employers = getEmployerInfo(db);
//
//    // Print employer information
//    for (int i = 0; i < 2; ++i) {
//        cout << "Employer ID: " << employers[i].employer_id << endl;
//        cout << "Employer Name: " << employers[i].employer_name << endl;
//        cout << "Company Name: " << employers[i].company_name << endl;
//        cout << "Employer Email: " << employers[i].employer_email << endl;
//        cout << "Employer Phone Number: " << employers[i].employer_phone_number << endl;
//        cout << "Password: " << employers[i].password << endl << endl;
//    }
//
//    // Close the database connection
//    closeSQLiteFile(db);
//
//    return 0;
//}
