cmake_minimum_required(VERSION 3.26)
project(JobExplorer)

set(CMAKE_CXX_STANDARD 17)

add_executable(JobExplorer main.cpp
        WebDevJob.h
        IOInterface.h
        BackendDevJob.h
        FrontendDevJob.h
        FullstackDevJob.h
        Applicant.h
        Company.h
        CustomException.h
        InteractiveMenu.h
)
