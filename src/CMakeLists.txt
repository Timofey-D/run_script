cmake_minimum_required(VERSION 3.10)

project(run_script VERSION 1.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    runcpp
    main.cpp
    input.cpp
    preProcessor.cpp
    compilation.cpp
    postProcessor.cpp
    utility.cpp
    main.h
    input.h
    preProcessor.h
    compilation.h
    postProcessor.h
    utility.h
    )

