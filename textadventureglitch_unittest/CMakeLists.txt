cmake_minimum_required(VERSION 3.5)

project(TestCase1 LANGUAGES CXX)

enable_testing()

# WPB
#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
#find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt6Widgets_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX11)

find_package(Threads REQUIRED)

if ($ENV{GOOGLETEST_DIR})
    set(GOOGLETEST_DIR $ENV{GOOGLETEST_DIR})
else ()
    if (NOT "/Volumes/zen-linux/dev/repos_github_others/googletest" STREQUAL "")
        message(WARNING "Using googletest src dir specified at Qt Creator wizard")
    endif ()
    set(GOOGLETEST_DIR "/Volumes/zen-linux/dev/repos_github_others/googletest")
endif ()
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)
elseif (UNIX AND EXISTS /usr/src/gtest)
    set(GTestSrc /usr/src/gtest)
    message(WARNING "Using gtest from system")
    if (EXISTS /usr/src/gmock)
        set(GMockSrc /usr/src/gmock)
    endif ()
else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()

set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
if (NOT ${GMockSrc} STREQUAL "")
    list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
    list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
endif ()

include_directories(${GTestIncludes})

add_executable(TestCase1 main.cpp tst_testcase1.cpp
               ${GTestFiles})
add_test(NAME TestCase1 COMMAND TestCase1)
#target_link_libraries(TestCase1 PRIVATE Threads::Threads)
# WPB
target_link_libraries(TestCase1 PRIVATE Threads::Threads Qt${QT_VERSION_MAJOR}::Widgets)

