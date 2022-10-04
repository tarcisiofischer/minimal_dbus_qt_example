cmake_minimum_required(VERSION 3.18)

project(minimal_dbus_qt_example CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5 REQUIRED COMPONENTS Core DBus)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(myproject_DBUS_XML myproject.MyProject.xml)
set(myproject_SRC myproject_dbus.cpp)
qt5_wrap_cpp(myproject_SRC myproject_dbus.h)

qt5_generate_dbus_interface(
    myproject_dbus.h
    ${myproject_DBUS_XML}
    # Options:
    # -p|-s|-m       Only parse scriptable Properties, Signals and Methods (slots)
    # -P|-S|-M       Parse all Properties, Signals and Methods (slots)
    #
    OPTIONS -p -s -m
)

qt5_add_dbus_adaptor(myproject_DBUS_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/${myproject_DBUS_XML}
    myproject_dbus.h
    MyProjectDBus
)

add_executable(myproject
    main.cpp
    ${myproject_SRC}
    ${myproject_DBUS_SRC}
)

target_link_libraries(myproject
    Qt5::Core
    Qt5::DBus
)
