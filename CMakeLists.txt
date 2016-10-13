PROJECT( arecv )
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)

INCLUDE_DIRECTORIES(
    include
)

SET( CMAKE_CXX_FLAGS "-g -pedantic-errors -Wall -std=c++11" )

SET( SOURCE_PATH src )

SET( CPP

    ${SOURCE_PATH}/main.cpp
    ${SOURCE_PATH}/data/api.cpp

#    ${SOURCE_PATH}/skel/app_stand_alone.cpp
#    ${SOURCE_PATH}/ar/assets_receiver.cpp
#    ${SOURCE_PATH}/term-ui/inceptor.cpp
#    ${SOURCE_PATH}/commons-ui/popup_windows.cpp
#    ${SOURCE_PATH}/tcp/http_client.cpp
#    ${SOURCE_PATH}/util/str_ascii_helper.cpp
#    ${SOURCE_PATH}/util/csv_ascii_helper.cpp
#    ${SOURCE_PATH}/util/file_helper.cpp
)

ADD_SUBDIRECTORY(dsrest)

ADD_EXECUTABLE (
    ${PROJECT_NAME}
    ${HPP}
    ${CPP}
)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME}
    dl
    dsrest
    log4cxx
    ncurses
    panel
    menu
    form
)

INSTALL(FILES ${PROJECT_NAME} DESTINATION bin)
