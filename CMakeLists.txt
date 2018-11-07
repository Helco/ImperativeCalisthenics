cmake_minimum_required (VERSION 3.9.2)
project(imperative_calisthenics)

###################################################################
# Dependencies
###################################################################

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    link_libraries(m)
endif()

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

set(sources_imperative_calisthenics
    src/main.cpp
)

add_executable(imperative_calisthenics
    ${sources_imperative_calisthenics}
)

