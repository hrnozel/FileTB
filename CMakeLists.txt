cmake_minimum_required(VERSION 3.16)

project(filetb VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appfiletb
    src/main.cpp
)

qt_add_qml_module(appfiletb
    URI filetb
    QML_FILES
        src/Main.qml
        SOURCES src/filelistmodel.h src/filelistmodel.cpp
)

target_link_libraries(appfiletb
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appfiletb
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
