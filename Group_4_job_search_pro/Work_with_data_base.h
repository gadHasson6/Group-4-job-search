//
// Created by LENOVO on 22/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H
#define GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#endif //GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#include "sqlite3.h"
#include <iostream>
using namespace std;


////////////////////////////opening a file
sqlite3 *openSQLiteFile(const char *filename);

////////////////////////////closing a file
void closeSQLiteFile(sqlite3 *db);

////////////////////////////Count the number of employers
int countRowsInEmployersTable(sqlite3* db);

////////////////////////////Count the number of candidates
int countRowsInCandidatesTable(sqlite3* db);

////////////////////////////Counts employer jobs by ID
int countRowsByCreatorID(sqlite3* db, int idToSearch);

////////////////////////////Count submissions of a candidate by ID
int countRowsByApplyingID(sqlite3* db, int idToSearch);

////////////////////////////Counts job application submissions by ID
int countRowsByJobID(sqlite3* db, int idToSearch);

////////////////////////////
