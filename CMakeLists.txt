cmake_minimum_required(VERSION 3.10)

project(VisualBeautifUI_2026_kwzDev VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
pkg_check_modules(GLIBMM REQUIRED glibmm-2.68)
pkg_check_modules(CAIROMM REQUIRED cairomm-1.16)
pkg_check_modules(SIGC++ REQUIRED sigc++-3.0)
pkg_check_modules(PANGOMM REQUIRED pangomm-2.48)

add_executable(${PROJECT_NAME}
    test/main.cpp
    ../src/ApplicationController/Application.h
    ../src/LayoutComponentController/LayoutBlockComponentController.h
    ../src/LayoutComponentController/LayoutFlexComponentController.h
    ../src/ButtonComponentController/Button.h
    ../src/TextComponent/ReactiveText.h
    ../src/TextComponent/HtmlText.h
    ../src/TextComponent/Text.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "VisualBeautifUI"
    VERSION ${PROJECT_VERSION}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
    ${GTKMM_INCLUDE_DIRS}
    ${GLIBMM_INCLUDE_DIRS}
    ${CAIROMM_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${GTKMM_LIBRARIES}
    ${GLIBMM_LIBRARIES}
    ${CAIROMM_LIBRARIES}
    ${SIGC++_LIBRARIES}
    ${PANGOMM_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    ${GTKMM_CFLAGS_OTHER}
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g -O0 -DDEBUG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _DEBUG)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O3 -DNDEBUG)
endif()

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    file(GLOB_RECURSE UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/*.ui)
    file(GLOB_RECURSE GLADE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/*.glade)
    file(GLOB_RECURSE RESOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/*.gresource.xml)
    
    if(RESOURCE_FILES)
        find_program(GLIB_COMPILE_RESOURCES glib-compile-resources)
        if(GLIB_COMPILE_RESOURCES)
            add_custom_command(
                OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/resources.c
                COMMAND ${GLIB_COMPILE_RESOURCES}
                    --target=${CMAKE_CURRENT_BINARY_DIR}/resources.c
                    --generate-source
                    ${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.gresource.xml
                DEPENDS ${RESOURCE_FILES}
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources
            )
            target_sources(${PROJECT_NAME} PRIVATE
                ${CMAKE_CURRENT_BINARY_DIR}/resources.c
            )
        endif()
    endif()
endif()

option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    
    find_package(GTest QUIET)
    if(GTest_FOUND)
        add_executable(${PROJECT_NAME}_test
            test/test_main.cpp
        )
        target_link_libraries(${PROJECT_NAME}_test PRIVATE
            ${PROJECT_NAME}
            GTest::gtest
            GTest::gtest_main
        )
        add_test(NAME ${PROJECT_NAME}_Test COMMAND ${PROJECT_NAME}_test)
    endif()
endif()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION Applications
)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    install(DIRECTORY resources/
        DESTINATION share/${PROJECT_NAME}/resources
        FILES_MATCHING PATTERN "*.ui" PATTERN "*.glade" PATTERN "*.png" PATTERN "*.svg"
    )
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)

message(STATUS "=========================================")
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "GTKmm Version: ${GTKMM_VERSION}")
message(STATUS "Binary Output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "=========================================")