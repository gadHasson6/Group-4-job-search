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
int countRowsInApplyTable(sqlite3* db) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the candidates table
    const char* sql = "SELECT COUNT(*) FROM apply";

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
int countRowsInJobTable(sqlite3* db) {
    int rowCount = 0;
    sqlite3_stmt* stmt;

    // SQL query to count rows in the candidates table
    const char* sql = "SELECT COUNT(*) FROM job";

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
int countRowsByApplyingID(sqlite3* db, long idToSearch) {
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


////////////////////////////
vector<EmployerInfo> getEmployerInfo(sqlite3* db) {
    vector<EmployerInfo> employers;
    sqlite3_stmt* stmt;

    // SQL query to select all fields from the employer table
    const char* sql = "SELECT [employer_ID], [employr name], [company name], [employer email], [employer phone number], password FROM employer";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return employers; // Return empty vector to indicate error
    }

    // Execute the SQL statement
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve employer information from the result and add it to the vector
        EmployerInfo employer;
        employer.employer_id = sqlite3_column_int64(stmt, 0);
        employer.employer_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
//        employer.company_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        employer.employer_email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        employer.employer_phone_number = sqlite3_column_int64(stmt, 4);
        employer.password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        employers.push_back(employer);
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return employers;
}


////////////////////////////
//vector<CandidateInfo> getCandidateInfo(sqlite3* db) {
//    vector<CandidateInfo> candidates;
//    sqlite3_stmt* stmt;
//
//    // SQL query to select all fields from the employer table
//    const char* sql = "SELECT [employer_ID], [employr name], [company name], [employer email], [employer phone number], password FROM employer";
//
//    // Prepare the SQL statement
//    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
//
//    if (rc != SQLITE_OK) {
//        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
//        return employers; // Return empty vector to indicate error
//    }
//
//    // Execute the SQL statement
//    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
//        // Retrieve employer information from the result and add it to the vector
//        EmployerInfo employer;
//        employer.employer_id = sqlite3_column_int64(stmt, 0);
//        employer.employer_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
//        employer.company_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
//        employer.employer_email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
//        employer.employer_phone_number = sqlite3_column_int64(stmt, 4);
//        employer.password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
//        employers.push_back(employer);
//    }
//
//    // Finalize the prepared statement
//    sqlite3_finalize(stmt);
//
//    return employers;
//}


////////////////////////////
vector<CandidateId> getCandidateId(sqlite3* db) {
    vector<CandidateId> candidate_ids;
    sqlite3_stmt* stmt;

    // SQL query to select candidateID field from the candidate table
    const char* sql = "SELECT [candidateID] FROM candidate";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return candidate_ids; // Return empty vector to indicate error
    }

    // Execute the SQL statement
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve employer information from the result and add it to the vector
        CandidateId c_id;
        c_id.candidate_id = sqlite3_column_int64(stmt, 0);
        candidate_ids.push_back(c_id);
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return candidate_ids;
}


////////////////////////////
vector<EmployerId> getEmployerId(sqlite3* db) {
    vector<EmployerId> employer_ids;
    sqlite3_stmt* stmt;

    // SQL query to select ID field from the employer table
    const char* sql = "SELECT [ID] FROM employer";

    // Prepare the SQL statement
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << sqlite3_errmsg(db) << endl;
        return employer_ids; // Return empty vector to indicate error
    }

    // Execute the SQL statement
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        // Retrieve employer information from the result and add it to the vector
        EmployerId e_id;
        e_id.employer_id = sqlite3_column_int64(stmt, 0);
        employer_ids.push_back(e_id);
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);

    return employer_ids;
}


////////////////////////////
CandidateInfo getCandidateByID(sqlite3* db, long candidateID) {
    CandidateInfo candidate;

    // SQL query to retrieve data for a specific candidate ID
    string sql = "SELECT * FROM candidate WHERE candidateID = " + to_string(candidateID);

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle error (e.g., return empty CandidateInfo struct)
        return candidate;
    }

    // Retrieve data for the candidate
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        candidate.candidate_id = sqlite3_column_int64(stmt, 0);
        candidate.candidate_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        candidate.candidate_age = sqlite3_column_int(stmt, 2);
        candidate.candidate_gender = *reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        candidate.candidate_phone_number = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        candidate.candidate_email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        candidate.candidate_living_area = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        candidate.candidate_experience = static_cast<float>(sqlite3_column_double(stmt, 7));
        candidate.candidate_specialty = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        candidate.password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9));
        candidate.candidate_free_text = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 10));
        candidate.resumePath = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 11));
    }

    sqlite3_finalize(stmt);

    return candidate;
}


