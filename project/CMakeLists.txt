cmake_minimum_required (VERSION 3.16)

project(project)

add_library(project KdV.c KdV_1.c KdV_2.c KdV_3.c)

link_libraries(project)

include(CTest)

add_executable(KdV KdV.c)
target_link_libraries(KdV PRIVATE m)

add_executable(KdV_1 KdV_1.c)
target_link_libraries(KdV_1 PRIVATE m)

add_executable(KdV_2 KdV_2.c)
target_link_libraries(KdV_2 PRIVATE m)

add_executable(KdV_3 KdV_3.c)
target_link_libraries(KdV_3 PRIVATE m)
