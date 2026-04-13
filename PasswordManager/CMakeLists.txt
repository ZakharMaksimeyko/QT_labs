cmake_minimum_required(VERSION 3.19)
project(PasswordManager LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets Sql)

qt_standard_project_setup()

qt_add_executable(PasswordManager
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    databasemanager.h databasemanager.cpp
    passwordrecord.h
    repository.h repository.cpp
)

target_link_libraries(PasswordManager
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS PasswordManager
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PasswordManager
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
