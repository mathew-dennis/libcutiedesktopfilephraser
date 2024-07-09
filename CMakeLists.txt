cmake_minimum_required(VERSION 3.16)
project(cutiephonenumber VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)
qt_standard_project_setup()

set(lib_SOURCES
    src/cutiephonenumber.h
    src/cutiephonenumber.cpp)

set(plugin_SOURCES
    src/plugin.cpp src/plugin.h)

qt6_add_library(cutiephonenumber
    SHARED ${lib_SOURCES}
)

qt6_add_qml_module(qmlcutiephonenumberplugin
    URI Cutie.Phonenumber
    VERSION ${PROJECT_VERSION}
    PLUGIN_TARGET qmlcutiephonenumberplugin
    NO_GENERATE_PLUGIN_SOURCE
    SOURCES
        ${plugin_SOURCES}
)

set_target_properties(cutiephonenumber PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(cutiephonenumber PROPERTIES SOVERSION 0)
set_target_properties(cutiephonenumber PROPERTIES PUBLIC_HEADER src/cutiephonenumber.h)

target_link_libraries(cutiephonenumber PUBLIC
    Qt::Core
    Qt::Quick
    -lphonenumber
)

target_link_libraries(qmlcutiephonenumberplugin PUBLIC
    Qt::Core
    Qt::Quick
    cutiephonenumber
)

configure_file(src/cutiephonenumber.pc.in cutiephonenumber.pc @ONLY)

install(TARGETS cutiephonenumber
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

install(FILES ${CMAKE_BINARY_DIR}/cutiephonenumber.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

install(TARGETS qmlcutiephonenumberplugin
    RUNTIME DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Phonenumber"
    BUNDLE DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Phonenumber"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie/Phonenumber"
)

install(DIRECTORY src/qml/Cutie/Phonenumber DESTINATION "${CMAKE_INSTALL_LIBDIR}/qt6/qml/Cutie")
