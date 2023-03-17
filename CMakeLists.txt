cmake_minimum_required(VERSION 3.24)
project(Linus-PE-2022 C)

set(CMAKE_C_STANDARD 11)

add_executable(main main.c graphics_handler.c graphics_handler.h file_handler.c file_handler.h)

enable_testing()
add_executable(test_application testing.c graphics_handler.c graphics_handler.h)
target_link_libraries(test_application)
add_test(NAME test_application COMMAND test_application)

