cmake_minimum_required(VERSION 3.0.0)
project(sorts VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(sorts sorts_vis)
add_executable(sorts main.cpp)
add_executable(sorts_vis main_vis.cpp)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
target_link_libraries(sorts_vis ${CURSES_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
