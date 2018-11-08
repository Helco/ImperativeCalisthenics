cmake_minimum_required (VERSION 3.9.2 FATAL_ERROR)

###################################################################
# Dependencies
###################################################################

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_library(imperative_lib STATIC
    src/Bombs.cpp
    src/Cells.cpp
    src/Board.cpp
    src/BoardGenerator.cpp
    src/BoardReveal.cpp
)
add_executable(imperative_calisthenics src/main.cpp)
target_link_libraries(imperative_calisthenics PRIVATE imperative_lib)

###################################################################
# Utilities
###################################################################

# To preserve file hierarchy in Visual Studio
function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)

###################################################################
# imperative_calisthenics
###################################################################

add_executable(imperative_tests "")

target_compile_features(imperative_tests PUBLIC cxx_std_17)
target_include_directories(imperative_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} third_party src)
target_link_libraries(imperative_tests imperative_lib)
target_sources(imperative_tests PRIVATE "test/main.cpp")

