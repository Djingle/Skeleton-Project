project(skeleton
        VERSION 1.0
        DESCRIPTION "Skeleton Project"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} ${LINK_EXTERNAL_LIBRARIES})
target_sources(${PROJECT_NAME}
               PRIVATE
               Skeletizator.h
               Skeletizator.cpp
               SkeletonViewer.h
               SkeletonViewer.cpp
               SkeletonTester.h
               SkeletonTester.cpp
               main.cpp  
               )
