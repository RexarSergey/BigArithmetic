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
include CMakeFiles/BigArithmetic.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BigArithmetic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigArithmetic.dir/flags.make

CMakeFiles/BigArithmetic.dir/main.cpp.o: CMakeFiles/BigArithmetic.dir/flags.make
CMakeFiles/BigArithmetic.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigArithmetic.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigArithmetic.dir/main.cpp.o -c /home/sergey/CLionProjects/BigArithmetic/main.cpp

CMakeFiles/BigArithmetic.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigArithmetic.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/BigArithmetic/main.cpp > CMakeFiles/BigArithmetic.dir/main.cpp.i

CMakeFiles/BigArithmetic.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigArithmetic.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/BigArithmetic/main.cpp -o CMakeFiles/BigArithmetic.dir/main.cpp.s

CMakeFiles/BigArithmetic.dir/BA.cpp.o: CMakeFiles/BigArithmetic.dir/flags.make
CMakeFiles/BigArithmetic.dir/BA.cpp.o: ../BA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BigArithmetic.dir/BA.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BigArithmetic.dir/BA.cpp.o -c /home/sergey/CLionProjects/BigArithmetic/BA.cpp

CMakeFiles/BigArithmetic.dir/BA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigArithmetic.dir/BA.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sergey/CLionProjects/BigArithmetic/BA.cpp > CMakeFiles/BigArithmetic.dir/BA.cpp.i

CMakeFiles/BigArithmetic.dir/BA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigArithmetic.dir/BA.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sergey/CLionProjects/BigArithmetic/BA.cpp -o CMakeFiles/BigArithmetic.dir/BA.cpp.s

# Object files for target BigArithmetic
BigArithmetic_OBJECTS = \
"CMakeFiles/BigArithmetic.dir/main.cpp.o" \
"CMakeFiles/BigArithmetic.dir/BA.cpp.o"

# External object files for target BigArithmetic
BigArithmetic_EXTERNAL_OBJECTS =

BigArithmetic: CMakeFiles/BigArithmetic.dir/main.cpp.o
BigArithmetic: CMakeFiles/BigArithmetic.dir/BA.cpp.o
BigArithmetic: CMakeFiles/BigArithmetic.dir/build.make
BigArithmetic: CMakeFiles/BigArithmetic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BigArithmetic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigArithmetic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigArithmetic.dir/build: BigArithmetic
.PHONY : CMakeFiles/BigArithmetic.dir/build

CMakeFiles/BigArithmetic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigArithmetic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigArithmetic.dir/clean

CMakeFiles/BigArithmetic.dir/depend:
	cd /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sergey/CLionProjects/BigArithmetic /home/sergey/CLionProjects/BigArithmetic /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug /home/sergey/CLionProjects/BigArithmetic/cmake-build-debug/CMakeFiles/BigArithmetic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigArithmetic.dir/depend

