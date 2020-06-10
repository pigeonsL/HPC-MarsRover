# CMake generated Testfile for 
# Source directory: /Users/dove/HPC/MarsRover/tests
# Build directory: /Users/dove/HPC/MarsRover/cmake-build-debug/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testRover "/Users/dove/HPC/MarsRover/cmake-build-debug/tests/testRover")
set_tests_properties(testRover PROPERTIES  _BACKTRACE_TRIPLES "/Users/dove/HPC/MarsRover/tests/CMakeLists.txt;6;ADD_TEST;/Users/dove/HPC/MarsRover/tests/CMakeLists.txt;0;")
subdirs("googletest")
