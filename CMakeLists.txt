cmake_minimum_required (VERSION 3.10)

project(rtcbase)
set(C_COMPILE_OPTIONS "-std=c99")
set(CXX_COMPILE_OPTIONS "-std=c++14")
set(CMAKE_EXE_LINKER_FLAGS "-framework AVFoundation -framework CoreMedia -framework Foundation -framework ApplicationServices -framework CoreServices")

include_directories(
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/third_party/include"
)

link_directories(
    "${PROJECT_SOURCE_DIR}/third_party/lib"
)

add_definitions("-g -pipe -W -Wall -fPIC -std=gnu++17 -DWEBRTC_POSIX
    -DWEBRTC_MAC -DNDEBUG -Wno-unused-parameter")

file(GLOB all_src
    "./src/rtc_base/*.cc"
    "./src/rtc_base/strings/*.cc"
    "./src/rtc_base/synchronization/*.cc"
    "./src/rtc_base/deprecated/*.cc"
    "./src/rtc_base/internal/*.cc"
    "./src/rtc_base/task_utils/*.cc"
    "./src/rtc_base/third_party/sigslot/*.cc"
    "./src/rtc_base/third_party/base64/*.cc"
    "./src/api/task_queue/*.cc"
    "./src/api/units/*.cc"
    "./src/api/crypto/*.cc"
    "./src/system_wrappers/source/*.cc"
    # mac
    "./src/rtc_base/system/*.mm"
)

add_library(rtcbase ${all_src})
target_link_libraries(rtcbase libssl.a libcrypto.a)

add_subdirectory(third_party/googletest EXCLUDE_FROM_ALL)

set(
	SOURCE_FILES
    test/rtc_base_test.cc    
)

set(rtc_base_test "")
enable_testing()
add_executable(rtc_base_test ${SOURCE_FILES})
target_compile_features(rtc_base_test PRIVATE cxx_std_14)
set(TEST_INCLUDES ${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include)
target_include_directories(rtc_base_test PUBLIC TEST_INCLUDES)
target_link_libraries(rtc_base_test "${PROJECT_SOURCE_DIR}/out/librtcbase.a")
target_link_libraries(rtc_base_test gtest gtest_main)