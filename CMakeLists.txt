cmake_minimum_required(VERSION 3.1.0)

project(DetectMarked VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
  #add_definitions("/D_CRT_SECURE_NO_WARNINGS /wd4996 /wd4463 /wd4505 /wd4819 -DNOMINMAX")
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif(WIN32)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

#set(Qt5_DIR D:/Qt/Qt5.12.3/5.12.3/msvc2017/lib/cmake/Qt5)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
if(Qt5_FOUND)
        message(STATUS "Found Qt5.")
else(Qt5_FOUND)
        message(FATAL_ERROR "Not Found Qt5.")
endif()

# find DCMTK library
find_package(DCMTK)
if (DCMTK_FOUND)
    message(STATUS "Found DCMTK: " ${DCMTK_INCLUDE_DIR})
    include_directories(${DCMTK_INCLUDE_DIR})
else (MD_FOUND)
    message("DCMTK not found. Please set DCMTK_DIR")
    set(DCMTK_DIR D:/dcmtk/build)
    include_directories(${DCMTK_INCLUDE_DIR})
endif()

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
    message(STATUS "OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

#subdirectory
add_subdirectory(Widgets)
add_subdirectory(MainWindow)
