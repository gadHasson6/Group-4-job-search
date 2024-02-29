//
// Created by LENOVO on 28/02/2024.
//

#include "Job_search_system.h"

Job_search_system::Job_search_system() {
    sqlite3 * db = openSQLiteFile(DATA_BASE_PATH);
    num_of_employers = countRowsInEmployersTable(db);
    num_of_candidates = countRowsInCandidatesTable(db);
    num_of_jobs = countRowsInJobTable(db);
    num_of_submissions = countRowsInApplyTable(db);

    employers_list = new Employer * [num_of_employers];
    candidates_list = new Candidate * [num_of_candidates];
    jobs_list = new Job * [num_of_jobs];
    submissions_list = new Apply * [num_of_submissions];

    vector<EmployerInfo> employers = getEmployerInfo(db);
    for (int i = START_INDEX; i < num_of_employers; ++i) {
        employers_list[i] = new Employer(employers[i].employer_id, employers[i].employer_name,
                                         employers[i].company_name, employers[i].employer_email,
                                         employers[i].employer_phone_number, employers[i].password);

    }
}