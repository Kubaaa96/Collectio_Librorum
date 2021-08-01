cmake_minimum_required(VERSION 3.19)

project(Collectio_Librorum LANGUAGES CXX VERSION 0.0.1)

include(${CMAKE_SOURCE_DIR}/cmake/gtest.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/qtTest.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

execute_process(
        COMMAND conan install --build=missing --profile=${CMAKE_SOURCE_DIR}/conan/linux-profile --install-folder=${CMAKE_SOURCE_DIR}/conan ${CMAKE_SOURCE_DIR}/conan/conanfile.txt
)

include(${CMAKE_SOURCE_DIR}/conan/conanbuildinfo.cmake)
conan_basic_setup()

add_library(project_warnings INTERFACE)

include(cmake/Cache.cmake)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt${QT_VERSION}::Core Qt${QT_VERSION}::Gui Qt${QT_VERSION}::Widgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    message("NOT RELEASE mode - enable testing")
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
else ()
    message("RELEASE mode - testing disabled")
endif ()