////////////////////////////
vector<ApplyInfo> getAllApplies(sqlite3* db) {
    vector<ApplyInfo> applies;

    // SQL query to retrieve data for all apply objects
    string sql = "SELECT * FROM apply";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle error (e.g., return empty vector)
        return applies;
    }

    // Retrieve data for all apply objects
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        ApplyInfo apply;
        apply.candidateID = sqlite3_column_int64(stmt, 1);
        apply.jobID = sqlite3_column_int(stmt, 2);
        apply.submissionDay = sqlite3_column_int(stmt, 5);
        apply.submissionMonth = sqlite3_column_int(stmt, 6);
        apply.submissionYear = sqlite3_column_int(stmt, 7);
        apply.applyID = sqlite3_column_int(stmt, 0);
        apply.submissionStatus = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        apply.jobName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        apply.companyName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        applies.push_back(apply);
    }

    sqlite3_finalize(stmt);

    return applies;
}


////////////////////////////
vector<JobInfo> getAllJobs(sqlite3* db) {
    vector<JobInfo> jobs;

    // SQL query to retrieve data for all job objects
    string sql = "SELECT * FROM job";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle error (e.g., return empty vector)
        return jobs;
    }

    // Retrieve data for all job objects
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        JobInfo job;
        job.jobID = sqlite3_column_int(stmt, 0);
        job.employerID = sqlite3_column_int64(stmt, 1);
        job.location = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        job.profession = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        job.job_type = sqlite3_column_int(stmt, 4);
        job.experience = sqlite3_column_int(stmt, 5);
        job.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        job.company_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        job.contact = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        job.posting_status = sqlite3_column_int(stmt, 9) != 0;
        job.posting_day = sqlite3_column_int(stmt, 11);
        job.posting_month = sqlite3_column_int(stmt, 12);
        job.posting_year = sqlite3_column_int(stmt, 13);

        jobs.push_back(job);
    }

    sqlite3_finalize(stmt);

    return jobs;
}


////////////////////////////
vector<ApplyInfo> getSubmissionsForApplicant(sqlite3* db, long applicantID) {
    vector<ApplyInfo> submissions;

    // SQL query to retrieve data for submissions of a specific applicant
    string sql = "SELECT * FROM apply WHERE applyingID = ?";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle error (e.g., return empty vector)
        return submissions;
    }

    // Bind the applicantID parameter to the SQL statement
    sqlite3_bind_int64(stmt, 1, applicantID);

    // Retrieve data for submissions of the specified applicant
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        ApplyInfo submission;
        submission.candidateID = sqlite3_column_int64(stmt, 1);
        submission.jobID = sqlite3_column_int(stmt, 2);
        submission.submissionDay = sqlite3_column_int(stmt, 5);
        submission.submissionMonth = sqlite3_column_int(stmt, 6);
        submission.submissionYear = sqlite3_column_int(stmt, 7);
        submission.applyID = sqlite3_column_int(stmt, 0);
        submission.submissionStatus = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        submission.jobName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        submission.companyName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

        submissions.push_back(submission);
    }

    sqlite3_finalize(stmt);

    return submissions;
}



////////////////////////////
vector<JobInfo> getJobsByID(sqlite3* db, long jobID) {
    vector<JobInfo> jobs;

    // SQL query to retrieve data for jobs with a specific ID
    string sql = "SELECT * FROM job WHERE ID = ?";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        // Handle error (e.g., return empty vector)
        return jobs;
    }

    // Bind the jobID parameter to the SQL statement
    sqlite3_bind_int64(stmt, 1, jobID);

    // Retrieve data for jobs with the specified ID
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        JobInfo job;
        job.jobID = sqlite3_column_int(stmt, 0);
        job.employerID = sqlite3_column_int64(stmt, 1);
        job.location = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        job.profession = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        job.job_type = sqlite3_column_int(stmt, 4);
        job.experience = sqlite3_column_int(stmt, 5);
        job.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        job.company_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        job.contact = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        job.posting_status = sqlite3_column_int(stmt, 9) != 0;
        job.posting_day = sqlite3_column_int(stmt, 11);
        job.posting_month = sqlite3_column_int(stmt, 12);
        job.posting_year = sqlite3_column_int(stmt, 13);

        jobs.push_back(job);
    }

    sqlite3_finalize(stmt);

    return jobs;
}


