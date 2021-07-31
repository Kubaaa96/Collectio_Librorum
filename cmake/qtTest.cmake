set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Test REQUIRED)

function(add_qtest TARGET_NAME)
    add_executable(${TARGET_NAME} ${ARGN})
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
    target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
    target_link_libraries(${TARGET_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Test)
endfunction()
