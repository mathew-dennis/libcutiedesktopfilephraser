cmake_minimum_required(VERSION 3.16)
project(cutiedesktopfilephraser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include necessary modules
include(GNUInstallDirs)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)
qt_standard_project_setup()

# Source files for the library and plugin
set(lib_SOURCES
    src/cutiedesktopfilephraser.h
    src/cutiedesktopfilephraser.cpp)

set(plugin_SOURCES
    src/plugin.cpp src/plugin.h)

# Create the library
qt6_add_library(cutiedesktopfilephraser
    SHARED ${lib_SOURCES}
)

# Create the QML module
qt6_add_qml_module(qmlcutiedesktopfilephraserplugin
    URI Cutie.Desktopfilephraser
    VERSION ${PROJECT_VERSION}
    PLUGIN_TARGET qmlcutiedesktopfilephraserplugin
    NO_GENERATE_PLUGIN_SOURCE
    SOURCES
        ${plugin_SOURCES}
        OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/Cutie/Desktopfilephraser
)

# Set target properties
set_target_properties(cutiedesktopfilephraser PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    PUBLIC_HEADER src/cutiedesktopfilephraser.h
)

# Link libraries
target_link_libraries(cutiedesktopfilephraser PUBLIC
    Qt::Core
    Qt::Quick
)

target_link_libraries(qmlcutiedesktopfilephraserplugin PUBLIC
    Qt::Core
    Qt::Quick
    cutiedesktopfilephraser
)

# Configure the pkg-config file
configure_file(src/cutiedesktopfilephraser.pc.in cutiedesktopfilephraser.pc @ONLY)

# Installation instructions
install(TARGETS cutiedesktopfilephraser
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(FILES ${CMAKE_BINARY_DIR}/cutiedesktopfilephraser.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS qmlcutiedesktopfilephraserplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfilephraser"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfilephraser"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Desktopfilephraser"
)

install(DIRECTORY src/qml/Cutie/Desktopfilephraser DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie")