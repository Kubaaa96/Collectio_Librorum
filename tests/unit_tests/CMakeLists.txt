set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -w -O0 -g3 -no-pie")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS_DEBUG} -w -O0 -g3 -no-pie")

package_add_test(ExampleUnitTest
        ExampleGTest.cpp)

add_qtest(ExampleQtTest
        ExampleQtTest.cpp)
