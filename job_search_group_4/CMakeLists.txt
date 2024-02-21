cmake_minimum_required(VERSION 3.27)
project(job_search_group_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(job_search_group_4 main.cpp
        sqlite3.c
        sqlite3.h
        User.cpp
        User.h
        Defines.h
        Includes.h
        Employer.cpp
        Employer.h
        Job.cpp
        Job.h
        Candidate.cpp
        Candidate.h
        Apply.cpp
        Apply.h
        Job_search.cpp
        Job_search.h
        Work_with_dataBase.cpp)
