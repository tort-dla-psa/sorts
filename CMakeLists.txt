cmake_minimum_required(VERSION 3.0.0)
project(sorts VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(sorts tests)
add_executable(sorts main.cpp)

set(CURSES_NEED_NCURSES TRUE)
target_compile_options(sorts PRIVATE -DSORT_VIZ)
find_package(Curses REQUIRED)
target_link_libraries(sorts ${CURSES_LIBRARIES})

add_executable(test_bubble tests/bubble.cpp)
add_test(test_bubble test_bubble)

add_executable(test_cocktail tests/cocktail.cpp)
add_test(test_cocktail test_cocktail)

add_executable(test_comb tests/comb.cpp)
add_test(test_comb test_comb)

add_executable(test_gnome tests/gnome.cpp)
add_test(test_gnome test_gnome)

add_executable(test_odd_even tests/odd_even.cpp)
add_test(test_odd_even test_odd_even)

add_executable(test_quick tests/quick.cpp)
add_test(test_quick test_quick)

add_executable(test_selection tests/selection.cpp)
add_test(test_selection test_selection)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
