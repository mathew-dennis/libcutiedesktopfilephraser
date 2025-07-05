cmake_minimum_required(VERSION 3.16)
project(cutiedesktopfileparser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include necessary modules
include(GNUInstallDirs)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)
qt_standard_project_setup()

# Source files for the library and plugin
set(lib_SOURCES
    src/cutiedesktopfileparser.h
    src/cutiedesktopfileparser.cpp)

set(plugin_SOURCES
    src/plugin.cpp src/plugin.h)

# Create the library
qt6_add_library(cutiedesktopfileparser
    SHARED ${lib_SOURCES}
)

# Create the QML module
qt6_add_qml_module(qmlcutiedesktopfileparserplugin
    URI Cutie.Desktopfileparser
    VERSION ${PROJECT_VERSION}
    PLUGIN_TARGET qmlcutiedesktopfileparserplugin
    NO_GENERATE_PLUGIN_SOURCE
    SOURCES
        ${plugin_SOURCES}
        OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/Cutie/Desktopfileparser
)

# Set target properties
set_target_properties(cutiedesktopfileparser PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    PUBLIC_HEADER src/cutiedesktopfileparser.h
)

# Link libraries
target_link_libraries(cutiedesktopfileparser PUBLIC
    Qt::Core
    Qt::Quick
)

target_link_libraries(qmlcutiedesktopfileparserplugin PUBLIC
    Qt::Core
    Qt::Quick
    cutiedesktopfileparser
)

# Configure the pkg-config file
configure_file(src/cutiedesktopfileparser.pc.in cutiedesktopfileparser.pc @ONLY)

# Installation instructions
install(TARGETS cutiedesktopfileparser
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(FILES ${CMAKE_BINARY_DIR}/cutiedesktopfileparser.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS qmlcutiedesktopfileparserplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfileparser"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfileparser"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfileparser"
)

install(DIRECTORY src/qml/Cutie/Desktopfileparser DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie")