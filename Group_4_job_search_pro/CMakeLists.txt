cmake_minimum_required(VERSION 3.27)
project(Group_4_job_search_pro)

set(CMAKE_CXX_STANDARD 17)

add_executable(Group_4_job_search_pro main.cpp
        sqlite3.c
        sqlite3.h
        Apply.cpp
        Apply.h
        Job.cpp
        Job.h
        User.cpp
        User.h
        Employer.cpp
        Employer.h
        Candidate.cpp
        Candidate.h
        Work_with_data_base.h
        Work_with_data_base.cpp
        Job_search_system.h
        Job_search_system.cpp
)
