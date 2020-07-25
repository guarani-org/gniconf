# CMakeList.txt : CMake project for gniconf, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (gniconf STATIC "src/gniconf.cpp" "include/gniconf.h" "include/accel.h" "test/gniconf_test.h" "src/accel.cpp" "src/gyro.cpp"  "src/mag.cpp" "include/recorder.h" "src/recorder.cpp" "include/syscfg.h" "src/syscfg.cpp" "include/gps.h" "src/gps.cpp")
target_include_directories(gniconf PRIVATE "include" "../pugixml/src")
set_target_properties(gniconf   PROPERTIES
                                CXX_STANDARD 17
                                CXX_STANDARD_REQUIRED YES
                                CXX_EXTENSIONS NO)

add_executable(gniconf_test  "test/gniconf_test.cpp" "test/gniconf_test.h")
target_include_directories(gniconf_test PRIVATE "test" "include" "../pugixml/src")
set_target_properties(gniconf_test  PROPERTIES
                                    CXX_STANDARD 17
                                    CXX_STANDARD_REQUIRED YES
                                    CXX_EXTENSIONS NO)
target_link_libraries(gniconf_test PRIVATE gniconf pugixml)

# TODO: Add tests and install targets if needed.
add_test("gnit_test" gniconf_test)

