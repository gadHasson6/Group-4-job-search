//
// Created by LENOVO on 15/02/2024.
//

#ifndef JOB_SEARCH_GROUP_4_JOB_SEARCH_H
#define JOB_SEARCH_GROUP_4_JOB_SEARCH_H

#include "Includes.h"

struct id_num {
    int id;
};

class Job_search {
private:
    User * current_user;
    User ** candidates;
    User ** employers;
    Job ** jobs;
    int max_job_id;
    int max_apply_id;
    string databasePath = "C:/Users/LENOVO/לא לגיבוי- תכנות/sqlite-tools-win-x64-3450100/search_job.db";
    static int js_callback(void* data, int argc, char** argv, char** azColName);

public:
    Job_search() : current_user(nullptr), candidates(nullptr), employers(nullptr), jobs(nullptr), max_apply_id(DEFAULT_VAL){};
    ~Job_search();
    void js_menu();
    void jb_im_candidate();
    void jb_im_employer();
    vector<id_num> js_read_id_from_db();
};


#endif //JOB_SEARCH_GROUP_4_JOB_SEARCH_H
