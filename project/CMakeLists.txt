#cmake_minimum_required (VERSION 3.16)

project(project)

add_library(project KdV.c KdV1.c)

link_libraries(project)

#include(cmake/CPM.cmake)

include(CTest)
add_executable(KdV KdV.c)
target_link_libraries(KdV PRIVATE m)

CPMAddPackage(
  NAME GTest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.11.0
  EXCLUDE_FROM_ALL ON
)
include(GoogleTest)

#add_subdirectory(c)
