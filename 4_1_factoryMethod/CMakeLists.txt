cmake_minimum_required(VERSION 3.19)
project(4_1_factoryMethod LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(4_1_factoryMethod
    main.cpp
)

target_link_libraries(4_1_factoryMethod
    PRIVATE
        Qt::Core
)

install(TARGETS 4_1_factoryMethod
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
