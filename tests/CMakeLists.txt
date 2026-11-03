include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(ip_filter_tests test_ip_filter.cpp)

target_link_libraries(ip_filter_tests
    PRIVATE gtest_main
    PRIVATE gtest
)

target_sources(ip_filter_tests PRIVATE ${CMAKE_SOURCE_DIR}/ip_filter.cpp)

include(GoogleTest)
gtest_discover_tests(ip_filter_tests)