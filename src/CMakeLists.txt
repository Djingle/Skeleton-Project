project(skeleton
        VERSION 1.0
        DESCRIPTION "skeleton project test build"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} ${LINK_EXTERNAL_LIBRARIES})
target_sources(${PROJECT_NAME}
               PRIVATE
               tp4_ex1_tools.cpp
               CustomSurfaceMeshGL.h
               CustomSurfaceMeshGL.cpp
               cli_tools.h
               cli_tools.cpp
               tp4_ex1_tools.h
               tp4_ex1.cpp  
               )