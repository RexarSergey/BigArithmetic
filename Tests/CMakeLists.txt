find_package(GTest REQUIRED)

add_executable(BA_Tests BA_Tests.cpp ../BA.h ../BA.cpp)

target_link_libraries(BA_Tests GTest::GTest GTest::Main)

add_test(
        NAME BA_Tests
        COMMAND $<TARGET_FILE:${BA_Tests}> --gtest_output=xml:${CMAKE_BINARY_DIR}/test_results/BA_Tests.xml
)