# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sergey/Загрузки/clion-2021.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/sergey/Загрузки/clion-2021.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sergey/CLionProjects/BigArithmetic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug

# Include any dependencies generated for this target.
include Tests/CMakeFiles/BA_Tests.dir/depend.make
# Include the progress variables for this target.
include Tests/CMakeFiles/BA_Tests.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/BA_Tests.dir/flags.make

Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o: Tests/CMakeFiles/BA_Tests.dir/flags.make
Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o: ../Tests/BA_Tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o -c /home/sergey/CLionProjects/BigArithmetic/Tests/BA_Tests.cpp

Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BA_Tests.dir/BA_Tests.cpp.i"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/BigArithmetic/Tests/BA_Tests.cpp > CMakeFiles/BA_Tests.dir/BA_Tests.cpp.i

Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BA_Tests.dir/BA_Tests.cpp.s"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/BigArithmetic/Tests/BA_Tests.cpp -o CMakeFiles/BA_Tests.dir/BA_Tests.cpp.s

Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.o: Tests/CMakeFiles/BA_Tests.dir/flags.make
Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.o: ../BA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.o"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BA_Tests.dir/__/BA.cpp.o -c /home/sergey/CLionProjects/BigArithmetic/BA.cpp

Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BA_Tests.dir/__/BA.cpp.i"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/BigArithmetic/BA.cpp > CMakeFiles/BA_Tests.dir/__/BA.cpp.i

Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BA_Tests.dir/__/BA.cpp.s"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/BigArithmetic/BA.cpp -o CMakeFiles/BA_Tests.dir/__/BA.cpp.s

# Object files for target BA_Tests
BA_Tests_OBJECTS = \
"CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o" \
"CMakeFiles/BA_Tests.dir/__/BA.cpp.o"

# External object files for target BA_Tests
BA_Tests_EXTERNAL_OBJECTS =

Tests/BA_Tests: Tests/CMakeFiles/BA_Tests.dir/BA_Tests.cpp.o
Tests/BA_Tests: Tests/CMakeFiles/BA_Tests.dir/__/BA.cpp.o
Tests/BA_Tests: Tests/CMakeFiles/BA_Tests.dir/build.make
Tests/BA_Tests: /usr/lib/x86_64-linux-gnu/libgtest_main.a
Tests/BA_Tests: /usr/lib/x86_64-linux-gnu/libgtest.a
Tests/BA_Tests: Tests/CMakeFiles/BA_Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BA_Tests"
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BA_Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/BA_Tests.dir/build: Tests/BA_Tests
.PHONY : Tests/CMakeFiles/BA_Tests.dir/build

Tests/CMakeFiles/BA_Tests.dir/clean:
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests && $(CMAKE_COMMAND) -P CMakeFiles/BA_Tests.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/BA_Tests.dir/clean

Tests/CMakeFiles/BA_Tests.dir/depend:
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/BigArithmetic /home/sergey/CLionProjects/BigArithmetic/Tests /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/Tests/CMakeFiles/BA_Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/BA_Tests.dir/depend

