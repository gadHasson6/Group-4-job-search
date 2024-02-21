//
// Created by LENOVO on 22/02/2024.
//

#ifndef GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H
#define GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#endif //GROUP_4_JOB_SEARCH_PRO_WORK_WITH_DATA_BASE_H

#include "sqlite3.h"
#include <iostream>
using namespace std;


////////////////////////////
sqlite3 *openSQLiteFile(const char *filename);

////////////////////////////
void closeSQLiteFile(sqlite3 *db);