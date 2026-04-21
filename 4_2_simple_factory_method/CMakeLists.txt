cmake_minimum_required(VERSION 3.19)
project(4_2_simple_factory_method LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(4_2_simple_factory_method
    WIN32 MACOSX_BUNDLE
    main.cpp


)

target_link_libraries(4_2_simple_factory_method
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS 4_2_simple_factory_method
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 4_2_simple_factory_method
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
