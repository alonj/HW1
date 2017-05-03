cmake_minimum_required(VERSION 3.7)
project(codeHW1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        Cluster.cpp
        Cluster.h
        Kmeans.cpp
        Kmeans.h
        KMedoids.cpp
        KMedoids.h
        Point.cpp
        Point.h
        main.cpp
        SeedsGenerator.cpp
        SeedsGenerator.h
        Tests.cpp
        Tests.h cmake-build-debug/ Point.cpp)

add_executable(codeHW1 ${SOURCE_FILES})