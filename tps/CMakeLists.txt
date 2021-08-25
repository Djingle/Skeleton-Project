# Add include directories of the project
include_directories("include/")

# Add all the cpp sources of the src directory
file(GLOB TP_TOOLS_SRC "src/*.cpp")

# List all the cpp files in the app folder
file(GLOB TP_MAIN_SRC "apps/*.cpp")

# Loop through all cpp files in the app directory
# In order to create an executable for each of them
foreach(CURR_MAIN_SRC ${TP_MAIN_SRC})
    # Get the current file name (no extension, no directory)
    set(CURR_MAIN_SRC_PATH ${CURR_MAIN_SRC})
    get_filename_component(EXECUTABLE_NAME ${CURR_MAIN_SRC_PATH} NAME_WLE)

    # Use it as the name of the generated executable
    # The executable requires the current main cpp file (CURR_MAIN_SRC) and the tool files (TP_TOOL_SRC)
    add_executable(${EXECUTABLE_NAME} ${TP_TOOLS_SRC} ${CURR_MAIN_SRC})

    # Links the executable with the required libraries
    target_link_libraries(${EXECUTABLE_NAME} ${LINK_EXTERNAL_LIBRARIES})
endforeach()