////////////////////////////
void updateCandidateData(sqlite3* db, const CandidateInfo& candidate) {
    // Prepare the SQL statement
    string sql = "UPDATE candidate SET "
                 "candidateName = ?, "
                 "candidateAge = ?, "
                 "candidateGender = ?, "
                 "candidatePhoneNumber = ?, "
                 "candidateMail = ?, "
                 "candidateLivingArea = ?, "
                 "cadidateExperience = ?, "
                 "candidateSpecialty = ?, "
                 "candidatePassword = ?, "
                 "candidateFreeText = ?, "
                 "resumePath = ? "
                 "WHERE candidateID = ?";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle error
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stmt, 1, candidate.candidate_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, candidate.candidate_age);
    sqlite3_bind_text(stmt, 3, &candidate.candidate_gender, 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, candidate.candidate_phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, candidate.candidate_email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, candidate.candidate_living_area.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 7, candidate.candidate_experience);
    sqlite3_bind_text(stmt, 8, candidate.candidate_specialty.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, candidate.password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, candidate.candidate_free_text.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, candidate.resumePath.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int64(stmt, 12, candidate.candidate_id);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // Handle error
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}


////////////////////////////
void updateJobData(sqlite3* db, const JobInfo& job) {
    // Prepare the SQL statement
    string sql = "UPDATE job SET "
                 "location = ?, "
                 "profession = ?, "
                 "job_type = ?, "
                 "experience = ?, "
                 "name = ?, "
                 "company_name = ?, "
                 "contact = ?, "
                 "posting_status = ?, "
                 "posting_day = ?, "
                 "posting_month = ?, "
                 "posting_year = ? "
                 "WHERE ID = ?";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle error
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stmt, 1, job.location.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, job.profession.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, job.job_type);
    sqlite3_bind_int(stmt, 4, job.experience);
    sqlite3_bind_text(stmt, 5, job.name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, job.company_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, job.contact.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 8, job.posting_status ? 1 : 0);
    sqlite3_bind_int(stmt, 9, job.posting_day);
    sqlite3_bind_int(stmt, 10, job.posting_month);
    sqlite3_bind_int(stmt, 11, job.posting_year);
    sqlite3_bind_int(stmt, 12, job.jobID);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // Handle error
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}


////////////////////////////
void updateApplyData(sqlite3* db, const ApplyInfo& apply) {
    // Prepare the SQL statement
    string sql = "UPDATE apply SET "
                 "submissionDay = ?, "
                 "submissionMonth = ?, "
                 "submissionYear = ?, "
                 "submissionStatus = ?, "
                 "job_name = ?, "
                 "company_name = ? "
                 "WHERE applyID = ?";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle error
        return;
    }

    // Bind parameters
    sqlite3_bind_int(stmt, 1, apply.submissionDay);
    sqlite3_bind_int(stmt, 2, apply.submissionMonth);
    sqlite3_bind_int(stmt, 3, apply.submissionYear);
    sqlite3_bind_text(stmt, 4, apply.submissionStatus.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, apply.jobName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, apply.companyName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 7, apply.applyID);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // Handle error
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}


////////////////////////////
void insertCandidateData(sqlite3* db, const CandidateInfo& candidate) {
    // Prepare the SQL statement
    string sql = "INSERT INTO candidate (candidateName, candidateAge, candidateGender, candidatePhoneNumber, "
                 "candidateMail, candidateLivingArea, cadidateExperience, candidateSpecialty, candidatePassword, "
                 "candidateFreeText, resumePath) "
                 "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        // Handle error
        return;
    }

    // Bind parameters
    sqlite3_bind_text(stmt, 1, candidate.candidate_name.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, candidate.candidate_age);
    sqlite3_bind_text(stmt, 3, &candidate.candidate_gender, 1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, candidate.candidate_phone_number.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, candidate.candidate_email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, candidate.candidate_living_area.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 7, candidate.candidate_experience);
    sqlite3_bind_text(stmt, 8, candidate.candidate_specialty.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 9, candidate.password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 10, candidate.candidate_free_text.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 11, candidate.resumePath.c_str(), -1, SQLITE_STATIC);

    // Execute the SQL statement
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        // Handle error
    }

    // Finalize the statement
    sqlite3_finalize(stmt);
}