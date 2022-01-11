# Add include directories of the project
message(STATUS "Here ${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

# Add all the cpp sources of the src directory
file(GLOB TP_TOOLS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(CLI_TOOLS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/cli_tools.cpp")

# List all the cpp files in the app folder
file(GLOB TP_MAIN_SRC "${CMAKE_CURRENT_SOURCE_DIR}/apps/*.cpp")

# Loop through all cpp files in the app directory
# In order to create an executable for each of them
foreach(CURR_MAIN_SRC ${TP_MAIN_SRC})
    # Get the current file name (no extension, no directory)
    set(CURR_MAIN_SRC_PATH ${CURR_MAIN_SRC})
    get_filename_component(EXECUTABLE_NAME ${CURR_MAIN_SRC_PATH} NAME_WLE)
    
    # construct the list of sources for the current app
    foreach(CURR_TP_TOOLS_SRC ${TP_TOOLS_SRC})
        if(CURR_TP_TOOLS_SRC MATCHES ${EXECUTABLE_NAME})
            list(APPEND ${EXECUTABLE_NAME}_SOURCE_LIST ${CURR_TP_TOOLS_SRC})
        endif()
    endforeach()

    # Use it as the name of the generated executable
    # The executable requires the current main cpp file (CURR_MAIN_SRC), the cli_tools and the tool files (${${EXECUTABLE_NAME}_SOURCE_LIST})
    add_executable(${EXECUTABLE_NAME} ${CLI_TOOLS_SRC} ${${EXECUTABLE_NAME}_SOURCE_LIST} ${CURR_MAIN_SRC})

    # Links the executable with the required libraries
    target_link_libraries(${EXECUTABLE_NAME} ${LINK_EXTERNAL_LIBRARIES})
endforeach()