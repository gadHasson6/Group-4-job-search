cmake_minimum_required(VERSION 3.26)
project(Group_4_job_search)

set(CMAKE_CXX_STANDARD 14)

include_directories(Group_4_job_search_pro)

add_executable(Group_4_job_search
        Group_4_job_search_pro/Apply.cpp
        Group_4_job_search_pro/Apply.h
        Group_4_job_search_pro/Candidate.cpp
        Group_4_job_search_pro/Candidate.h
        Group_4_job_search_pro/Employer.cpp
        Group_4_job_search_pro/Employer.h
        Group_4_job_search_pro/Job.cpp
        Group_4_job_search_pro/Job.h
        Group_4_job_search_pro/main.cpp
        Group_4_job_search_pro/sqlite3.c
        Group_4_job_search_pro/sqlite3.h
        Group_4_job_search_pro/User.cpp
        Group_4_job_search_pro/User.h
        Group_4_job_search_pro/Work_with_data_base.cpp
        Group_4_job_search_pro/Work_with_data_base.h
        Group_4_job_search_pro/Job_search_system.h
        Group_4_job_search_pro/Job_search_system.cpp)
