cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME Structures)
set(EXECUTABLE ${PROJECT_NAME}_exec)
project(${PROJECT_NAME})

# Provide needed libraries
add_library(linkedListLib include/linked_list.hpp)
set_target_properties(linkedListLib PROPERTIES LINKER_LANGUAGE CXX)

add_library(doubleLinkedListLib include/double_linked_list.hpp)
set_target_properties(doubleLinkedListLib PROPERTIES LINKER_LANGUAGE CXX)

add_library(queueLib include/queue.hpp)
set_target_properties(queueLib PROPERTIES LINKER_LANGUAGE CXX)

set(LIBS
    linkedListLib
    doubleLinkedListLib
    queueLib
)

# Create an executable
add_executable(${EXECUTABLE} main.cpp)
set_property(TARGET ${EXECUTABLE} PROPERTY CXX_STANDARD 20)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TESTS
    test/test_linked_list.cpp
    test/test_double_linked_list.cpp
    test/test_queue.cpp
)

add_executable(Google_Tests_run ${TESTS})

# Add subdirectory where googletest is stored
add_subdirectory(googletest)
target_link_libraries(Google_Tests_run gtest gmock gtest_main)

# Link libraries for my executable
target_link_libraries(${EXECUTABLE} PRIVATE ${LIBS})