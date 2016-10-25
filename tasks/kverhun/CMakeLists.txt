cmake_minimum_required(VERSION 2.8.9)

project(catch_builder CXX)
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
   )

# Expose required variable (CATCH_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR ${source_dir}/include CACHE INTERNAL "./catch")

project(Algorithms)
# Includes Catch in the project:

add_executable(Words 02-Words/impl/main.cpp)
add_executable(TextJustification 03-TextJustification/impl/main.cpp)

####################################################
# Longest Common Subsequence
####################################################
set(LCS_SOURCE_DIR 04-LCS/impl)
add_library(LCS SHARED ${LCS_SOURCE_DIR}/lcs.cpp ${LCS_SOURCE_DIR}/_Library.h ${LCS_SOURCE_DIR}/lcs.h)
target_compile_definitions(LCS PRIVATE LCS_LIBRARY)

add_executable(LCS_Tests 04-LCS/unit_tests/lcs_test.cpp)
target_link_libraries(LCS_Tests PUBLIC LCS)
add_dependencies(LCS_Tests catch)
####################################################

####################################################
# Words Alignment
####################################################
set(WordsAlignment_SOURCE_DIR 05-WordsAlignment/impl)
set(WordsAlignment_TEST_DIR 05-WordsAlignment/unit_tests)

add_library(WordsAlignment SHARED 
    ${WordsAlignment_SOURCE_DIR}/_Library.h
    ${WordsAlignment_SOURCE_DIR}/WordsAlignment.h
    ${WordsAlignment_SOURCE_DIR}/WordsAlignment.cpp)
target_compile_definitions(WordsAlignment PRIVATE WORDS_ALIGNMENT_LIBRARY)

add_executable(WordsAlignment_Tests ${WordsAlignment_TEST_DIR}/words_alignment_tests.cpp)
target_link_libraries(WordsAlignment_Tests PUBLIC WordsAlignment)
add_dependencies(WordsAlignment_Tests catch)
####################################################

####################################################
# Binary heap
####################################################
set(BinaryHeap_SOURCE_DIR 06-BinaryHeap/impl)
set(BinaryHeap_TEST_DIR 06-BinaryHeap/unit_tests)

add_library(BinaryHeap SHARED
    ${BinaryHeap_SOURCE_DIR}/_Library.h
    ${BinaryHeap_SOURCE_DIR}/BinaryHeap.h
    ${BinaryHeap_SOURCE_DIR}/BinaryHeap.cpp)
target_compile_definitions(BinaryHeap PRIVATE BINARY_HEAP_LIBRARY)

add_executable(BinaryHeap_Tests ${BinaryHeap_TEST_DIR}/binary_heap_tests.cpp)
target_link_libraries(BinaryHeap_Tests PUBLIC BinaryHeap)
add_dependencies(BinaryHeap_Tests catch)
####################################################

####################################################
# Graphs
####################################################
set(Graphs_SOURCE_DIR 07-Graphs/impl)
set(Graphs_TEST_DIR 07-Graphs/unit_tests)

add_library(Graphs SHARED
    ${Graphs_SOURCE_DIR}/_Library.h		
    ${Graphs_SOURCE_DIR}/Graph.h
    ${Graphs_SOURCE_DIR}/Graph.cpp
    ${Graphs_SOURCE_DIR}/GraphAlgorithms.h
    ${Graphs_SOURCE_DIR}/GraphAlgorithms.cpp
)
target_compile_definitions(Graphs PRIVATE GRAPHS_LIBRARY)

add_executable(Graphs_Tests ${Graphs_TEST_DIR}/graphs_tests.cpp)
target_link_libraries(Graphs_Tests PUBLIC Graphs)
add_dependencies(Graphs_Tests Graphs)
####################################################

include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)  # Enables unit-testing.