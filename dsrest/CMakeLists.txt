CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)
PROJECT (dsrest)
 
SET (
    PROJECT_INCLUDE_DIR

    ${PROJECT_SOURCE_DIR}/include
)
SET (
    PROJECT_SOURCE_DIR

    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
 
SET (
    CPP 
    ${PROJECT_SOURCE_DIR}/ds.cpp
    ${PROJECT_SOURCE_DIR}/client.cpp
)
 
INCLUDE_DIRECTORIES (
    "${PROJECT_INCLUDE_DIR}"
)

SET( CMAKE_CXX_FLAGS "-g -pedantic-errors -Wall -std=c++11" )
 
ADD_LIBRARY(${PROJECT_NAME} SHARED ${CPP})

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME}
    jsoncpp
    curl
)

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION lib)
